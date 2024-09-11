#include "headers.h"

char departements[][STRING_SIZE] = {"Maths", "Physique", "Chimie", "Biologie", "Geologie", "Informatique"};
const int size = sizeof(departements) / sizeof(departements[0]);

int id_counter = 0;

void Menu()
{
    printf("\n ---------- MENU ---------- \n");
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
    printf("15. Quitter.\n");
    printf("   -------------------         \n");
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

void modifierEtudiant(Etudiant e[], int id, int taille)
{
    int index = rechercheEtudiantParId(e, id, taille);
    if(index == -1)
    {
        printf("L'etudiant n'existe pas.\n");
        return;
    }
    printf("1. Nom.\n");
    printf("2. Prenom.\n");
    printf("3. Date de naissance.\n");
    printf("4. Departement.\n");
    printf("5. Note generale.\n");
    printf("6. Tous.\n");

    int choix;
    printf("Entrer le nombre d'element que vous voulez modifier.\n");
    scanf("%d", &choix);

    switch(choix)
    {
        case 1:
        {
            char nom[STRING_SIZE];
            printf("Entrer le nouveau nom: ");
            scanf(" %[^\n]", nom);
            strcpy(e[index].nom, nom);
            break;
        }
        case 2:
        {
            char prenom[STRING_SIZE];
            printf("Entrer le nouveau prenom: ");
            scanf(" %[^\n]", prenom);
            strcpy(e[index].prenom, prenom);
            break;
        }
        case 3:
        {
            int annee, mois, jour;
            printf("Entrer la nouvelle date (YYYY-MM-DD): ");
            while(scanf("%d-%d-%d", &annee, &mois, &jour) != 3 || !check_date(annee, mois, jour))
            {
                printf("Invalide date, ressayer: ");
            }
            e[index].dateNaissance.annee = annee;
            e[index].dateNaissance.mois = mois;
            e[index].dateNaissance.jour = jour;
            break;
        }
        case 4:
        {
            char departement[STRING_SIZE];
            printf("Entrer le nouveau departement: ");
            scanf(" %[^\n]", departement);
            strcpy(e[index].departement, departement);
            break;
        }
        case 5:
        {
            float note;
            printf("Entrer la nouvelle note: ");
            scanf("%f", &note);
            e[index].note_generale = note;
            break;
        }
        case 7:
        {
            e[index] = saisieEtudiant();
            break;
        }
    }
    printf("L'etudiant a ete modifier.\n");
}

void supprimerEtudiant(Etudiant e[], int id, int *taille)
{
    int index = rechercheEtudiantParId(e, id, *taille);
    if(index == -1)
    {
        printf("L'etudiant n'existe pas.\n");
        return;
    }
    for(int i = index; i < *taille; i++)
    {
        e[i] = e[i+1];
    }
    (*taille) --;
    printf("L'etudiant a ete supprimee.\n");
}

int rechercheEtudiantParNom(Etudiant e[], char nom[], int taille)
{
    for(int i = 0; i < taille; i++)
    {
        if(strcmp(strlwr(e[i].nom), strlwr(nom)) == 0)
        {
            return i;
        }
    }
    return -1;
}

float moyenneGenerale(Etudiant e[], int taille)
{
    int sum = 0;
    for(int i = 0; i < taille; i++)
    {
        sum += e[i].note_generale;
    }
    return sum / taille;
}

float moyenneGeneraleParDep(Etudiant e[], char dep[], int taille)
{
    float sum = 0;
    int counter = 0;
    for(int i = 0; i < taille; i++)
    {
        if(strcmp(strlwr(e[i].departement), strlwr(dep)) == 0)
        {
            sum += e[i].note_generale;
            counter++;
        }
    }
    return sum / counter;
}

void afficherMoyenneGeneraleParDep(Etudiant e[], int taille)
{
    for(int i = 0; i < size; i++)
    {
        printf("Le moyenne generale du departement de %s est: %.2f.\n", departements[i], moyenneGeneraleParDep(e, departements[i], taille));
    }
}

int nbrEtudiantsParDep(Etudiant e[], char dep[], int taille)
{
    int nbr_students = 0;
    for(int i = 0; i < taille; i++)
    {
        if(strcmp(strlwr(e[i].departement), strlwr(dep)) == 0)
            nbr_students++;
    }
    return nbr_students;
}
void afficherNbrEtudiantsParDep(Etudiant e[], int taille)
{
    for(int i = 0; i < size; i++)
        printf("Nombre total des etudiants dans departement %s est: %d\n", departements[i], nbrEtudiantsParDep(e, departements[i], taille));
}

void etudiantsSupSeuil(Etudiant e[], float seuil, int taille)
{
    printf("Les etudiants qu'ayant un note supperieur a %.2f sont: \n");
    for(int i = 0; i < taille; i++)
    {
        if(e[i].note_generale >= seuil)
            printf("%s %s\n", e[i].nom, e[i].prenom);
    }
}

void topTrois(Etudiant e[], int taille)
{
    int max_idx1, max_idx2, max_idx3;
    max_idx1 = max_idx2 = max_idx3 = 0;
    for(int i = 1; i < taille; i++)
    {
        if(e[max_idx1].note_generale < e[i].note_generale)
        {
            max_idx3 = max_idx2;
            max_idx2 = max_idx1;
            max_idx1 = i;
        }
        else if(e[max_idx1].note_generale > e[max_idx2].note_generale && e[max_idx2].note_generale < e[i].note_generale)
        {
            max_idx3 = max_idx2;
            max_idx2 = i;
        }
        else
            max_idx3 = i;
    }

    printf("Top 3 etudiants sont: ");
    printf("%s: %.2f\n", e[max_idx1].nom, e[max_idx1].note_generale);
    printf("%s: %.2f\n", e[max_idx2].nom, e[max_idx2].note_generale);
    printf("%s: %.2f\n", e[max_idx3].nom, e[max_idx3].note_generale);
    
}

int nbrEtudiantReuissiParDep(Etudiant e[], char dep[], int taille)
{
    int nbr;
    for(int i = 0; i < taille; i++)
    {
        if(strcmp(strlwr(e[i].departement), strlwr(dep)) == 0 && e[i].note_generale >= 10)
            nbr++;
    }
    return nbr;
}

void afficherNbrEtudiantsReuissiParDep(Etudiant e[], int taille)
{
    printf("\nLe nombre des etudiant par departement: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%s: %d\n", departements[i], nbrEtudiantReuissiParDep(e, departements[i], taille));
    }
}

void afficherEtudiantsInscritsParDep(Etudiant e[], int taille)
{
    int j = 0;
    while(j < size)
    {
        printf("Les etudians inscrits dans %s:\n", departements[j]);
        for(int i = 0; i < taille; i++)
        {
            if(strcmp(e[i].departement, departements[j]) == 0)
            {
                printf("%s %s\n", e[i].nom, e[i].prenom);
            }
        }
        j++;
    }
}

void swap(Etudiant *a, Etudiant *b)
{
    Etudiant temp = *a;
    *a = *b;
    *b = temp;
}

void triParMoyenneGenerale(Etudiant e[], int taille)
{
    int min_idx;
    for(int i = 0; i < taille; i++)
    {
        min_idx = i;
        for(int j = i; j < taille; j++)
        {
            if(e[i].note_generale < e[j].note_generale)
                min_idx = j;
        }
        swap(&e[min_idx], &e[i]);
    }
}

void triParOrdreAlphabetique(Etudiant e[], int taille)
{
    int min_idx;
    for(int i = 0; i < taille; i++)
    {
        min_idx = i;
        for(int j = i; j < taille; j++)
        {
            if(strcmp(strlwr(e[min_idx].nom), strlwr(e[j].nom)) > 0)
            {
                min_idx = j;
            }
        }
        swap(&e[i], &e[min_idx]);
    }
}

void triParStatus(Etudiant e[], int taille)
{

}

void afficherEtudiant(Etudiant e)
{
    printf("\n    ---------------     \n");
    printf("Id: %d\n", e.id);
    printf("Nom: %s\n", e.nom);
    printf("Prenom: %s\n", e.prenom);
    printf("Date de naissance: %d/%d/%d\n", e.dateNaissance.annee, e.dateNaissance.mois, e.dateNaissance.jour);
    printf("Departement: %s\n", e.departement);
    printf("Note generale: %.2f\n", e.note_generale);
    printf("\n    ---------------     \n");
}

void afficherTous(Etudiant e[], int taille)
{
    printf("La liste des etudiant est: \n");
    for(int i = 0; i < taille; i++)
        afficherEtudiant(e[i]);
}