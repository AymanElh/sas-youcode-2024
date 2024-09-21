#include <stdio.h>

int main()
{
    int number;
    printf("Number: ");
    scanf("%d", &number);
    
    int inverse = 0;
    inverse = inverse*10 + number % 10;
    number = number / 10;

    inverse = inverse*10 + number % 10;
    number = number / 10;

    inverse = inverse*10 + number % 10;
    number = number / 10;

    inverse = inverse*10 + number % 10;
    number = number / 10;

    printf("Inverse: %d", inverse);
    return 0;
}