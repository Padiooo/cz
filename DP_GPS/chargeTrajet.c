#include "chargeTrajet.h"
#include <stdio.h>

etape* chargeTrajet()
{
    FILE *f;
    etape *listeEtape = NULL;
    etape *lastEtape = NULL;
    etape *currEtape = NULL;

    char *nom;
    int distance;
    int checkCloture = 1;

    nom = malloc(sizeof(char)*255);
    listeEtape = malloc(sizeof(etape));
    currEtape = listeEtape;

    f = fopen("trajetGPS.txt", "r");
    if( f == NULL)
    {
        printf("Echec d'ouverture du fichier\n");
    }
    else
        {
        printf("Succes ouverture du fichier\n");
        char line[255];
        memset(line, '\0', 255);
        while(fgets(line, 255, f))
        {
            sscanf(line,"%s %d\n", nom, &distance);
            lastEtape = creerEtape(nom, distance);
            ajouterEtapeListe(lastEtape, currEtape);
            currEtape = lastEtape;
        }
    }
    checkCloture = fclose(f);
    if( checkCloture == 0)
    {
        printf("Succes fermeture du fichier\n\n");
    }
    else
    {
        printf("Echec fermeture du fichier\n\n");
    }
    return listeEtape;
}

void modif (etape *start)
{
    FILE *f;
    etape *position = start->nextEtape;         // pour défiler la liste
    int checkCloture;

    f = fopen("trajetGPS.txt", "w");

    if( f == NULL)
    {
        printf("Echec d'ouverture du fichier\n");
    }
    else
    {
            printf("Succes ouverture du fichier\n");

        do
        {
            fprintf(f, "%s %i\n", position->nom, position->distance);
            position = position->nextEtape;
        } while (position != NULL);
    }
    checkCloture = fclose(f);
    if( checkCloture == 0)
    {
        printf("Succes fermeture du fichier\n\n");
    }
    else
    {
        printf("Echec fermeture du fichier\n\n");
    }
}
