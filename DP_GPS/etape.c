#include "etape.h"
#include <stdlib.h>
#include <string.h>

etape* creerEtape(char *nom, int distance)
{
    etape *etapeCreation ;

    etapeCreation = malloc(sizeof(etape));
    etapeCreation->nom = malloc(sizeof(char) * strlen(nom));
    etapeCreation->distance = distance;
    strcpy(etapeCreation->nom, nom);
    etapeCreation->nextEtape = NULL;
    return etapeCreation;
}

void ajouterEtapeListe(etape *etapeAAjouter, etape *derniereEtapeDeLaListe)
{
    derniereEtapeDeLaListe->nextEtape = etapeAAjouter;
}

void insererEtape(etape *listeEtape)
{
    int i;
    etape *etapeAInserer = malloc(sizeof(etape));
    char *nomNouveau = malloc(sizeof(char)*255);
    char *nomAvant = malloc(sizeof(char)*255);
    int distanceAvant;
    int distanceApres;

    etapeAInserer = listeEtape;
    printf("Quel est le nom de la nouvelle etape?\n");
    scanf("%s",nomNouveau);
    printf("Quel est le nom de l'etape qui la precede?\n");
    scanf("%s",nomAvant);
    printf("Quelle est la distance en km avec la ville precedente?\n");
    scanf("%d",&distanceAvant);
    printf("Quelle est la distance en km avec la ville suivante?\n");
    scanf("%d",&distanceApres);

    while(strcmp(etapeAInserer->nom,nomAvant) != 0)
    {
        printf("%s\n",etapeAInserer->nom);
        etapeAInserer = etapeAInserer->nextEtape;
    }
}

void insererEtape2(etape *start)                // c'est un copier coller de votre fonction mais j'ai pas compris le while à la fin donc j'ai juste amménager la fin
{

    etape *etapeAInserer = malloc(sizeof(etape));
    char *nomNouveau = malloc(sizeof(char)*255);
    char *nomAvant = malloc(sizeof(char)*255);
    int distanceAvant;
    int distanceApres;

    etape *position = start->nextEtape;         // pour défiler la liste
    printf("Quel est le nom de la nouvelle etape?\n");
    scanf("%s",nomNouveau);
    printf("Quel est le nom de l'etape qui la precede?\n");
    scanf("%s",nomAvant);
    printf("Quelle est la distance en km avec la ville precedente?\n");
    scanf("%d",&distanceAvant);
    printf("Quelle est la distance en km avec la ville suivante?\n");
    scanf("%d",&distanceApres);


    while(strlen(position->nom) != strlen(nomAvant) )               // c'est du bidoullage parce que la condition  while ( position->nom != nomAvant) ne marchait jamais
    {
        position = position->nextEtape;             // pour balayer la chaine jusqu'à la ville concerné
    }

    etapeAInserer->distance = distanceAvant;            // on assigne les caractéristiques
    etapeAInserer->nom = nomNouveau;
    etapeAInserer->nextEtape = position->nextEtape;

    position->nextEtape = etapeAInserer;
    position = position->nextEtape;                             // c'est parceque on revient en arriere donc faut passer 2 structures....
    position = position->nextEtape;
    position->distance = distanceApres;
}

void suppr (etape *start, char* ville)           // pour supprimer une ville
{
    etape *position = start->nextEtape;         // pour défiler la liste


    while(strlen(position->nom) != strlen(ville) )               // c'est du bidoullage parce que la condition  while ( position->nom != ville) ne marchait jamais
    {
        position = position->nextEtape;             // pour balayer la chaine jusqu'à la ville concerné
    }
}


