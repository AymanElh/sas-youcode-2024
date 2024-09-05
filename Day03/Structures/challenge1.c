#include <stdio.h>

typedef struct persone
{
    int age;
    char prenom[20];
    char nom[20];
}persone;

int main()
{
    persone p1 = {20, "ayman", "elhamioui"};
    printf("Persone1. age: %d, prenom: %s, nom: %s\n", p1.age, p1.prenom, p1.nom);
    return 0;
}