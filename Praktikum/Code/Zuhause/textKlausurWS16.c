#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int v1=2;
void collatz_iter(int n){
  while(n>1){
    printf("%d ",n);
    if(n%2 == 0){
      n = n/2;
    } else {
      n = 3* n+1;
    }
  }
  printf("%d\n" ,n);
}

bool istVokal(char c){
  if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u'){
    return true;
  } else {
    return false;
  }
}

int zaehleVokale(char *s){
  int anzahl=0;
  size_t lange= strlen(s);
  for(int i=0; i< lange; i++){
    switch(s[i]){
      case 'a':
      anzahl= anzahl +1;
      break;
      
      case 'e':
      anzahl= anzahl +1;
      break;

      case 'i':
      anzahl= anzahl +1;
      break;

      case 'o':
      anzahl= anzahl +1;
      break;

      case 'u':
      anzahl= anzahl +1;
      break;
    }
  }
  return anzahl;
  
}



int main(){

  int v2=3;
  {
    int v1=7;
    int v2=4;
    printf("%d\n", v1*v2);
  }
  printf("%d\n", v1*v2);
  
  //char satz1[] = "Wie heisst der Buergermeister von Wesel";

  //printf("%s\n", satz1+ (7*5));

  char* satz2 = "Wie heisst der Buergermeister von Wesel";
  int z= zaehleVokale(satz2);
  printf("Anzahl: %d\n",z);

  //printf("satz2: %s\n", &satz2[40-5]);
  collatz_iter(6);
  return 0;
}

