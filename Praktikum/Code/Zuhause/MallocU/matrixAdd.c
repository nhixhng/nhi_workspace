#include <stdlib.h>
#include <stdio.h>

void matAdd(int** a, int** b, int** sum, int m, int n){
    for(int i=0; i<m; i++){
      for (int p= 0; p<n; p++){
        sum[i][p]= a[i][p]+ b[i][p];
      }
    }
}

void druck(int** a, int m, int n){
  for(int i=0; i<m; i++){
      for(int p=0; p<n; p++){
        printf("%04d\t",a[i][p]);
      }
      printf("\n");
    }
  printf("\n");
}

void initialisiere(int** a, int m, int n){
    for(int i=0; i<m; i++){
      for(int p=0; p<n; p++){
        scanf("%d",&(a[i][p]));
      }
    }
}

void free2(int** a, int m){
  for(int i=0; i<m; i++){
    free(a[i]);
  }
  free(a);
}

int main(int argc, char * argv[]){
  if(argc != 3){
    printf("Fehler! Pogramm mit Zahlen als Dimension der Matrix aufurufen: Beispiel bin/add 4 4\n");
    return EXIT_FAILURE;
  }

  int m= atoi(argv[1]);
  int n= atoi(argv[2]);

  //Speicherreservierng für Erste Matrix 
  int** m1= malloc(sizeof(int*)*m);
  if(m1==NULL){
    printf("Out of Memory1\n");
    return EXIT_FAILURE;
  }
  for(int i=0; i<m;i++){
    m1[i]= malloc(sizeof(int)*n);
    if(m1[i]==NULL){
      printf("Out of Memory1.1\n");
      return EXIT_FAILURE;
    }
  }

  //Speicher für array 2
  int** m2= malloc(sizeof(int*)*m);
  if(m2==NULL){
    printf("Out of Memory2\n");
    return EXIT_FAILURE;
  }
  for(int i=0; i<m;i++){
    m2[i]= malloc(sizeof(int)*n);
    if(m2[i]==NULL){
      printf("Out of Memory2.2\n");
      return EXIT_FAILURE;
    }
  }
  
  //Speicher für array 3 
  int** m3= malloc(sizeof(int*)*m);
  if(m3==NULL){
    printf("Out of Memory3\n");
    return EXIT_FAILURE;
  }
  for(int i=0; i<m;i++){
    m3[i]= malloc(sizeof(int)*n);
    if(m3[i]==NULL){
      printf("Out of Memory3.1\n");
      return EXIT_FAILURE;
    }
  }

  printf("Zahlen für deine erste Matrix\n");
  initialisiere(m1,m,n);

  printf("Zahlen für deine zweite Matrix\n");
  initialisiere(m2,m,n);

  printf("Matrix 1:\n");
  druck(m1,m,n);

  printf("Matrix 2:\n");
  druck(m2,m,n);

  matAdd(m1,m2,m3,m,n);
 
  printf("Ergebnis von der Addition: \n");
  druck(m3,m,n);

  free2(m1,m);
  free2(m2,m);
  free2(m3,m);

  return EXIT_SUCCESS;
}
