#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, z1;
    printf("Entrer les cordonnes du 1ere point dans l'espace.\n");
    printf("x1: ");
    scanf("%f", &x1);
    printf("y1: ");
    scanf("%f", &y1);
    printf("z1: ");
    scanf("%f", &z1);

    float x2, y2, z2;
    printf("Entrer les cordonnes du 2eme point dans l'espace.\n");
    printf("x2: ");
    scanf("%f", &x2);
    printf("y2: ");
    scanf("%f", &y2);
    printf("z2: ");
    scanf("%f", &z2);

    float distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2));

    printf("Distance entre les deux points est: %.2f", distance);
    return 0;
}