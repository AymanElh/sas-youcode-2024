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

    printf("Les elements paire du tableau.\n");
    for(int i = 0; i < taille; i++)
    {
        if(tab[i] % 2 == 0)
            printf("%d ",tab[i]);
    }
    printf("\n");
    printf("Les elements impaire du tableau.\n");
    for(int i = 0; i < taille; i++)
    {
        if(tab[i] % 2 == 1)
            printf("%d ",tab[i]);
    }
}