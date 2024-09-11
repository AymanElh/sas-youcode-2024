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

int check_date(int annee, int mois, int jour)
{
    if(annee < 1)
        return 0;

    if(mois < 1 || mois > 12)
        return 0;

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
        days[1] = 29;

    if(jour < 1 || jour > days[mois-1])
        return 0;

    return 1;
}

int check_departement(char dep[])
{
    int size = sizeof(departements) / sizeof(departements[0]);
    for(int i = 0; i < size; i++)
    {
        if(strcmp(strlwr(dep), strlwr(departements[i])) == 0)
            return 1;
    }
    return 0;
}

Etudiant saisieEtudiant()
{
    Etudiant e1;
    id_counter++;
    e1.id = id_counter;
    printf("Nom: ");
    scanf(" %[^\n]", e1.nom);
    printf("Prenom: ");
    scanf(" %[^\n]", e1.prenom);
    printf("Date de naissance (YYYY-MM-DD): ");
    while(scanf("%d-%d-%d", &e1.dateNaissance.annee, &e1.dateNaissance.mois, &e1.dateNaissance.jour) != 3 || !check_date(e1.dateNaissance.annee, e1.dateNaissance.mois, e1.dateNaissance.jour))
    {
        printf("Invalide date, Ressayer: ");
    }
    printf("Choisi un Departement: \n");
    for(int i = 0; i < 6; i++)  
        printf("   %s\n", departements[i]);
    printf("Departement: ");
    while(scanf(" %[^\n]", e1.departement) != 1 || !check_departement(e1.departement))
    {
        printf("Invalide departement, Ressayer: ");
    }
    printf("Note generale: ");
    scanf("%f", &e1.note_generale);
    return e1;
}

void ajouterEtudiants(Etudiant e[], int nbr, int *taille)
{
    for(int i = 0; i < nbr; i++)
    {
        printf("Entrer les informations d'etudiant %d\n", i+1);
        e[*taille] = saisieEtudiant();
        (*taille) ++;
    }
}

int rechercheEtudiantParId(Etudiant e[], int id, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        if(e[i].id == id)
            return i;
    }
    return -1;
}
