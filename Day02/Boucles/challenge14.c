#include <stdio.h>

int main()
{
    printf("1.Lundi.\n");
    printf("2Mardi.\n");
    printf("3.Mercredi.\n");
    printf("4.Jeudi.\n");
    printf("5.Vendredi.\n");
    printf("6.Samedi.\n");
    printf("7.Dimanche.\n");

    int choix;
    printf("Entrer votre choix: ");
    scanf("%d", &choix);

    for(int i = choix; i <= 7; i++)
    {
        switch(i)
        {
            case 1:
                printf("Lundi ");
                break;
            case 2:
                printf("Mardi ");
                break;
            case 3:
                printf("Mercredi ");
                break;
            case 4:
                printf("Jeudi ");
                break;
            case 5:
                printf("Vendredi ");
                break;
            case 6:
                printf("Samedi ");
                break;
            case 7:
                printf("Dimanche ");
                break;
        }
    }

    return 0;
}