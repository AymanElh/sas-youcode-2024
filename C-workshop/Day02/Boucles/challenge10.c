#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int size = sizeof(set) / sizeof(char);
    int n;
    printf("Entrer n: ");
    scanf("%d", &n);
    char password[n+1];
    srand(time(NULL));
    for(int i = 0; i <=n ; i++)
    {
        password[i] = set[rand() % size];
    }

    for(int i = 0; i <= n; i++)
    {
        printf("%c", password[i]);
    }
    return 0;
}