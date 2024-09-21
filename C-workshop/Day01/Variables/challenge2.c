#include <stdio.h>

int main()
{
    float C, K;
    
    printf("Entrer la temperature en celsius: ");
    scanf("%f", &C);

    K = C + 273.15;

    printf("La temperature en Kelvin est: %.2f", K);
}