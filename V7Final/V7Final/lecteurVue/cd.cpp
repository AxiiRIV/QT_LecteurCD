#include "cd.h"
Cd::Cd()
{
    this->nbTitres = 0;
    this->duree = 0;
    this->position = 1;
}
Cd::~Cd()
{

}

unsigned int Cd::getPosition()
{
    return position;
}

string Cd::getIntitule()
{
    return intitule;
}

string Cd::getPochette()
{
    return pochette;
}

string Cd::getGenre()
{
    return genre;
}

unsigned int Cd::getNbTitres()
{
    return nbTitres;
}

unsigned int Cd::getDuree()
{
    return duree;
}

Titre Cd::getTitre(unsigned int pIndice)
{
    return this->titres[pIndice];
}

Titre *Cd::getTitres()
{
    return this->titres;
}

void Cd::PasserSuivant()
{
    position++;
}

void Cd::PasserPrecedent()
{
    if (position > 1) {
        position--;
    }
    //juste au cas ou.... securité pour pas tomber dans un tire en psoition négatif.
}

void Cd::RetourDebut()
{
    position = 1;
}


void Cd::setIntitule(const string &pIntitule)
{
    intitule = pIntitule;
}

void Cd::setPochette(const string &pPochette)
{
    pochette = pPochette;
}

void Cd::setGenre(const string &pGenre)
{
    genre = pGenre;
}

void Cd::setNbTitres(unsigned int pNbTitres)
{
    nbTitres = pNbTitres;
}

void Cd::setDuree(unsigned int pDuree)
{
    duree = pDuree;
}

void Cd::ajouterTitre(const string &pIntitule, unsigned int pDuree, const string &pUrl)
{

    if (this->nbTitres < constantes::NB_MAX_TITRES)
    {

        this->titres[this->nbTitres] = Titre(pIntitule, pDuree, pUrl);
        this->nbTitres++;


        this->duree += pDuree;
    }
}

void Cd::enleverTitre(unsigned int pIndice)
{
    if (pIndice < this->nbTitres)
    {

        this->duree -= this->titres[pIndice].getDuree();


        for (unsigned int i = pIndice; i < this->nbTitres - 1; i++)
        {
            this->titres[i] = this->titres[i + 1];
        }


        this->nbTitres--;
    }
}
