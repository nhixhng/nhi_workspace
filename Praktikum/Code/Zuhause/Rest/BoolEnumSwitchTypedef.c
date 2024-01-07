#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum color{
  red=1,
  oran,
  yel,
  green,
  blue,
  purp,
} farben_t;
  
int main(){
  farben_t farbe;

  printf(" Gebe eine Zahl ein um zuschauen ob die Farbe eine Grundfarbe ist oder nicht.\n");
  printf(" Dabei ist rot=1 und dann immer soweiter in der Regenbogen Reihenfolge (Rot, orange, geld, gruen...\n");
  scanf("%d", &farbe);

  switch(farbe){
    case red:
    case yel:
    case blue:
    printf("Du hast eine Grundfarbe ausgewahlt\n");
    break;

    case oran:
    case green:
    case purp:
    printf("Du hast eine Mischbare Farbe ausgewahlt\n");
    break;

    default:
    printf("Diese Farbe ist nicht registriert\n");
    break;
  }

  return EXIT_SUCCESS;
}

