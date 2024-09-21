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

    int max = tab[0];
    for(int i = 0; i < taille; i++)
    {
        if(max < tab[i])
            max = tab[i];
    }

    printf("Max: %d", max);
    return 0;
}