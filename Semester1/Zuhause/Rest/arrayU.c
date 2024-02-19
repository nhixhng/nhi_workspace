#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10];
    int zaehler= 10;

    for(int i=0; i<10 ;i++){
      printf("Sie müssen noch %d Zahlen eingeben: \n", zaehler);
      scanf("%d", &a[i]);
      zaehler= zaehler -1;
    }

    printf("\n ------------------------------------------------ \n");

    for(int i=0; i<10; i++){
      printf("Die Zahlen in deinem Array sind: %03d\n", a[i]);
    }

    return EXIT_SUCCESS;
}

