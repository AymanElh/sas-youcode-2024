#include <stdio.h>
#include <math.h>

#define pi 3.14

int main()
{
    float r;
    printf("Entrer le rayon du sphre: ");
    scanf("%f", &r);

    float volume = (4*pi*pow(r, 3)) / 3;

    printf("Volume du sphere est: %.2f", volume);
}