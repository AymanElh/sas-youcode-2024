#include <stdio.h>

int multiplication(int a, int b);


int main()
{
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
}

int multiplication(int a, int b)
{
    return a*b;
}