#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "etape.h"
#include "chargeTrajet.h"

int main()
{
    int choice = 1;
    char *nomEtapeACreer;
    char* nom;
    char* ville;
    char buffer[255];
    etape *listeDeEtape = NULL;

    printf("*** PLANIFICATEUR DE TRAJET ***\n\n");

    do
    {
        printf("Que souhaitez-vous faire?\n\n");
        printf("(1)     Afficher le trajet en cours\n");
        printf("(2)     Ajouter une etape\n");
        printf("(3)     Afficher la distance totale\n\n");
        printf("(autre) Quitter?\n");

        scanf("%d",&choice);

        /*if(choice == 1)
        {
            listeDeEtape = chargeTrajet();
            afficherTrajet(listeDeEtape);
        }
        else if(choice == 2)
        {
            insererEtape(listeDeEtape);
        }*/

        switch (choice)
        {
            case 1 :
                listeDeEtape = chargeTrajet();
                afficherTrajet(listeDeEtape);
                break;

            case 2 :
                listeDeEtape = chargeTrajet();
                insererEtape2(listeDeEtape);
                modif(listeDeEtape);
                break;

            case 3 :
                listeDeEtape = chargeTrajet();
                distanceTotale(listeDeEtape);
                break;

            case 4 :
                listeDeEtape = chargeTrajet();
                printf("Quelle ville ?");
                scanf("%s",&ville);
                suppr(listeDeEtape, ville);

            default : break;
        }
    }
    while (choice == 1 || choice == 2 || choice == 3);

    printf("CIAO !");

    return 0;
}
