#include "headers.h"


void ajouter_contact(contact c[], int *n)
{
    printf("\nEntrer les information de contact.\n");
    printf("Nom: ");
    scanf(" %[^\n]", c[*n].nom);
    printf("Numero: ");
    scanf(" %[^\n]", c[*n].numero);
    printf("Email: ");
    scanf(" %[^\n]", c[*n].email);
    printf("Le contact a ete ajouter avec success.\n");

    (*n)++;
}

int recherche_contact_name(contact c[], char name[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(strlwr(name), strlwr(c[i].nom)) == 0)
        {
            return i;
        }
    }
    return -1;
}

int recherche_contact_id(contact c[], int id, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(id == c[i].id)
            return i;
    }
    return -1;
}

void modifier_contact(contact c[], int n)
{
    printf("1. Rechercher par id.\n");
    printf("2. Rechercher par nom.\n");
    int index;
    int choix1;
    printf("Entrer votre choix: ");
    scanf("%d", &choix1);
    switch(choix1)
    {
        case 1:
        {
            int id;
            printf("Entrer id de contact: ");
            scanf("%d", &id);
            index = recherche_contact_id(c, id, n);
            break;
        }
        case 2:
        {
            char name[20];
            printf("Entrer le nom de contact: ");
            scanf(" %[^\n]", name);
            index = recherche_contact_name(c, name, n);
            break;
        }
        default:
            printf("Choix Invalide.\n");
    }
    if(index == -1)
    {
        printf("Le contact n'exist pas.\n");
        return;
    }

    int choix2;
    printf("    1. Modifier le numero.\n");
    printf("    2. Modifier l'email.\n");
    printf("Entrer votre choix: ");
    scanf("%d", &choix2);
    switch(choix2)
    {
        case 1:
        {
            char numero[12];   
            printf("Entrer le nouveau numero: ");
            scanf(" %[^\n]", numero);
            strcpy(c[index].numero, numero);
            printf("Le numero a ete modifie.\n");
            break;
        }
        case 2:
        {
            char email[50];
            printf("Entrer le nouveau email: ");
            scanf(" %[^\n]", email);

            strcpy(c[index].email, email);
            printf("L'email a ete modifie.\n");
            break;
        }
        default:
            printf("Choix invalid.\n");
    }
}

void supprimer_contact(contact c[], char name[], int *n)
{
    printf("1. Rechercher par id.\n");
    printf("2. Rechercher par nom.\n");
    int choix;
    printf("Entrer votre choix: ");
    scanf("%d", &choix);

    int index;
    switch(choix)
    {
        case 1:
        {
            int id;
            printf("Entrer id de contact: ");
            scanf("%d", &id);
            index = recherche_contact_id(c, id, *n);
            break;
        }
        case 2:
        {
            char name[20];
            printf("Entrer le nom de contact: ");
            scanf(" %[^\n]", name);
            index = recherche_contact_name(c, name, *n);
            break;
        }
        default:
            printf("Choix Invalide.\n");
    }
            
    if(index == -1)
    {
        printf("Le contact introvable.\n");
        return;
    }

    for(int i = index; i < *n; i++)
    {
        c[i] = c[i+1];
    }
    (*n) --;
    printf("Le contact est supprime avec success.\n");
}

void afficher(contact c[], int n)
{
    printf("\nLes contacts sont.\n");
    for(int i = 0; i < n; i++)
    {
        printf("Nom: %s\n", c[i].nom);
        printf("Email: %s\n", c[i].email);
        printf("Numero: %s\n", c[i].numero);
        printf("\n   ----------     \n");
    }
    printf("\n");
}
