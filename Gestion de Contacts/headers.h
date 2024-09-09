#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct contact
{
    int id;
    char nom[50];
    char numero[12];
    char email[50];
}contact;

void ajouter_contact(contact c[], int *n);
int recherche_contact(contact c[], char name[], int n);
void modifier_contact(contact c[], char name[], int n);
void supprimer_contact(contact c[], char name[], int *n);
void afficher(contact c[], int n);



#endif // HEADER_H_INCLUDED
