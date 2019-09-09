//Directives
#include <stdlib.h>
#include <stdio.h>

//structures
typedef struct Maillon{
  int info;
  struct Maillon * suivant;
}Maillon;

//prototypes
int length(Maillon maillon);
int length_rec(Maillon maillon);
int find(Maillon maillon, int info);
int find_rec(Maillon maillon, int info, int i);
int occ(Maillon maillon, int info);
int occ_rec(Maillon maillon, int info);
void one_on_two(Maillon maillon);
void one_on_two_rec(Maillon maillon, int i);
void is_growing(Maillon maillon);

//main
int main(){
    Maillon maillon;
    Maillon maillon1;
    Maillon maillon2;
    Maillon maillon3;
    maillon.info = 1;
    maillon1.info = 2;
    maillon2.info = 4;
    maillon3.info = 4;
    maillon.suivant = &maillon1;
    maillon1.suivant = &maillon2;
    maillon2.suivant = &maillon3;
    maillon3.suivant = NULL;


    /* //EXO1
    int l = length(maillon1);
    int l_rec = length_rec(maillon):
    printf("%d ; %d", l, l1);
    */

    /* //EXO2
    int p = find(maillon, 4);
    int p_rec = find_rec(maillon, 4, 0);
    printf("%d ; %d", p, p_rec);
    */

    /* //EXO3
    int oc = occ(maillon, 2);
    int oc_rec = occ_rec(maillon, 2);
    printf("%d ; %d", oc, oc_rec);
    */

    /* //EXO4
    one_on_two(maillon);
    one_on_two_rec(maillon, 0);
    */

    /* // EXO05
    is_growing(maillon);
    */

    return 0;
}

//funtctions
//EXO1
int length(Maillon maillon){
  int i = 1;
  while ((maillon.suivant) != NULL){
    maillon = *(maillon.suivant);
    i++;
  }
  return i;
}

int length_rec(Maillon maillon){
  if ((maillon.suivant) == NULL){
    return 1;
  }
  else {
    return 1 + length_rec(*(maillon.suivant));
  }
}

//EXO2
int find(Maillon maillon, int info){
  int i = 0;
  int n = length_rec(maillon);
  while(i < n){
    if (maillon.info == info){
      i += n + 1;
    }
    else{
      i++;
      if (i != n){
        maillon = *(maillon.suivant);
      }
    }
  }
  if (i == n){
    return -1;
  }
  return i - n - 1;
}

int find_rec(Maillon maillon, int info, int i){
  int n = length_rec(maillon);
  if (maillon.info == info){
    return i;
  }
  if (maillon.suivant == NULL){
    return -1;
  }
  return find_rec(*(maillon.suivant), info, i+1);
}

//EXO3
int occ(Maillon maillon, int info){
  int n = length_rec(maillon);
  int i = 0;
  int oc = 0;
  while (i < n){
    if (maillon.info == info){
      oc++;
    }
    i++;
    if (i != n){
      maillon = *(maillon.suivant);
    }
  }
  return oc;
}

int occ_rec(Maillon maillon, int info){
  int n = length_rec(maillon);
  if (maillon.info == info && maillon.suivant == NULL){
    return 1;
  }
  else if (maillon.suivant == NULL){
    return 0;
  }
  else if (maillon.info == info){
    return 1 + occ_rec(*(maillon.suivant), info);
  }
  return occ_rec(*(maillon.suivant), info);
}

//EXO4
void one_on_two(Maillon maillon){
  int n = length_rec(maillon);
  int i = 0;
  while (i < n){
    if ((i % 2) == 0) {
      printf("%d ", maillon.info);
    }
    i++;
    if (i != n){
      maillon = *(maillon.suivant);
    }
  }
}

void one_on_two_rec(Maillon maillon, int i){
  if (i % 2 == 0){
    printf("%d ", maillon.info);
  }
  if (maillon.suivant != NULL){
    one_on_two_rec(*(maillon.suivant), i+1);
  }
}

//EXO5
void is_growing(Maillon maillon){
  if (maillon.suivant != NULL && (*(maillon.suivant)).info <= maillon.info){
    printf("La liste n'est pas strictement croissante.\n");
  }
  else if (maillon.suivant == NULL){
    printf("La liste est strictement croissante.\n");
  }
  else {
    is_growing(*(maillon.suivant));
  }
}

//EXO6
Maillon * add_cell(Maillon * maillon, int pos, int info){
  if (pos == 0){
    Maillon * new_maillon = malloc(sizeof(Maillon));
    new_maillon->info = info;
    new_maillon->suivant = maillon;
    return maillon;
  }
  else{
    int n = length(*mail  lon);
    if (pos >= n){
      Maillon * new_maillon = malloc(sizeof(Maillon));
      while (maillon->suivant != NULL){
        *maillon = maillon->suivant;
      }
      maillon->suivant = new_maillon;
      new_maillon->info = info;
      new_maillon->suivant = NULL;
      return new_maillon;
    }
    else{
      int i = 0;
      while (i < pos){
        *maillon = maillon->suivant;
        i++;
      }
      Maillon * new_maillon = malloc(sizeof(Maillon));
      new_maillon->info = info;
      new_maillon->suivant = maillon->suivant;
      maillon->suivant = new_maillon;
      return new_maillon;
    }
  }
}
