#include <stdio.h>

int main()
{
    float longeur, largeur;
    printf("Entrer la longeur de rectangle: ");
    scanf("%f", &longeur);
    printf("Entrer la largeur de rectangle: ");
    scanf("%f", &largeur);

    float surface = longeur * largeur;
    printf("Surface de rectangle est: %.2f", surface);
    return 0;
}