#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

#define SIZE 1000
#define STRING_SIZE 50

int main()
{
    char titres[SIZE][STRING_SIZE];
    char auteurs[SIZE][STRING_SIZE];
    float prix[SIZE];
    int quantites[SIZE];
    int taille = 0;

    while(1)
    {
        printf("\n ****** MENU ******\n");
        printf("1. Ajouter un livre.\n");
        printf("2. Afficher\n");
        printf("3. Update quantity.\n");
        printf("4. Supprimer livre.\n");
        printf("5. Nombre total des livre dans le stock.\n");
        printf("6. Exit.\n\n");

        int choix;
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                ajouter_livre(titres, auteurs, prix, quantites, &taille);
                break;
            case 2:
                afficher(titres, auteurs, prix, quantites, taille);
                break;
            case 3:
                update_quantity(titres, quantites, taille);
                break;
            case 4:
                supprimer_livre(titres, auteurs, prix, quantites, &taille);
                break;
            case 5:
                printf("Nombre total des livres dans le stock: %d\n", nbr_total(quantites, taille));
                break;
            case 6:
                exit(1);
            default:
                printf("Invalide choix, ressayer.\n");

        }
    }

    return 0;
}

