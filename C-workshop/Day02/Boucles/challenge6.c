#include <stdio.h>

int main()
{
    int nbr;
    printf("Entrer un nombre: ");
    scanf("%d", &nbr);

    for(int i = 1; i <= nbr; i++)
    {
        if(nbr % i == 0)
            printf("%d ", i);
    }
    return 0;
}