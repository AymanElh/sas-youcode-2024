#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[20];
    printf("Entrer la chaine 1: ");
    gets(str1);
    
    char str2[20];
    printf("Entrer la chaine 2: ");
    gets(str2);

    int n = strlen(str1) ;
    int m = strlen(str2);
    
    printf("%d %d\n", n, m);

    int len = n+m+1;
    char str[len];

    int i = 0;  

    for(int j = 0; j < n; j++)
    {
        str[i] = str1[j];
        i++;
    }
    for(int k = 0; k < m; k++)
    {
        str[i] = str2[k];
        i++;
    }
    str[len] = '\0';
    puts(str);
    puts(strcat(str1, str2));
    return 0;
}