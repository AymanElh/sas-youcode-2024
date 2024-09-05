#include <stdio.h>

int estPaire(int nbr);

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    
    if(estPaire(n))
        printf("Paire");
    else
        printf("Impaire");
    
    return 0;
}

int estPaire(int nbr)
{
    return nbr % 2 == 0;
}