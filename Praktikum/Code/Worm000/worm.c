// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//

#include <curses.h>        //Compiler bekommt die Funktionen der Curses Bib mit
#include <string.h>        //Verwenden der String Funktion ; Bekannt machen mit der String Bib

// ********************************************************************************************
// Constants, data structures
// ********************************************************************************************

// Result codes of functions
#define RES_OK 0          // Konstanten(Wert ändert sich nicht) für Resultat-Codes der Funktion main(); Code signalisiert 0
#define RES_FAILED 1

// *********************************************
// Standard curses initialization and cleanup
// *********************************************

// Initialize application with respect to curses settings
void initializeCursesApplication() {
    initscr(); // Initialize the curses screen

    // Note:
    // The call to initscr() defines various global variables of the curses framework.
    // stdscr, LINES, COLS, TRUE, FALSE

    noecho();  // Characters typed are not echoed
    cbreak();  // No buffering of stdin
    nonl();    // Do not translate 'return key' on keyboard to newline character
    keypad(stdscr, TRUE); // Enable the keypad
    curs_set(0);          // Make cursor invisible
    // Begin in non-single-step mode (getch will not block)
    nodelay(stdscr, TRUE);  // make getch to be a non-blocking call
}

// Reset display to normale state and terminate curses application
void cleanupCursesApp(void)                                                    //durch aufrufe dieser Methode wird CurseAplplication wieder in einen normalen Zustand gebracht
{
    standend();   // Turn off all attributes
    refresh();    // Write changes to terminal
    curs_set(1);  // Set cursor state to normal visibility
    endwin();     // Terminate curses application
}

// ********************************************************************************************
// MAIN
// ********************************************************************************************

int main(void) {
    int res_code;         // Result code from functions
    char* message_template = "Das Fenster hat xxx Zeilen und yyy Spalten";
    int msg_len;
    int min_rows = 3;

    // Here we start
    initializeCursesApplication();      /*@01*/                      // Init various settings of our application

    msg_len = strlen(message_template);  /* @02*/                   // Compute length of our template

    // Maximal LINES and COLS are set by curses for the current window size.
    // Check if the window is large enough to display our message
    if ( LINES < min_rows /* @03 Zeilen*/       || COLS < msg_len /* @03 Spalten*/     ) {
        // Cleanup special curses settings and restore the normal terminal functionality
        cleanupCursesApp(); /*@04*/
        // Print a conventional error message via printf.
        // Note: this only work after the call to  cleanupCursesApp();
        printf("Das Fenster ist zu klein: wir brauchen mindestens %dx%d\n", min_rows /* @05*/,msg_len /* @05*/ );

        // Set the result code to report the error
        res_code = RES_FAILED;
    } else {
        // Center output
        int mid_row = LINES /2;  /*@06 Zeilen durch zwei. da mittig)*/
        int start_col = COLS /2; /*@06 Spalten durch zwei)*/

        // Write letter A to the top    left  corner of our display
        move(0,0); /* @07*/        // Move to position
        addch('A'); /*@07*/       // Put character there

        // Write letter B to the top    right corner of our display
        // Use combination of move() and addch() functions
        mvaddch(0, COLS -1, 'B');  /*@08 -1 weil wir von 0 auszählen */ 
        // Write letter C to the bottom right corner of our display
        mvaddch(LINES -1, COLS -1, 'C'); /*@09*/
        // Write letter D to the bottom left  corner of our display
        mvaddch(LINES -1, 0, 'D'); /* @10*/
 
        // Write our message centered onto the display
        mvprintw(mid_row, start_col,"Das Fenster hat %3d Zeilen und %3d Spalten",LINES /* @11*/,COLS);

        // Refresh the screen in order to show all changes on the screen
        refresh(); /*@12 Änderungen aktualisieren*/
        
        // Wait for user to press a key
        @13                   // make getch to be a blocking call
        getch();

        // Set the result code to report success
        res_code = RES_OK;

        // Cleanup special curses settings and restore the normal terminal functionality
        @14
    }
    return res_code;
}
