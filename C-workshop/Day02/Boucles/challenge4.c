#include <stdio.h>

int main()
{
    int number;
    printf("Entrer un nombre: ");
    scanf("%d", &number);

    int inverse = 0;
    while(number != 0)
    {
        inverse = inverse*10 + number % 10;
        number = number / 10;
    }
    printf("Inverse: %d", inverse);
    return 0;
}