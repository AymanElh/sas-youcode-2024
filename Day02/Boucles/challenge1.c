#include <stdio.h>

int main()
{
    int nbr;
    printf("Entrer le nnombre: ");
    scanf("%d", &nbr);

    for(int i = 10; i >= 0; i--)
    {
        printf("%d x %d = %d\n", nbr, i, nbr*i);
    }
    return 0;
}