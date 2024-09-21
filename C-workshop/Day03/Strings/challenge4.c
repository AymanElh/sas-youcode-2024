#include <stdio.h>
#include <string.h>

int compare(char str1[], char str2[]);

int main()
{
    char str1[20];
    char str2[20];
    printf("Entrer la chaine 1: ");
    gets(str1);
    printf("Entrer la chaine 2: ");
    gets(str2);

    if(compare(str1, str2))
        printf("Les deux chaines sont identiques.");
    else
        printf("Les deux chaines sont differents.");
    return 0;
}

int compare(char str1[], char str2[])
{
    if(strlen(str1) != strlen(str2))
        return 0;

    for(int i = 0; i < strlen(str1); i++)
    {
        if(str1[i] != str2[i])
            return 0;
    }
    return 1;
}