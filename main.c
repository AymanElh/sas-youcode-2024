#include "headers.h"

int main()
{
    int nbr_etudiants = 0;
    Etudiant etudiants[MAX_STUDENTS];
    
    while(1)
    {
        Menu();
        int choix;
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch(choix)
        {
            Menu();
            int choix;
            printf("Entrer votre choix: ");
            scanf("%d", &choix);
            case 1:
            {
                int nbr;
                printf("Entrer le nombre des etudiant que vous voulez ajouter: ");
                scanf("%d", &nbr);
                ajouterEtudiants(etudiants, nbr, &nbr_etudiants);
                printf("\n");
                break;
            }
            case 2:
            {
                int id;
                printf("Entrer identifiant d'etudiant que vous voulez modifier: ");
                scanf("%d", &id);
                modifierEtudiant(etudiants, id, nbr_etudiants);
                printf("\n");
                break;
            }
            case 3:
            {
                int id;
                printf("Entrer identifiant d'etudiant que vous voulez supprimer: ");
                scanf("%d", &id);
                supprimerEtudiant(etudiants, id, &nbr_etudiants);
                printf("\n");
                break;
            }
            case 4:
            {
                int id;
                printf("Enter identifiant d'etudiant que vous voulez recherche: ");
                scanf("%d", &id);
                printf("L'etudiant que vous chercher est: \n");
                afficherEtudiant(etudiants[rechercheEtudiantParId(etudiants, id, nbr_etudiants)]);
                printf("\n");
                break;
            }
            case 5:
            {
                char nom[STRING_SIZE];
                printf("Enter identifiant d'etudiant que vous voulez recherche: ");
                scanf(" %[^\n]", nom);
                printf("L'etudiant que vous chercher est: \n");
                afficherEtudiant(etudiants[rechercheEtudiantParNom(etudiants, nom, nbr_etudiants)]);
                printf("\n");
                break;
            }
            case 6:
            {
                afficherEtudiantsInscritsParDep(etudiants, nbr_etudiants);
                printf("\n");
                break;
            }
            case 7:
            {
                printf("Moyenne generale de universite est: %.2f\n", moyenneGenerale(etudiants, nbr_etudiants));
                printf("\n");
                break;
            }
            case 8:
            {
                afficherMoyenneGeneraleParDep(etudiants, nbr_etudiants);
                break;
            }
            case 9:
            {
                printf("Statistiques: \n");
                printf("Nombre total des etudiants inscrits dans universite est: %d\n", nbr_etudiants);
                afficherNbrEtudiantsParDep(etudiants, nbr_etudiants);
                printf("\n");
                float seuil;
                printf("Entrer seuil: ");
                scanf("%f", &seuil);
                etudiantsSupSeuil(etudiants, seuil, nbr_etudiants);
                printf("\n");
                topTrois(etudiants, nbr_etudiants);
                printf("\n");
                afficherNbrEtudiantsReuissiParDep(etudiants, nbr_etudiants);
                printf("\n");
                break;
            }
            case 10:
            {
                triParMoyenneGenerale(etudiants, nbr_etudiants);
                printf("\n");
                break;
            }
            case 11:
            {
                triParOrdreAlphabetique(etudiants, nbr_etudiants);
                printf("\n");
                break;
            }
            case 12:
            {
                break;
            }
            case 13:
            {
                break;
            }
            case 14:
            {
                afficherTous(etudiants, nbr_etudiants);
                printf("\n");
                break;
            }
            case 15:
            {
                printf("Au revoir.\n");
                exit(1);
            }
            default:
                printf("Invalide choix, ressayer.\n");
        }
    }
    return 0;
}