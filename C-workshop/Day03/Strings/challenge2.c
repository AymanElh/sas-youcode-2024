#include <stdio.h>
#include <string.h>



int main()
{
    char string[50];
    printf("Entrer un phrase: ");
    scanf("%[^\n]s", string);
    int i;
    for(i = 0; string[i] != '\0'; i++);
    printf("Taille de cette chaine est: %d", i);
    return 0;
}

