#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_SIZE 50

void ajouter_livre(char titres[][STRING_SIZE], char auteurs[][STRING_SIZE], float prix[], int quantites[], int *n);
void afficher(char titres[][STRING_SIZE], char auteurs[][STRING_SIZE], float prix[], int quantites[], int n);
int recherche_livre(char titres[][STRING_SIZE], char titre[STRING_SIZE], int n);
void update_quantity(char titres[][STRING_SIZE], int quantities[], int n);
void supprimer_livre(char titres[][STRING_SIZE], char auteurs[][STRING_SIZE], float prix[], int quantites[], int *n);
int nbr_total(int quantities[], int n);

#endif // HEADERS_H_INCLUDED
