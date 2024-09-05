#include <stdio.h>

int main()
{
    int nbr;
    printf("Entrer un nombre: ");
    scanf("%d", &nbr);

    int fact = 1;
    for(int i = 2; i <= nbr; i++)
    {
        fact = fact * i;
    }
    printf("%d! = %d", nbr, fact);
    return 0;
}