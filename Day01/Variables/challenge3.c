#include <stdio.h>

int main()
{
    float km, yards;
    
    printf("Entrer la distance en kilometre: ");
    scanf("%f", &km);

    yards = km * 1093.61;

    printf("La distance en yards est: %.2f", yards);
    return 0;
}