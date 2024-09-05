#include <stdio.h>

int main()
{
    int sum = 0;
    printf("Entrer un liste de nombre.\n");
    int nbr, count = 0;
    while(1)
    {
        printf("Entrer un nombre: ");
        scanf("%d", &nbr);
        if(nbr == 0)
            break;
        count++;
        sum += nbr;
    }
    float moyenne = sum / count;
    printf("Moyene est: %.2f", moyenne);
    return 0;
}
