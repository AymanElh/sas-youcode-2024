#include <stdio.h>

int somme(int a, int b);

int main()
{
    int n, m;
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);    
    printf("%d + %d = %d", n, m, somme(n, m));
    return 0;
}

int somme(int a, int b)
{
    return a+b;
}