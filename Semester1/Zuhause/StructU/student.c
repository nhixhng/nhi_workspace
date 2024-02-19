#include <stdio.h>
#include <stdlib.h>


typedef struct addresse{
  char name[10];
  int postleitzahl;
} addresse;

typedef struct student{
  char name[10];
  int matrikelnummer;
  addresse wohnort;
} student;

student studenteingabe(student s1){
  printf("Bitte Vor- und Nachname eingeben:\n");
  scanf("%s", s1.name); //gehe zu den block s1 und wähle das array aus (Array=Addresse)

  printf("Bitte Matrikelnummer eingeben:\n");
  scanf("%d", &(s1.matrikelnummer));

  printf("Bitte straßenname eingeben:\n");
  scanf("%s", s1.wohnort.name);

  printf("Bitte Postleitzahl eingeben:\n");
  scanf("%d", &(s1.wohnort.postleitzahl));

  return s1;
} 

int main(){
  student s2= {"nhi", 1, {"haslangStr",85049}};
  printf("Name\t\tMatrikelnummer\t\tWohnort\n");
  printf("%s\t\t%05d\t\t%s,%d\n", s2.name, s2.matrikelnummer, s2.wohnort.name, s2.wohnort.postleitzahl);
 
  s2= studenteingabe(s2);
  printf("Nach meiner Ueberschreibung:\n");
  printf("%s\t\t%05d\t\t%s,%d\n", s2.name, s2.matrikelnummer, s2.wohnort.name, s2.wohnort.postleitzahl);

  return EXIT_SUCCESS;
}

