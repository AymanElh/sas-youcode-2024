#include <stdio.h>
#include <string.h>

void reverse(char mot[], int size);

int main()
{
    char name[10];
    int size = sizeof(name);
    printf("Name: ");
    scanf("%s", name);

    printf("%s", strrev(name));
    reverse(name, size);
    printf("%s\n", name);
    return 0;
}

void reverse(char mot[], int size)
{
    char temp;
    for(int i = 0, j = size-1; i < j; i++, j--)
    {
        temp = mot[i];
        mot[i] = mot[j];
        mot[j] = temp;
    }
}