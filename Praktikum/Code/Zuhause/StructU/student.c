#include <stdlib.h>
#include <stdio.h>

typedef struct addresse{
  char strName[20];
  int postleitzahl;
} addresse;

typedef struct student{
  char name[10];
  char vorname[15];
  int matrikelnummer;
  addresse wohnort;
} student;

student studentEingabe(student s1){
  printf("Bitte Name eingeben\n");
  scanf("%s\n",(&s1)->name);

  printf("Bitt Vorname eingeben\n");
  scanf("%s\n",(&s1)->vorname);

  printf("Bitte matrikelnummer eingeben\n");
  scanf("%d\n",(&s1)->matrikelnummer);

  printf("Bitte Strase und nr eingeben\n");
  scanf("%s\n",(&s1)->wohnort.strName);

  printf("Bitte Postleitzahl eingeben\n");
  scanf("%d\n",(&s1)->wohnort.postleitzahl);

  printf("Student: %s, %s mit der Matrikelnuller: %010d, wohnt in der %s ,%d\n", (&s1)->vorname, (&s1)->name, (&s1)->matrikelnummer, (&s1)->wohnort.strName, (&s1)->wohnort.postleitzahl);

  return s1;
}

int main(){
  student s2;
  studentEingabe(s2);
  return EXIT_SUCCESS;
}


