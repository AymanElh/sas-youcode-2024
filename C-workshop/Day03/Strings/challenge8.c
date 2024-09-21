#include <stdio.h>
#include <string.h>

void supprimer_spaces(char str[]);

int main()
{
    char str[20];
    printf("Entrer un chaine de caracteres: ");
    gets(str);

    supprimer_spaces(str);
    puts(str);

    return 0;
}

void supprimer_spaces(char str[])
{
    int x = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
        {
            for(int j = i; j < strlen(str); j++)
            {
                str[j] = str[j+1];
            }
            str[strlen(str)] = '\0';
        }
    }
}