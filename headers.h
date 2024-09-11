#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 1000
#define STRING_SIZE 20



typedef struct 
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct 
{
    int id;
    char nom[STRING_SIZE];
    char prenom[STRING_SIZE];
    Date dateNaissance;
    char departement[STRING_SIZE];
    float note_generale;
}Etudiant;

void Menu();

#endif