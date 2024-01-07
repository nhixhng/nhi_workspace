#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern bool even(int z);
extern bool odd(int z);

bool even(int z){
  if(z==0){
    return true;
  } else {
    return odd(z-1);
  }
}

bool odd(int z){
  if(z==0){
    return false;
  } else {
    return even(z-1);
  }
}

int main(int argc, char* argv[]){
  if(argc != 2){
    printf("Rufe das Pogramm mit einer Zahl auf, als Beispiel bin/indirekteRekursion 5\n");
    return EXIT_FAILURE;
  }

  int z = atoi(argv[1]);

  if(even(z)==0){
    printf("Deine Zahl: %03d ist ungerade :(\n",z);
  } else {
    printf("Deine Zahl: %03d ist gerade ;)\n",z);
  }
  return EXIT_SUCCESS;
}
  


