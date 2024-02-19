#include <stdlib.h>
#include <stdio.h>

int matadd( int m, int n){
    int i,p;
    int** m1;
    int** m2;
    int** m3;

    m1=  malloc(m* sizeof(int));
    if(m1== NULL){
      printf("Fehler\n");
      return EXIT_FAILURE;
    }


    for(int y=0; y < m; y++){
      m1[y] = malloc(sizeof(int) * n);
      if(m1[y]== NULL){
        printf("Fehler\n");
        return EXIT_FAILURE;
      }
    }

    for(i=0; i< m; i++){
      for(p=0; p <n ; p++){
        m1[i][p]= p+1;
      }
    }

    for(i=0; i < m; i++){
      for(p =0;p<n ;p ++){
        printf("%d ", m1[i][p]);
      }
      printf("\n");
    }

    printf("\n");

    m2=  malloc(m* sizeof(int));
    if(m2== NULL){
      printf("Fehler\n");
      return EXIT_FAILURE;
    }


    for(int y=0; y < m; y++){
      m2[y] = malloc(sizeof(int) * n);
      if(m2[y]== NULL){
        printf("Fehler\n");
        return EXIT_FAILURE;
      }
    }

    for(i=0; i< m; i++){
      for(p=0; p <n ; p++){
        m2[i][p]= p+2;
      }
    }

    m3=  malloc(m* sizeof(int));
    if(m3== NULL){
      printf("Fehler\n");
      return EXIT_FAILURE;
    }


    for(int y=0; y < m; y++){
      m3[y] = malloc(sizeof(int) * n);
      if(m3[y]== NULL){
        printf("Fehler\n");
        return EXIT_FAILURE;
      }
    }

    for(i=0; i < m; i++){
      for(p =0;p<n ;p ++){
        printf("%d ", m2[i][p]);
      }
      printf("\n");
    }

    for(i=0; i < m; i++){
      for(p =0;p<n ;p ++){
        m3[i][p]= m2[i][p] + m1[i][p];
      }
    }

    printf("\n");

    for(i=0; i < m; i++){
      for(p =0;p<n ;p ++){
        printf("%d ", m3[i][p]);
      }
      printf("\n");
    }

    free(m1);
    free(m2);
    free(m3);
}

int main(){
    
    int m,n;
    printf("gebe die Größe deiner Mamtrix an\n");
    printf("m = \n");
    scanf("%d", &m);
    printf("n = \n");
    scanf("%d", &n);

    matadd(m,n);
    return EXIT_SUCCESS;
}

