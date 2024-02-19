#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    int m= atoi(argv[1]);
    int n= atoi(argv[2]);
    int** m1, m2;
    int x,k;
    
    if(argc != 3){
      printf("Rufe das Pogramm mit zwei zahlen für die beiden Dimension der Matrix auf\n");
      return 1;
    }

    printf("Zahl für die Matrix eingeben ");
    scanf("%d", &x);

    m1= malloc(sizeof(int)*m);
    if(m1==0){
      printf("error\n");
    }

    for(int i=0; i<m; i++){
      m1[i]= malloc(sizeof(int)*n);
      if(m2==0){
        printf("error\n");
      }
    }
    
    for(int i=0; i<m; i++){
      for(int p=0; p<n; p++){
        m1[i][p]= x;
      }
    }

    for(int i=0; i<m; i++){
      for(int p=0; p<n; p++){
        printf("%d",m1[i][p]);
      }
      printf("\n");
    }
    free(m1);
    return 0;
}

