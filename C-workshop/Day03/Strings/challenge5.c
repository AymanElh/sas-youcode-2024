#include <stdio.h>
#include <string.h>

void reverse_string(char *str);

int main()
{
    char str[20];
    printf("Entrer un chaine: ");
    scanf("%[^\n]", str);

    reverse_string(str);
    puts(str);
    return 0;
}

void reverse_string(char *str)
{
    char temp;
    int length = strlen(str);
    for(int i = 0, j = length-1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}