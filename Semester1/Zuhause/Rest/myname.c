#include<stdio.h>

int main()
{
  char* name;
  int day;
  int month;
  int year;
 
  name= "YNhi Hoang";
  day= 28;
  month= 03;
  year= 2004;

  printf("Mein Name ist %s\n", name);
  printf("Mein Geburtsdatum ist der %02d.%02d.%04d\n",day,month,year);

  return 0;
}

