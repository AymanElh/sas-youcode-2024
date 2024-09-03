#include <stdio.h>

int main()
{
    int taille;
    printf("Entrer la taille du tableau: ");
    scanf("%d", &taille);
    int tab[taille];
    printf("Entrer les elements du tableau. \n");
    for(int i = 0; i < taille; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab[i]);
    }

    int n, m;
    printf("Entrer la valeur a remplacer: ");
    scanf("%d", &n);
    printf("Entrer la nouvelle valeur: ");
    scanf("%d", &m);
    
    int exist = 0;
    for(int i = 0; i < taille; i++)
    {
        if(n == tab[i])
        {
            tab[i] = m;
            exist = 1;
        }
    }
    if(!exist)
    {
        printf("La valeur n'exit pas dans le tableau.\n");
        return 1;
    }

    printf("Le tableau apres remplacement.\n");
    for(int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}