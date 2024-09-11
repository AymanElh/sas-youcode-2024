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
int check_date(int annee, int mois, int jour);
int check_departement(char dep[]);
Etudiant saisieEtudiant();
void ajouterEtudiants(Etudiant e[], int nbr, int *taille);
int rechercheEtudiantParId(Etudiant e[], int id, int taille);
void modifierEtudiant(Etudiant e[], int id, int taille);
void supprimerEtudiant(Etudiant e[], int id, int *taille);
int rechercheEtudiantParNom(Etudiant e[], char nom[], int taille);
float moyenneGenerale(Etudiant e[], int taille);
float moyenneGeneraleParDep(Etudiant e[], char dep[], int taille);
void afficherMoyenneGeneraleParDep(Etudiant e[], int taille);
int nbrEtudiantsParDep(Etudiant e[], char dep[], int taille);
void afficherNbrEtudiantsParDep(Etudiant e[], int taille);
void etudiantsSupSeuil(Etudiant e[], float seuil, int taille);
int nbrEtudiantReuissiParDep(Etudiant e[], char dep[], int taille);
void afficherNbrEtudiantsReuissiParDep(Etudiant e[], int taille);
void afficherEtudiant(Etudiant e);
void afficherTous(Etudiant e[], int taille);

#endif