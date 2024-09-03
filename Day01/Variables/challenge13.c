#include <stdio.h>

int main()
{
    int number;
    printf("Number: ");
    scanf("%d", &number);
    int r = 0, index = 0;
    int bin[20];
    while(number != 0)
    {
        r = number % 2;
        number = number / 2;
        bin[index] = r;
        index++;
    }

    for(int i = index-1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
    
    return 0;
}