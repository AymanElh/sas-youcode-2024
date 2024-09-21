#include <stdio.h>

int main()
{
    int n;
    printf("Entrer la taille du tableau 1: ");
    scanf("%d", &n);
    int tab1[n];
    printf("Entrer les elements du tableau 1. \n");
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab1[i]);
    }

    int m;
    printf("Entrer la taille du tableau 2: ");
    scanf("%d", &m);
    int tab2[m];
    printf("Entrer les elements du tableau 2. \n");
    for(int i = 0; i < m; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab2[i]);
    }

    int T[n+m];
    int i = 0;
    while(i < n+m)
    {
        for(int j = 0; j < n; j++)
        {
            T[i] = tab1[i];
            i++;
        }
        for(int k = 0; k < m; k++)
        {
            T[i] = tab2[k];
            i++;
        }
        
    }

    printf("Les deux tableaux fusione: \n");
    for(int j = 0; j < n+m; j++)
    {
        printf("%d ", T[j]);
    }
    return 0;
}