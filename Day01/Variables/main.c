#include <stdio.h>

int main()
{
    int nbr_annnes, nbr_projets;
    float salaire;
    printf("Entrer le nombre d'annees d'experience: ");
    scanf("%d", &nbr_annnes);
    printf("Entrer le nombre de projet realise: ");
    scanf("%d", &nbr_projets);
    printf("Entrer votre salaire: ");
    scanf("%f", &salaire);

    float bonus = 0;

    if(nbr_annnes >= 10)
    {
        if(nbr_projets >= 15)
        {
            bonus = salaire * 0.3;
            printf("Tu as un bonus de 30 pourcent de votre salaire, ce qui donne: %.2f\n", bonus);
            printf("Salaire avec bonus est: %.2f", salaire+bonus);
        }
        else if(nbr_projets >= 10 && nbr_projets < 15)
        {
            bonus = salaire * 0.2;
            printf("Tu as un bonus de 20 pourcent de votre salaire, ce qui donne: %.2f\n", bonus);
            printf("Salaire avec bonus: %.2f", salaire+bonus);
        }
    }
    else
    {
        printf("Tu n'a pas acun bonus.");
    }
    return 0;
}