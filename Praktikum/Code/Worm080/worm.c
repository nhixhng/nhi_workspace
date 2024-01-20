// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //zugriff auf bib stdbool,elemente true und false
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "options.h"

#include "prep.h"
#include "messages.h"
#include "worm.h"
#include "worm_model.h"
#include "board_model.h" //hier werden alle Vordeklarierten Variabeln oder funktionen eingefugt, reihenfolge egal da sie vor dem aufrufen der Funktionen bereits reingeladen wurden

// Management of the game
void initializeColors();
void readUserInput(struct worm* aworm, enum GameStates* agame_state );
enum ResCodes doLevel(struct game_options* somegops);

// ************************************
// Management of the game
// ************************************

// Initialize colors of the game
void initializeColors() {
    // Define colors of the game
    start_color();
    init_pair(COLP_USER_WORM,    COLOR_GREEN /*@002*/,    COLOR_BLACK); // hinmalen vom Wurm
    init_pair(COLP_FREE_CELL,    COLOR_BLACK,             COLOR_BLACK); // wegradieren vom Wurm
    init_pair(COLP_FOOD_1,       COLOR_YELLOW,             COLOR_BLACK);
    init_pair(COLP_FOOD_2,       COLOR_MAGENTA,             COLOR_BLACK);
    init_pair(COLP_FOOD_3,       COLOR_CYAN,             COLOR_BLACK);
    init_pair(COLP_BARRIER,    COLOR_RED,             COLOR_BLACK);
}

void readUserInput(struct worm *aworm, enum GameStates* agame_state ) {
    int ch; // For storing the key codes

    if ((ch = getch()) > 0) {
        // Is there some user input?
        // Blocking or non-blocking depends of config of getch
        switch(ch) {
            case 'q' :    // User wants to end the show
                *agame_state = WORM_GAME_QUIT;
                break;
            case KEY_UP :// User wants up
                setWormHeading(aworm, WORM_UP);
                break;
            case KEY_DOWN :// User wants down
                setWormHeading(aworm, WORM_DOWN); /*@012*/
                break;
            case KEY_LEFT :// User wants left
                setWormHeading(aworm, WORM_LEFT); /*@012*/
                break;
            case KEY_RIGHT :// User wants right
                setWormHeading(aworm, WORM_RIGHT); /*@012*/
                break;

//            case 'w' : // schräg nach links oben
//              setWormHeading(aworm, WORM_LEFT_UP);
//                break;
//            case 'd' : // schräg nach rechts oben
//                setWormHeading(aworm, WORM_RIGHT_UP);
//                break;
//            case 'a' : // schräg links unten
//                setWormHeading(aworm, WORM_LEFT_DOWN);
//                break;
//            case 'x' : // schräg unten rechts
//                setWormHeading(aworm, WORM_RIGHT_DOWN);
//                break;

            case 'g' :
                growWorm(aworm, BONUS_3);
                break;

            case 's' : // User wants single step
                nodelay(stdscr,FALSE); //@013  We simply make getch blocking
                break;
            case ' ' : // Terminate single step; make getch non-blocking again
                nodelay(stdscr,TRUE); // @013   Make getch non-blocking again
                break;
        }
    }
    return;
}

enum ResCodes doLevel(struct game_options* somegops) {
    struct worm userworm;
    struct board theboard;
    enum GameStates game_state; // The current game_state

    enum ResCodes res_code; // Result code from functions
    bool end_level_loop;    // Indicates whether we should leave the main loop

    struct pos bottomLeft;   // Start positions of the worm

    // At the beginnung of the level, we still have a chance to win
    game_state = WORM_GAME_ONGOING;

    //Set up the board
    res_code = initializeBoard(&theboard);
    if(res_code != RES_OK) {
      return res_code;
    }

    //Initialize the current level
    res_code = initializeLevel(&theboard);
    if(res_code != RES_OK) {
      return res_code;
    }

    // There is always an initialized user worm.
    // Initialize the userworm with its size, position, heading.
    bottomLeft.y=  getLastRowOnBoard(&theboard);
    bottomLeft.x =  0;

    res_code = initializeWorm(&userworm, WORM_LENGTH,WORM_INITIAL_LENGTH, bottomLeft, WORM_RIGHT, COLP_USER_WORM);
    if ( res_code != RES_OK) {
        return res_code;
    }

    // Show worm at its initial position
    showWorm(&theboard, &userworm);

    // Display all what we have set up until now
    refresh();

    // Start the loop for this level
    end_level_loop = false; // Flag for controlling the main loop
                            
    while(!end_level_loop) {        //solange es nicht gleich false ist(also true)
       
      // Process optional user input
        readUserInput(&userworm, &game_state); 
        if ( game_state == WORM_GAME_QUIT ) {
            end_level_loop = true; // @014
            continue; // Go to beginning of the loop's block and check loop condition
        }

        // Process userworm
        // Clean the tail of the worm
        cleanWormTail(&theboard, &userworm);
        // Now move the worm for one step
        moveWorm(&theboard, &userworm, &game_state /*@015*/);
        // Bail out of the loop if something bad happened
        if ( game_state != WORM_GAME_ONGOING ) {
            end_level_loop = true; // @016;
            continue; // Go to beginning of the loop's block and check loop condition
        }

        // Show the worm at its new position
        showWorm(&theboard, &userworm);
        // END process userworm

        //Inform user about position and length of userworm in status window
        showStatus(&theboard, &userworm);

        // Sleep a bit before we show the updated window
        napms(somegops->nap_time);

        // Display all the updates
        refresh();

        if(getNumberOfFoodItems(&theboard) == 0) {
          end_level_loop = true;
        }

        // Start next iteration
    }

    // Preset res_code for rest of the function
    res_code = RES_OK;

    // For some reason we left the control loop of the current level.
    // However, in this version we do not yet check for the reason.
    // There is no user feedback at the moment!

    switch (game_state) {

            case WORM_GAME_ONGOING:
              if(getNumberOfFoodItems(&theboard) == 0) {
                 showDialog("Sie haben diese Runde erfolgreich beendet!!" , 
                     "Bitte Taste Druecken");
              } else {
                showDialog("Interner Fehler!", "Bitte Taste druecken");
                res_code= RES_INTERNAL_ERROR;
              }
              break;
              
            case WORM_GAME_QUIT:
            // User must have typed 'q' for quit
            showDialog("Sie haben die aktuelle Runde abgebrochen!",
            "Bitte Taste druecken");
            break;

            case WORM_CRASH:
            showDialog("Sie haben das Spiel verlore,"
            "weil Sie in die Barriere gefahren sind", 
            "Bitte Taste druecken");
            break;

            case WORM_OUT_OF_BOUNDS:
            showDialog("Sie haben das Spiel verloren,"
            " weil sie das Spielfeld verlassen haben",
            "Bitte Taste druecken");
            break;

            case WORM_CROSSING:
            showDialog ("Sie haben das Spiel verloren,"
            " weil sie einen Wurm gekreuzt haben",
            "Bitte Taste druecken");
            break;

            default:
            showDialog("Internet Fehler!", "Bitte Taste druecken");
            //set error resault code. This should never happen
            res_code = RES_INTERNAL_ERROR;
    }
    cleanupBoard(&theboard);

    // Normal exit point
    return res_code; // @017
}

// ********************************************************************************************
// MAIN
// ********************************************************************************************
enum ResCodes playGame(int argc, char* argv[]){
  enum ResCodes res_codes;
  struct game_options thegops;

  res_codes= readCommandLineOptions(&thegops, argc, argv);
  if( res_codes!= RES_OK){
    return res_codes;
  }
  
  if(thegops.start_single_step){
    nodelay(stdscr,FALSE);
  }

  res_codes= doLevel(&thegops);
  return res_codes;
}

int main(int argc, char* argv[]){ 
    enum ResCodes res_code;         // Result code from functions
    
    //printf("press key to continue\n");
    getchar(); // start pogramm, give debugger a chance to attach, waits for eingabe


    // Here we start
    initializeCursesApplication();  // Init various settings of our application
    initializeColors();             // Init colors used in the game

    // Maximal LINES and COLS are set by curses for the current window size.
    // Note: we do not cope with resizing in this simple examples!

    // Check if the window is large enough to display messages in the message area
    // a has space for at least one line for the worm
    if ( LINES < ROWS_RESERVED + MIN_NUMBER_OF_ROWS || COLS < MIN_NUMBER_OF_COLS ) {
        // Since we not even have the space for displaying messages
        // we print a conventional error message via printf after
        // the call of cleanupCursesApp()
        cleanupCursesApp();
        printf("Das Fenster ist zu klein: wir brauchen mindestens %dx%d\n",
                MIN_NUMBER_OF_COLS, MIN_NUMBER_OF_ROWS );
        res_code = RES_FAILED;
    } else {
        res_code = playGame(argc,argv);
        cleanupCursesApp();
    }

    return res_code; //*@001
}
