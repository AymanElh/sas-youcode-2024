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
    printf("Entrer les nouveaux informations d'etudiant: \n");
    e[index] = saisieEtudiant();
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

void afficherMoyenneGeneraleParDep(Etudiant e[],int taille)
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
        if(strcmp(strlwr(e[i]), strlwr(dep)) == 0)
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

int nbrEtudiantReuissiParDep(Etudiant e[], char dep[], int taille)
{
    int nbr;
    for(int i = 0; i < taille; i++)
    {
        if(stcmp(strlwr(e[i].departement), strlwr(dep)) == 0 && e[i].note_generale >= 10)
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