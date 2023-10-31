#include<stdio.h>

int main()
{
  char* mamaName = "Tuyet Lan";
  char* papaName = "Tuan";
  char* schwesterName = "Y Phung";
  char* meinName = "Y Nhi";
  char* freundName = "Maxi";

  int familienAnzahl= 04;

  printf("Die Familie Hoang besteht aus %02d Mitgliedern",familienAnzahl);
  printf(" Mutter %s , Vater %s, Schwester %s und %s\n.", mamaName, papaName, schwesterName, meinName);
  printf("Zu dem kommt noch ein neues Familienmitglied, Nhis Freund, %s\n", freundName);

  return 0;
}
