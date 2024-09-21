#include <stdio.h>

int main()
{
    int number;
    printf("Entrer un nombre: ");
    scanf("%d", &number);

    int sum = 0;
    for(int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", i, number, i*number);
        sum += (i*number);
    }
    printf("Sum: %d", sum);
    return 0;
}