#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

typedef struct etape etape;
struct etape{
    char *nom;
    int distance;
    etape *nextEtape;
};

etape* creerEtape(char *nom, int distance);
void ajouterEtapeListe(etape *etapeAAjouter, etape *derniereEtapeDeLaListe);
void insererEtape(etape *listeEtape);
void insererEtape2(etape *start);
void suppr(listeDeEtape, ville);            // supprimer une ville

#endif // PERSONNAGE_H_INCLUDED
