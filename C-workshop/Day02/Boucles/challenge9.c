#include <stdio.h>

int main()
{
    int x, y;
    printf("Entrer la base: ");
    scanf("%d", &x);
    printf("Entrer la puissance: ");
    scanf("%d", &y);

    int count = 0;
    int puissance = 1;
    while (count < y)
    {
        puissance *= x;
        count ++ ;
    }
    printf("x a la puissance y est: %d", puissance);
    return 0;
}