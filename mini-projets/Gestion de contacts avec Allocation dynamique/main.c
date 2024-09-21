#include "headers.h"

int main()
{
    int nbr_contacts = 0;
    Contact *contacts = NULL;

    while(1)
    {
        printf("1. Ajouter un Contact.\n");
        printf("2. Ajouter plusieurs Contacts.\n");
        printf("3. Recherche un contact par Nom.\n");
        printf("4. Recherche un contact par son Identifiant.\n");
        printf("5. Modifier le nom d'un contact par son Identifiant.\n");
        printf("6. Modifier le numero d'un contact par son Identifiant.\n");
        printf("7. Modifier l'email d'un contact par son Identifiant");
        printf("8. Supprimer un contact par son Id.\n");
        printf("9. Supprimer un element par son nom.\n");
        printf("10. Trier les elements par id.\n");
        printf("11. Afficher tous.\n");
        printf("12. Quitter.\n");

        int choix;
        printf("Entrer voter choix: ");
        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                ajouterContact(&contacts, &nbr_contacts);
                printf("\n");
                break;
            case 2:
                {
                    int nbr;
                    printf("Entrer le nombre des contacts que vous voulez ajouter: ");
                    scanf("%d", &nbr);
                    ajouterPlusieursContacts(&contacts, nbr, &nbr_contacts);
                        printf("\n");
                    break;
                }
            case 3:
                {
                    char nom[20];
                    printf("Entrer le nom: ");
                    scanf(" %[^\n]", nom);
                    if(rechercheParNom(contacts, nom, nbr_contacts) == -1) {printf("Le contact n'existe pas.\n");}
                    else
                    {
                        printf("Le contact que vous recherche:\n");
                        afficherContact(contacts[rechercheParNom(contacts, nom, nbr_contacts)]);
                    }
                    printf("\n");
                    break;
                }
            case 4:
                {
                    int id;
                    printf("Entrer identifiant: ");
                    scanf("%d", &id);
                    if(rechercheParId(contacts, id, nbr_contacts) == -1) {printf("Le contact n'existe pas.\n");}
                    else
                    {
                        printf("Le contact que vous recherche:\n");
                        afficherContact(contacts[rechercheParId(contacts, id, nbr_contacts)]);
                    }
                    printf("\n");
                    break;
                }
            case 5:
                {
                    int id;
                    printf("Entrer identifiant: ");
                    scanf("%d", &id);
                    char nom[20];
                    printf("Entrer le nouveau nom: ");
                    scanf(" %[^\n]", nom);
                    modifierContactName(contacts, nom, id, nbr_contacts);
                    printf("\n");
                    break;
                }
            case 6:
                {
                    int id;
                    printf("Entrer identifiant: ");
                    scanf("%d", &id);
                    char numero[12];
                    printf("Entrer le nouveau numero: ");
                    scanf(" %[^\n]", numero);
                    modifierContactNumero(contacts, numero, id, nbr_contacts);
                    printf("\n");
                    break;
                }
            case 7:
                {
                    int id;
                    printf("Entrer identifiant: ");
                    scanf("%d", &id);
                    char email[50];
                    printf("Entrer le nouveau email: ");
                    scanf(" %[^\n]", email);
                    modifierContactName(contacts, email, id, nbr_contacts);
                    printf("\n");
                    break;
                }
            case 8:
                {
                    int id;
                    printf("Entrer l'identifiant: ");
                    scanf("%d", &id);
                    supprimerContactParId(&contacts, id, &nbr_contacts);
                    printf("\n");
                    break;
                }
            case 9:
                {
                    char name[20];
                    printf("Entrer le nom: ");
                    scanf(" %[^\n]", name);
                    supprimerContactParNom(&contacts, name, &nbr_contacts);
                    printf("\n");
                    break;
                }
            case 10:
                triContactsParId(contacts, nbr_contacts);
                printf("\n");
                break;
            // case 11:

            case 11:
                afficherTous(contacts, nbr_contacts);
                printf("\n");
                break;
            case 12:
                printf("Au revoire.\n");
                exit(1);

            default:
                printf("Invalide choix, Ressayer.\n");

            }
    }
    getchar();
    return 0;
}
