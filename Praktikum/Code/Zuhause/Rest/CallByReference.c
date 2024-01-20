#include <stdio.h>
#include <stdlib.h>

int briefkasten(int post){
  post= post+20;
  return post;
}

int postbote(int* bote){
  *bote = *bote +10;
  return EXIT_SUCCESS;
}

int main(){
  int brief = 100;
  int zahl;

  printf("Ausgabe mit Call-by-Refenrece(1) oder mit übergabe(2)?\n");
  scanf("%d", &zahl);

  switch(zahl){
    case 1:
    postbote(&brief);
    printf("%d\n", brief);
    break;

    case 2:
    brief= briefkasten(brief);
    printf("%d\n", brief);
    break;

    default:
    printf("Fehler!\n");
    break;
  }

  return 0;
}
