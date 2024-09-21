#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Entrer la valeur de a: ");
    scanf("%d", &a);
    printf("Entrer la valeur de b: ");
    scanf("%d", &b);
    printf("Entrer la valeur de c: ");
    scanf("%d", &c);

    float moy = ((a*2) + (b*3) + (c*5)) / 10;

    printf("La moyenne pondere est: %.2f", moy);
}