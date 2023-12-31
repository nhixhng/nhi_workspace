#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct vec {
  int x;
  int y;
} vec;

vec vec_Add(vec vec1, vec vec2){
  vec vec3;
  vec3.x= vec2.x+ vec1.x;
  vec3.y= vec2.y+ vec1.y;
  return vec3;
}

vec vec_Neg(vec v1){
  v1.x = -v1.x;
  v1.y = -v1.y;
  return v1;
}

int main(){
 // vec v1= {4,5};
 // vec v2= {2,2};
 // vec v3;
  vec v1,v2,v3;

  printf("Eingabe für den ersten Vektor\n");
  printf("x= \n");
  scanf("%d", &v1.x);
  printf("y= \n");
  scanf("%d", &v1.y);

  printf("Eingabe für den zweiten Vektor\n");
  printf("x= \n");
  scanf("%d", &v2.x);
  printf("y= \n");
  scanf("%d", &v2.y);

  v3= vec_Add(v1,v2);
  printf("Vektor V1= %02d\t%02d\n", v1.x, v1.y);
  printf("Vektor V2= %02d\t%02d\n", v2.x, v2.y);
  printf("(%02d, %02d) + (%02d, %02d) = (%02d,%02d)\n",v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);

  v2= vec_Neg(v2);
  printf("Vektor V2= %02d\t%02d negiert\n", v2.x, v2.y);

  return EXIT_SUCCESS;
}

