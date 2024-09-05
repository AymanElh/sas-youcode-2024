#include <stdio.h>

typedef struct livre
{
    char titre[20];
    char auteur[20];
    int annee;
}livre;

livre initialiser();
void afficher(livre l);

int main()
{
    livre l1 = initialiser();
    afficher(l1);
    return 0;
}

livre initialiser()
{
    livre l;
    printf("Entrer le nom de livre: ");
    scanf(" %[^\n]", l.titre);
    printf("Entrer l'auteur de livre: ");
    scanf(" %[^\n]", &l.auteur);
    printf("Entrer annee: ");
    scanf("%d", &l.annee);

    return l;
}

void afficher(livre l)
{
    printf("Les information de livre: \n");
    printf("Titre: %s\n", l.titre);
    printf("Auteur: %s\n", l.auteur);
    printf("Annee: %d\n", l.annee);
}