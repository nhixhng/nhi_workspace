#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool even(int z){
  return (z%2 == 0);
}

int main(int argc, char* argv[]){
  if (argc != 2){
    printf("Fehler, du muss das Pogramm mit einer Zahl aufrufen\n");
    return EXIT_FAILURE;
  }

  int z= atoi(argv[1]);

  if(even(z) == 1){
    printf("Die Zahl %03d ist gerade!\n", z);
  } else {
    printf("Die Zahl %03d ist ungerade!\n", z);
  }
  return EXIT_SUCCESS;
}




  
