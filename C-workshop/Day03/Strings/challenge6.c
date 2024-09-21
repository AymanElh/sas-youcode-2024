#include <stdio.h>
#include <string.h>

int nbr_occurences(char str[], char c);

int main()
{
    char str[20];
    printf("Entrer un chaine de caractere: ");
    scanf("%[^\n]s", str);

    char c;
    printf("Entrer le caractere a rechercher: ");
    scanf(" %c", &c);
    
    printf("Le nombre d'occurences de %c est: %d", c, nbr_occurences(str, c));
    return 0;
}

int nbr_occurences(char str[], char c)
{
    int x = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == c)
            x++;
    }
    return x;
}