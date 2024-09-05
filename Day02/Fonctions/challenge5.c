#include <stdio.h>

int factoriel(int p);

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("%d! = %d", n, factoriel(n));
    return 0;
}

int factoriel(int p)
{
    int f = 1;
    if(p == 0 || p == 1)
        f = 1;
    else
        f = p * factoriel(p-1);
    return f;
}