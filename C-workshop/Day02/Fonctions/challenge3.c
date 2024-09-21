#include <stdio.h>

int max(int a, int b);
int min(int a, int b);

int main()
{
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("Max de %d et %d est: %d\n", a, b, max(a, b));
    printf("Min de %d et %d est: %d\n", a, b, min(a, b));
    return 0;
}

int max(int a, int b)
{
    return a > b ? a: b;
}

int min(int a, int b)
{
    return a < b? a : b;
}