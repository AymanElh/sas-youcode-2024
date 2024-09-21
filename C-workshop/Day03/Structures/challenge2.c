#include <stdio.h>

typedef struct etudiant
{ 
    char prenom[20];
    char nom[20];
    int notes[5];
}etudiant;

int main()
{
    etudiant e1 = {"ayman", "elhamioui", {12, 11, 18, 19, 14}};

    printf("Etudiant 1.\n");
    printf("Prenom: %s\n", e1.prenom);
    printf("Nom: %s\n", e1.nom);
    printf("Notes: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", e1.notes[i]);
    }
    return 0;
}