#include "headers.h"

char departements[][STRING_SIZE] = {"Maths", "Physique", "Chimie", "Biologie", "Geologie", "Informatique"};

int id_counter = 0;

void Menu()
{
    printf("\n ********** MENU ********** \n");
    printf("1. Ajouter des etudiants.\n");
    printf("2. Modifier etudiant.\n");
    printf("3. Supprimer etudiant.\n");
    printf("4. Recherche etudiant par son Id.\n");
    printf("5. Recherche etudiant par son Nom.\n");
    printf("6. Afficher les etudiants inscrit dans un departements specifie.\n");
    printf("7. Moyenne generale de l'unversite.\n");
    printf("8. Moyenne generale par departement.\n");
    printf("9. Statistiques.\n");
    printf("10. Tri les etudiants par moyenne generale.\n");
    printf("11. Tri les etudiants par ordre alphabetiques (A-z).\n");
    printf("12. Tri les etudiants par ordre alphabetiques (Z-A).\n");
    printf("13. Tri les etudiants par leur status.\n");
    printf("14. Afficher tous.\n");
}