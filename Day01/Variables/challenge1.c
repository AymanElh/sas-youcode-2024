#include <stdio.h>

int main()
{
    int age;
    char nom[20];
    char prenom[20];
    char sexe[20];
    char email[50];

    printf("Entrer votre age: ");
    scanf("%d", &age);

    printf("Entrer votre prenom: ");
    scanf("%s", prenom);

    printf("Entrer votre nom: ");
    scanf("%s", nom);

    printf("Entrer votre sexe: ");
    scanf("%s", sexe);

    printf("Entrer votre email: ");
    scanf("%s", email);

    printf("\n");
    printf("Votre informations sont: \n");
    printf("Prenom: %s\n", prenom);
    printf("Nom: %s\n", nom);
    printf("Age: %d\n", age);
    printf("Sexe: %s\n", sexe);
    printf("Email: %s", email);

}