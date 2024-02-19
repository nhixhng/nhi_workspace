#include <stdlib.h>
#include <stdio.h>

typedef struct zeit{
  int minuten;
  int sekunden;
  char sieger[6];
} zeit;

typedef struct teilnehmer{
  zeit zeit;
  char name[10];
} laufer;

int main(){
  laufer l1= {{10, 50, "Gold"},"Nhi"};
  printf("%s ist %d:%d Minuten gelaufen und hat %s erhalten\n", (&l1)->name, l1.zeit.minuten, l1.zeit.sekunden, (&l1)->zeit.sieger);
  return EXIT_SUCCESS;
}

  
