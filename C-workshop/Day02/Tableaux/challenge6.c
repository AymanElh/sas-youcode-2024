#include <stdio.h>

int main()
{
    int taille;
    printf("Entrer la taille du tableau: ");
    scanf("%d", &taille);
    int tab[taille];
    int facteur;
    printf("Entrer le facteur: ");
    scanf("%d", &facteur);
    printf("Entrer les elements du tableau: \n");
    for(int i = 0; i < taille; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab[i]);
        tab[i] *= facteur;;
    }

    for(int i = 0; i < taille; i++)
    {
        printf("tab[%d] = %d\n", i+1, tab[i]);
    }
    return 0;
}