#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  char* ptr= "pointer";
  char array[]= "array";
  char a[100];
  int n=7;
  int x=4;
  int y;

  //printf("Mit ptr Addition: %c %c %c %c %c\n", *ptr,*(ptr+1), *(ptr+2), *(ptr+3));
  //printf("Mit ptr[] : %c %c %c %c %c\n", ptr[0], ptr[1], ptr[2], ptr[3]);
  //printf("Nur ptr: %s\n", ptr);

  //printf("Mit Array ptr Arithemtik: %c %c %c %c %c\n", *array, *(array+1), *(array+2), *(array+3));
  //printf("%s\n", array);
  
  //for(int i=0;i<n; i++){
  // printf("Vorwärts: %c%c%c%c%c\n",array[x-4], array[x-3], array[x-2],array[x-1],array[x]);
  // y = x - (i+1);
  // array[y]= "-";
  // }
   
  //printf("\n");
  printf("Wort eingeben\n");
  scanf("%s", a);

  int length;
  length= strlen(a);
  
  for(int i=0;i<length;i++){
    printf("Test : %s\n",a + i);
  } 
   
  printf("\n");

  for(int l=0;l<n; l++){
    printf("Rückwärts: %c%c%c%c%c\n",array[x-4], array[x-3], array[x-2],array[x-1],array[x]);
    array[l]= ' ';
  }

  return EXIT_SUCCESS;
}

