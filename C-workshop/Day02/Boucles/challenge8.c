#include <stdio.h>

int main()
{
    int tab[5] = {2, 4, 7, 9, 10};
    int nbr;
    printf("Entrer le nombre a recherche: ");
    scanf("%d", &nbr);

    int exist = 0;
    int mil;
    int debut = 0, fin = 4;

    while(debut <= fin)
    {
        mil = (debut + fin) / 2;
        if(tab[mil] == nbr)
        {
            exist = 1;
            break;
        }
        else if (tab[mil] < nbr)
            debut = mil + 1;
        else
            fin = mil -1;
    }

    if(exist)
        printf("Le nombre est trouve et sa posistion est: %d", mil+1);
    else
        printf("Le nombre n'exist pas dans le tableaur.");
    return 0;
}