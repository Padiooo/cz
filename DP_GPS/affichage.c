#include "affichage.h"
#include <stdio.h>

void afficherEtape(etape *monEtape){

    printf("Etape : %s \nDistance : %d\n\n",
            monEtape->nom,
            monEtape->distance);
}

void afficherTrajet(etape *listeEtape)
{
    etape *etapeAAfficher = listeEtape->nextEtape;
    while(etapeAAfficher->nextEtape != NULL)
    {
        afficherEtape(etapeAAfficher);
        etapeAAfficher = etapeAAfficher->nextEtape;
    }
    afficherEtape(etapeAAfficher);
}

void distanceTotale(etape *start)
{
    etape *position = start->nextEtape;        // la où on est dans la chaine
    int distance = 0;                                           // pour stocker la distance

    while(position->nextEtape != NULL)
    {
        distance +=  position->distance;
        position = position->nextEtape;
    }
    printf("Le trajet total est de %i km\n\n", distance);
}
