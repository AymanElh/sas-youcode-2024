#include <stdio.h>

int main()
{
    char string[20];
    printf("Entrer votre chaine de caractere: ");
    scanf("%[^\n]s", string);

    printf("%s", string);
    return 0;
}