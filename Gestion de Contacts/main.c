#include "headers.h"


int main()
{
    contact contacts[SIZE];
    int taille = 0;

    char name[SIZE];
    while(1)
    {
        printf("\n***** MENU ******\n");
        printf("1. Ajouter un contact.\n");
        printf("2. Modifier un contact.\n");
        printf("3. Supprimer un contact.\n");
        printf("4. Afficher les contact.\n");
        printf("5. Exit.\n");

        int choix;
        printf("Entrer choix: ");
        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                ajouter_contact(contacts, &taille);
                break;
            case 2:
                modifier_contact(contacts, taille);
                break;
            case 3:
                printf("Entrer le nom du contact que vous voulez modifier: ");
                scanf(" %[^\n]", name);
                supprimer_contact(contacts, name, &taille);
                break;
            case 4:
                afficher(contacts, taille);
                break;
            case 5:
                exit(1);
            default:
                printf("Invalide choix, Ressayer.\n");
        }
    }
    return 0;
}


