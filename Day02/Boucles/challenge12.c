#include <stdio.h>

int main()
{
    int taille;
    printf("Entrer la taille du tableau: ");
    scanf("%d", &taille);

    int tab[taille];
    printf("Saisir les elements du tableau.\n");
    for(int i = 0; i < taille; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &tab[i]);
    }

    int fin = taille, temp;
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < fin-1; j++)
        {
            if(tab[j] < tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
        fin--;
        
    }
    printf("Le tableau trie.\n");
    for(int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}