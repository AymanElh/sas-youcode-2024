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

    int temp;
    for(int i = 0; i < taille; i++)
    {
        for(int j = i+1; j < taille; j++)
        {
            if(tab[i] < tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    printf("Le tableau trie par ordre croissante est: ");
    for(int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}