#include <stdio.h>

int main()
{
    float c;
    printf("Entrer la temperature en Celsius: ");
    scanf("%f", &c);
    
    if(c < 0)
        printf("Solide");
    else if(c >= 0 && c < 100)
        printf("Liquide");
    else
        printf("Gaz");
    return 0;
}