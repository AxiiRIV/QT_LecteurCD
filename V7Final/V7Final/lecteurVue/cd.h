#ifndef CD_H
#define CD_H
#include <string>
using namespace std;
#include "titre.h"
#include "declarationsCommunes.h"
#include "database.h"

class Cd
{
    public:
    Cd ();
    ~Cd();

    // getters
    unsigned int getPosition();
    string getIntitule();
    string getPochette();
    string getGenre();
    string getTitre();
    unsigned int getNbTitres();
    unsigned int getDuree();
    Titre getTitre (unsigned int pIndice);
    // Retourne le titre situé au rang pIndice (qui démarre à 0)
    Titre *getTitres(); // retourne l'ensemble des titres du CD

    // setters
    void PasserSuivant();
    void PasserPrecedent();
    void RetourDebut();
    void setIntitule (const string& pIntitule);
    void setPochette(const string& pPochette);
    void setGenre(const string& pGenre);
    void setNbTitres (unsigned int pNbTitres) ;
    void setDuree (unsigned int pDuree);

    // pour peupler/dépeupler le CD qui sera lu par le lecteur
    void ajouterTitre (const string& pIntitule, unsigned int pDuree, const string& pUrl);
    /* ajoute un titre à la liste des titres du CD
       et met à jour nbTitres*/
    void enleverTitre (unsigned int pIndice);
    /* enlève le titre situé à l'indice pIndice
       et met à jour nbTitres */

    private:
        unsigned int position;   // position du titres dans le CD
        string intitule ;             // intitulé du CD
        string pochette ;             // url vers photo de la pochette
        string genre;
        unsigned int nbTitres = 0;    // nbre de titres = morceaux musicaux contenus dans le CD
        unsigned int duree ;        // durée totale du CD, en secondes
        Titre titres[constantes::NB_MAX_TITRES];   // l'ensemble des titres composants le CD : un tableau de titres
};

#endif // CD_H

