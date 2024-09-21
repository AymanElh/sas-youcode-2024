#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int number;
    printf("Entrer un nombre: ");
    scanf("%d", &number);   
     
    char nbr[10];
    sprintf(nbr, "%d", 23);
    strcpy(nbr, strrev(nbr));
    number = atoi(nbr);
    printf("%d", number);
    return 0;
}