#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c;

    printf("Entrer la valeur de a: ");
    scanf("%f", &a);
    printf("Entrer la valeur de b: ");
    scanf("%f", &b);
    printf("Entrer la valeur de c: ");
    scanf("%f", &c);

    float moy = pow(a*b*c, 0.333333333);

    printf("Le moyene geometrique est %.2f", moy);
    return 0;
}