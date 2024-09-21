#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nom[20];
    char numero[11];
    char email[50];
}Contact;

int checkNumero(char num[]);
Contact saisieContact();
void ajouterContact(Contact **c, int *taille);
void ajouterPlusieursContacts(Contact **c, int nbr, int *taille);
int rechercheParId(Contact *c, int id, int taille);
int rechercheParNom(Contact *c, char nom[], int taille);
void modifierContactName(Contact *c, char nom[], int id, int taille);
void modifierContactNumero(Contact *c, char numero[], int id, int taille);
void modifierContactEmail(Contact *c, char email[], int id, int taille);
void supprimerContactParId(Contact **c, int id, int *taille);
void supprimerContactParNom(Contact **c, char name[], int *taille);
void triContactsParId(Contact *c, int taille);
void afficherContact(Contact c);
void afficherTous(Contact *c, int taille);

#endif