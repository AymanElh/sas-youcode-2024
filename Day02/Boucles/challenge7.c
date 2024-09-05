#include <stdio.h>

int main()
{
    int n;
    printf("Entrer la valeur de n: ");
    scanf("%d", &n);

    int suite[n+1];
    for(int i = 0; i <= n; i++)
    {
        if(i == 0 || i == 1)
        {
            suite[0] = 0;
            suite[1] = 1;
        }
        else
        {
            suite[i] = suite[i-1] + suite[i-2];
        }

    }

    for(int i = 0; i <= n; i++)
    {
        printf("%d ", suite[i]);
    }
    return 0;
}