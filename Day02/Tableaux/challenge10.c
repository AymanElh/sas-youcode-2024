#include <stdio.h>

int main()
{
    int taille;
    printf("Entrer la taille du tableau: ");
    scanf("%d", &taille);
    int tab[taille];
    printf("Entrer les elements du tableau: \n");
    for(int i = 0; i < taille; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab[i]);
    }

    int nbr;
    printf("Entrer l'element recherche: ");
    scanf("%d", &nbr);
    int exist = 0;
    for(int i = 0; i < taille; i++)
    {
        if(nbr == tab[i])
            exist = 1;
    }

    if(exist)
        printf("L'element %d est present dans le tableau.\n", nbr);
    else 
        printf("L'element %d n'exist pas dans le tableau.\n", nbr);

    return 0;
}