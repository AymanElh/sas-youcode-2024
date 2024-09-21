#include <stdio.h>

int Finobacci(int n);

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("La %d eme terme de la suite de fibonacci est: %d\n", n, Finobacci(n));
    return 0;
}

int Finobacci(int n)
{
    int F;
    if(n == 0)
        F = 0;
    else if(n == 1)
        F = 1;
    else
        F = Finobacci(n-1) + Finobacci(n-2);
    
    return F;
}