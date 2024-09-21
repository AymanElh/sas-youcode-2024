#include <stdio.h>

int main()
{
    int n;
    printf("Entrer la valeur de n: ");
    scanf("%d", &n);

    int i = 2;
    while(i <= n)
    {
        int estPremier = 1;
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                estPremier = 0;
                break;
            }
        }

        if(estPremier)
            printf("%d ", i);

        i++;
    }
    return 0;
}