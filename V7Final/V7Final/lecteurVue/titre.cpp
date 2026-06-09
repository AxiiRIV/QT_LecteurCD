#include "titre.h"
#include <QDebug>

Titre::Titre() {}

Titre::Titre(const string& pIntitule, unsigned short int pDuree, const string& pUrl)
    : intitule(pIntitule), duree(pDuree), url(pUrl){}

Titre::~Titre()
{ qDebug() << "Destruction du titre " << Qt::endl;}

// getters
//------------------------------
std::string Titre::getIntitule() const
{
    qDebug() << "recupération du titre :"<< intitule;
    return intitule;
}

unsigned short Titre::getDuree() const
{
    qDebug() << "recupération de la durée :"<< duree;
    return duree;
}

std::string Titre::getUrl() const
{
    qDebug() << "recupération de l'URL:"<< url;

    return url;
}

// setters
//------------------------------
void Titre::setIntitule(const string &pIntitule)
{
    qDebug() << "Modification de l'intitulé:"<< pIntitule;

    intitule = pIntitule;

}

void Titre::setDuree(unsigned short pDuree)
{
    qDebug() << "Modification de la durée:"<< pDuree;

    duree = pDuree;
}

void Titre::setUrl(const string &pUrl)
{
    qDebug() << "Modification de l'url :"<< pUrl;

    url = pUrl;
}
