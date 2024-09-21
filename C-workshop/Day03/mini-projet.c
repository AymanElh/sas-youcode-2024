#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct contact
{
    char nom[50];
    char numero[12];
    char email[50];
}contact;

void ajouter_contact(contact c[], int *n);
int recherche_contact(contact c[], char name[], int n);
void modifier_contact(contact c[], char name[], int n);
void supprimer_contact(contact c[], char name[], int *n);
void afficher(contact c[], int n);


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
                printf("Entrer le nom du contact que vous voulez modifier: ");
                scanf(" %[^\n]", name);
                modifier_contact(contacts, name, taille);
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

int recherche_contact(contact c[], char name[], int n)
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

void modifier_contact(contact c[], char name[], int n)
{
    int index = recherche_contact(c, name, n);
    if(index == -1)
    {
        printf("Le contact n'exist pas.\n");
        return;
    }

    char numero[12], email[50];

    int choix;
    printf("    1. Modifier le numero.\n");
    printf("    2. Modifier l'email.\n");
    printf("Entrer votre choix: ");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1:
            printf("Entrer le nouveau numero: ");
            scanf(" %[^\n]", numero);

            strcpy(c[index].numero, numero);
            printf("Le numero a ete modifie.\n");
            break;
        case 2:
            printf("Entrer le nouveau email: ");
            scanf(" %[^\n]", email);

            strcpy(c[index].email, email);
            printf("L'email a ete modifie.\n");
            break;
        default:
            printf("Choix invalid.\n");
    }
}

void supprimer_contact(contact c[], char name[], int *n)
{
    int index = recherche_contact(c, name, *n);
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