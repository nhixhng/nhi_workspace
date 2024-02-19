#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct person{
  char name[10];
  struct person* next;
} person_t;

person_t* list_create(char name[]){
  person_t* new;
  new = malloc(sizeof(person_t));
  if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

  strcpy(new->name,name);
  new->next= NULL;
  return new;
}

person_t* list_insert(person_t* anchor,char name[]){
  person_t* new;
  new= list_create(name);
  new->next= anchor;
  return new;
}

bool list_contains(person_t* node, char name[]){
  bool res= false;
  while(node!= NULL){
    if(strcmp(node->name,name)== 0){
      res=true;
    }
    node= node->next;
  }
  return res;
}

char* head_element(person_t* anchor){
  if(anchor==NULL){
    return NULL;
  }
  return anchor->name;
}

char* tail_element(person_t* anchor){
  if(anchor->next==NULL){
    return anchor->name;
  } else {
    return tail_element(anchor->next);
  }
}

person_t* remove_head(person_t* node){
  if(node==NULL){
    return NULL;
  }
  else{
    person_t* temp= node-> next;
    free(node);
    return temp;
  }
}

person_t* remove_tail(person_t* node){
  if(node==NULL){
    return NULL;
  }
  person_t* last = NULL;
  person_t* current= node;
  while(current->next != NULL){
    last= current;
    current= current->next;
  }
  free(current);
  if(last== NULL){
    return NULL;
  } else {
    last->next= NULL;
  }
  return node;
}

void print(person_t* anchor){
  while (anchor != NULL){
    printf("%s\n", anchor->name);
    anchor= anchor->next;
  }
}

int main(){
  person_t* myList= NULL;
  
  myList= list_insert(myList,"Nhi");
  myList= list_insert(myList,"Emma");
  myList= list_insert(myList,"Max");
  myList= list_insert(myList,"Emma");

  printf("deine aktuelle liste\n");
  print(myList);

  printf("Daten abbgleich\n");
  bool res= list_contains(myList,"Max");
  if(res){
    printf("Max ist dabei\n");
  }

  printf("Das aktuelle Kopfelement ist: %s\n", head_element(myList));
  printf("Das aktuelle Schwanzelement ist: %s\n", tail_element(myList));

  printf("Kopf löschen\n");
  myList= remove_head(myList);
  print(myList);

  printf("tail weg\n");
  myList= remove_tail(myList);
  print(myList);


  // Speicher freigeben
    while (myList != NULL) {
        person_t* temp = myList->next;
        free(myList);
        myList = temp;
    }
  
    return EXIT_SUCCESS;
}




