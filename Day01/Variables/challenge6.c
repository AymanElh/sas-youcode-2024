#include <stdio.h>

int main()
{
    float a, b;

    printf("Entrer la valeur de a: ");
    scanf("%f", &a);
    printf("Entrer la valeur de b: ");
    scanf("%f", &b);

    printf("a + b = %.2f\n", a+b);
    printf("a - b = %.2f\n", a-b);
    printf("a x b = %.2f\n", a*b);
    if(b == 0)
        printf("La division par 0 est imposible.\n");
    else
        printf("a / b = %.2f\n", a/b);

    return 0;
}