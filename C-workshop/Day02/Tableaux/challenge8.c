#include <stdio.h>


int main()
{
    int taille;
    printf("Entrer la taille du tableau: ");
    scanf("%d", &taille);
    int tab[taille];
    int tab1[taille];
    printf("Entrer les elements du tableau: \n");
    for(int i = 0; i < taille; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab[i]);
        tab1[i] = tab[i];
    }

    for(int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    for(int i = 0; i < taille; i++)
    {
        printf("%d ", tab1[i]);
    }

    return 0;
}