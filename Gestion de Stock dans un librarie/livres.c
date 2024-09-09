#include "headers.h"



void ajouter_livre(char titres[][STRING_SIZE], char auteurs[][STRING_SIZE], float prix[], int quantites[], int *n)
{
    printf("Entrer les informations de livre %d\n", (*n)+1);
    printf("Titre: ");
    scanf(" %[^\n]", titres[*n]);
    printf("Auteur: ");
    scanf(" %[^\n]", auteurs[*n]);
    printf("Prix: ");
    scanf("%f", &prix[*n]);
    printf("Quantite: ");
    scanf("%d", &quantites[*n]);

    (*n)++;
}

void afficher(char titres[][STRING_SIZE], char auteurs[][STRING_SIZE], float prix[], int quantites[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\nLes information de livre %d\n", i + 1);
        printf("Titre: %s\n", titres[i]);
        printf("Auteur: %s\n", auteurs[i]);
        printf("Prix: %.2f\n", prix[i]);
        printf("Quantite: %d\n", quantites[i]);
    }
    printf("\n");
}

int recherche_livre(char titres[][STRING_SIZE], char titre[STRING_SIZE], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strlwr(titre), strlwr(titres[i])) == 0)
        {
            return i;
        }
    }
    return -1;
}

void update_quantity(char titres[][STRING_SIZE], int quantities[], int n)
{
    char titre[STRING_SIZE];
    printf("Entrer le titre livre que vous voulez modifier: ");
    scanf(" %[^\n]", titre);
    int index = recherche_livre(titres, titre, n);
    if(index == -1)
    {
        printf("Le livre n'existe pas dans la bib.\n");
        return;
    }
    int quantity;
    printf("Entrer la quantite: ");
    scanf("%d", &quantity);

    quantities[index] = quantity;
    printf("La quantite a ete modifie.\n");
}

void supprimer_livre(char titres[][STRING_SIZE], char auteurs[][STRING_SIZE], float prix[], int quantites[], int *n)
{
    char titre[STRING_SIZE];
    printf("Entrer le titre de livre que vous voulez supprimer: ");
    scanf(" %[^\n]", titre);
    int index = recherche_livre(titres, titre, *n);
    if(index == -1)
    {
        printf("Le livre n'existe pas.\n");
        return;
    }

    for(int i = index; i < (*n) - 1; i++)
    {
        strcpy(titres[i], titres[i+1]);
        strcpy(auteurs[i], auteurs[i+1]);
        prix[i] = prix[i+1];
        quantites[i] = quantites[i+1];
    }
    (*n) --;
    printf("Le projet supprimer avec succees.\n");
}

int nbr_total(int quantities[], int n)
{
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        total += quantities[i];
    }
    return total;
}
