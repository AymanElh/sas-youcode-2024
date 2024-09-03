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
        printf("tab[%d] = ", i+1);
        scanf("%d", &tab[i]);
    }

    int min = tab[0];
    for(int i = 0; i < taille; i++)
    {
        if(min > tab[i])
            min = tab[i];
    }

    printf("Min: %d", min);
    return 0;
}