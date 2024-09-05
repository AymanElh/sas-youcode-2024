#include <stdio.h>
#include <string.h>

void majiscules(char str[]);
void minuscules(char str[]);

int main()
{
    char str[20];
    printf("Entrer un chaine de caractere: ");
    scanf("%[^\n]s", str);

    minuscules(str);

    puts(str);
    return 0;
}

void majiscules(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = str[i] - 'a' + 65;
    }
}

void minuscules(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = str[i] - 'A' + 97;
    }
}