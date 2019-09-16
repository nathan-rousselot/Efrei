//Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structures
typedef struct Maillon{
  int info;
  struct Maillon * suivant;
}Maillon;
//prototypes
void rebourd(Maillon* maillon);
void print_list(Maillon* maillon);
void concatener(Maillon* maillon1, Maillon* maillon2);


//main
int main(){
  Maillon maillon;
  Maillon maillon1;
  Maillon maillon2;
  Maillon maillon3;
  maillon.info = 1;
  maillon1.info = 2;
  maillon2.info = 3;
  maillon3.info = 4;
  maillon.suivant = &maillon1;
  maillon1.suivant = NULL;
  maillon2.suivant = &maillon3;
  maillon3.suivant = NULL;

  /* EXO1
  rebourd(&maillon);
  */

  /*
  concatener(&maillon, &maillon2);
  print_list(&maillon);
  */

  return 0;
}

//functions
//EXO
void print_list(Maillon* maillon){
  while(maillon != NULL){
    printf("%d ", maillon->info);
    maillon = maillon->suivant;
  }
}

//EXO1
void rebourd(Maillon* maillon){
  if (maillon == NULL){
    return;
  }
  rebourd(maillon->suivant);
  printf("%d ", maillon->info);
}

//EXO2
void concatener(Maillon* maillon1, Maillon* maillon2){
  Maillon* temp = maillon1;
  while(temp->suivant != NULL){
    temp = temp->suivant;
  }
  temp->suivant = maillon2;
}

//EXO3
