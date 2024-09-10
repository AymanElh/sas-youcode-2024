#include "headers.h"

int checkNumero(char num[])
{
    if(strlen(num) == 10 && num[0] == '0' && (num[1] == '6' || num[1] == '7' || num[1] == '5'))
        return 1;
    
    return 0;
}

Contact saisieContact()
{
    Contact c;
    printf("Identifiant: ");
    scanf("%d", &c.id);
    printf("Nom: ");
    scanf(" %[^\n]", c.nom);
    c.nom[strcspn(c.nom, "\n")] = '\0';
    printf("Numero (06XXXXXXXX) ou (07XXXXXXXX): ");
    while(scanf(" %[^\n]", c.numero) != 1 || checkNumero(c.numero) == 0)
    {
        printf("Numero invalide, ressayer: ");
    }
    c.numero[10] = '\0';
    printf("Email: ");
    scanf(" %[^\n]", c.email);
    c.nom[strcspn(c.email, "\n")] = '\0';

    return c;
}

void ajouterContact(Contact **c, int *taille)
{
    *c = realloc(*c, (*taille + 1) * sizeof(Contact));
    if(*c == NULL)
    {
        printf("Erreur d'allocation de memoire.\n");
        exit(1);
    }
    (*c)[*taille] = saisieContact();
    (*taille) ++;
    printf("Le contact est ajoute avec success.\n");
    printf("\n");
}

void ajouterPlusieursContacts(Contact **c, int nbr, int *taille)
{
    printf("Entrer les contacts: \n");
    for(int i = 0; i < nbr; i++)
    {
        printf("Contact %d: \n", i+1);
        ajouterContact(c, taille);
    }
}

int rechercheParId(Contact *c, int id, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        if(c[i].id == id)
            return i;
    }
    return -1;
}

int rechercheParNom(Contact *c, char nom[], int taille)
{
    for(int i = 0; i < taille; i++)
    {
        if(strcmp(strlwr(c[i].nom), strlwr(nom)) == 0)
            return i;
    }
    return -1;
}

void modifierContactName(Contact *c, char nom[], int id, int taille)
{
    int index = rechercheParId(c, id, taille);
    if(index == -1)
    {
        printf("Le contact n'existe pas dans la liste.\n");
        return;
    }
    strcpy(c[index].nom, nom);
    printf("Le nom a ete modifie.\n");
    printf("\n");
}

void modifierContactNumero(Contact *c, char numero[], int id, int taille)
{
    int index = rechercheParId(c, id, taille);
    if(index == -1)
    {
        printf("Le contact n'existe pas.\n");
        return;
    }
    strcpy(c[index].numero, numero);
    printf("Le numero a ete modifier.\n");
    printf("\n");
}

void modifierContactEmail(Contact *c, char email[], int id, int taille)
{
    int index = rechercheParId(c, id, taille);
    if(index == -1)
    {
        printf("Le contact n'existe pas.\n");
        return;
    }
    strcpy(c[index].email, email);
    printf("L'email a ete modifier.\n");
    printf("\n");
}

void supprimerContactParId(Contact **c, int id, int *taille)
{
    int index = rechercheParId(*c, id, *taille);
    if(index == -1)
    {
        printf("Le contact n'existe pas.\n");
        return;
    }
    for(int i = 0; i < *taille; i++)
    {
        *c[i] = *c[i+1];
    }

    (*taille) --;
    Contact *new_array = realloc(*c, (*taille) * sizeof(Contact));
    if(new_array == NULL)
    {
        printf("Erreur d'allocation dynamique de la memoire.\n");
        exit(1);
    }
    *c = new_array;
}

void supprimerContactParNom(Contact **c, char name[], int *taille)
{
    int index = rechercheParNom(*c, name, *taille);
    if(index == -1)
    {
        printf("Le contact n'existe pas.\n");
        return;
    }
    for(int i = 0; i < *taille; i++)
    {
        *c[i] = *c[i+1];
    }

    (*taille) --;
    Contact *new_array = realloc(*c, (*taille) * sizeof(Contact));
    if(new_array == NULL)
    {
        printf("Erreur d'allocation dynamique de la memoire.\n");
        exit(1);
    }
    *c = new_array;
}

// Swap two elements on array of type contact 
void swap(Contact *a, Contact *b)
{
    Contact *temp = a;
    a = b;
    b = temp;
}

// Selection sort
void triContactsParId(Contact *c, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < taille; j++)
        {
            if(c[min_idx].id > c[j].id)
                min_idx = j;
        }
        swap(&c[i], &c[min_idx]);
    }
}

void afficherContact(Contact c)
{
    printf("Identifiant: %d\n", c.id);
    printf("Nom: %s\n", c.nom);
    printf("Numero: %s\n", c.numero);
    printf("Email: %s\n", c.email);
}

void afficherTous(Contact *c, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        printf("   -----------      \n");
        afficherContact(c[i]);
        printf("   -----------      \n");
    }
    printf("\n");
}