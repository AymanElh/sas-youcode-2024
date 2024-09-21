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
    
    int sum = 0;
    float moy;
    for(int i = 0; i < taille; i++)
    {
        sum += tab[i];
    }
    moy = sum / taille;
    printf("Moyene des elements est: %.2f", moy);
}