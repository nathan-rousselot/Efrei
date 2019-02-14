#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mem.h>
#include <unistd.h>


//EXO 1

void print_type() {
    int a = 5;
    long b = 12;
    float c = 5.2;
    double d = 85;
    char e = 'a';
    char f[] = "abcde";
    printf("%d, %ld, %f, %f, %c, %s", a, b, c, d, e, f);
}

//EXO 2

int particle(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    else if (a == -1 && b == -1) {
        return -1;
    }
    else if (a == -1 && b == 1) {
        return 0;
    }
    else {
        return -6;
    }
}

// EXO 3

int resultante(int A[10]) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += A[i];
    }
    if (sum > 0) {
        return 1;
    }
    else if (sum < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

// EXO 4

int* two_tab_treatment(int A[10], int B[10]) {
    int* res = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        res[i] = particle(A[i], B[i]);
    }
    return res;
}

// EXO 5

void adjectifs() {
    char *adj_tab[5];
    for (int i = 0; i < 5; i++) {
        printf("Entrez un adjectif: ");
        scanf("%s", &adj_tab[i]);
    }
    for (int j = 0; j < 5; j++) {
        printf("%s ", &adj_tab[j]);
    }
}

char** get_five_strings() {
   char **adj_tab = malloc(5 * sizeof(char*));
   int j = 0;
   while (j < 5) {
       adj_tab[j] = malloc(10 * sizeof(char));
       j++;
   }
   int i = 0;
   while (i < 5) {
       scanf("%s", adj_tab[i]);
       i++;
   }
    return adj_tab;
}

int len(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char* concatenate (char* s1, char* s2) {
    int final_length = len(s1) + len(s2) + 1;
    char* res = malloc(final_length * sizeof(char));
    int i = 0;
    while (i < len(s1)) {
        res[i] = s1[i];
        i++;
    }
    int j = 0;
    res[i] = ' ';
    while (j < len(s2)) {
        res[j + i + 1] = s2[j];
        j++;
    }
    res[j+i+1] = '\0';
    return res;
}

void nom_indien() {
    printf("Entrez cinq adjectifs :  ");
    char** adj = get_five_strings();
    printf("\nEntrez cinq noms :  ");
    char** name = get_five_strings();
    int j = 0;
    char entry;
    char* radj;
    char* rname;
    while (j < 5){
        printf("Appuyez sur ENTER pour generer un nouveau nom indien\n");
        scanf("%c", &entry);
        radj = adj[rand_a_b(0, 5)];
        rname = name[rand_a_b(0, 5)];
        printf("%s\n", concatenate(rname, radj));
    }

    int i = 0;
    while (i < 5) {
        free(adj[i]);
        free(adj[i]);
    }
    free(adj);
    free(name);
}

// EXO 6

void typage_user() {
    char entry;
    char* value;
    while (entry != '5') {
        printf("Quel type voulez-vous entrez ? \n- Ecrire 1 pour entrer un entier\n- Ecrire 2 pour entrer un decimal\n- Ecrire 3 pour entrer un caractere unique\n- Ou ecrire 4 pour entrer une chaine de caracteres\n- Ecrire 5 pour arreter le programme.\n");
        scanf("%c", &entry);
        sleep(1);
        if (entry == '1') {
            printf("Veuillez entrer un entier");
            scanf("%d", &value);
            sleep(1);
        }
        else if (entry == '2') {
            printf("Veuillez entrer un decimal");
            scanf("%f", &value);
            sleep(1);
        }
        else if (entry == '3') {
            printf("Veuillez entrer un caractere unique");
            scanf("%c", &value);
            sleep(1);
        }
        else if (entry == '4') {
            printf("Veuillez entrer une chaine de caractere.");
            scanf("%s", &value);
            sleep(1);
        }
        else if (entry != '5') {
            printf("Vous n avez pas choisi une bonne option.\n");
            sleep(1);
        }
    }
}


int main() {
    srand(time(NULL));
    //EXO 1
    /*
    print_type();
    */

    //EXO 2
    /*
    int particle_test;
    particle_test = particle(1, 1);
    printf("%d", particle_test);
    */


    //EXO 3
    /*
    int A[10];
    int resultante_test;
    for (int i = 0; i < 10; i++) {
        A[i] = rand_a_b(0,2);
    }
    resultante_test = resultante(A);
    printf("%d", resultante_test);
    */


    //EXO 4
    /*
    int A[10];
    int B[10];
    for (int i = 0; i < 10; i++) {
        A[i] = 1;
        B[i] = 0;
    }
    int* arr = two_tab_treatment(A, B);
    for (int j = 0; j < 10; j++) {
        printf("%d ", arr[j]);
    }
    free(arr);
    */

    //EXO 5
    /*
    adjectifs();
    nom_indien();
    */

    //EXO 6
    //typage_user();


    return 0;
}
