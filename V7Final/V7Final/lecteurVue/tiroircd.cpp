#include "lecteurCD.h"
#include "tiroirCD.h"

#include <QDebug>

TiroirCD::TiroirCD(LecteurCD *pLecteur, QObject *parent)
    : QObject{parent}, leLecteurCD(pLecteur)
{
    qDebug() << "TiroirCD::Construction début :" << Qt::endl;
    retirerCD();        // initialise leCD
    fermer();           // initialise etatOuverture
    qDebug() << "TiroirCD::Construction fin : un tiroir a été construit VIDE et FERME" << Qt::endl;

    if (getLeLecteurCD()->getMonTiroirCD() == this)
    {
        qDebug() << "TiroirCD::Construction fin : liaison avec LecteurCD établie" << Qt::endl;
    }

    /*// 1. Création de l'objet CD
    //Cd *monCd = new Cd();// la on fait une variable locale... il vaut meix faire :
    leCD = new Cd();
    peuplerCD(leCD);



    // Affichage du contenu via qDebug()
    qDebug() << "========= CHARGEMENT DU CD =========";
    qDebug() << "Album :" << QString::fromStdString(leCD->getIntitule());
    qDebug() << "Genre :" << QString::fromStdString(leCD->getGenre());
    qDebug() << "Nombre de titres :" << leCD->getNbTitres();
    qDebug() << "Durée totale :" << leCD->getDuree() << "secondes";


    for (unsigned int i = 0; i < leCD->getNbTitres(); i++)
    {
        // recuperation de chaque titre pour l'
        Titre t = leCD->getTitre(i);
        qDebug() << "  Piste" << (i + 1) << ":"
                 << QString::fromStdString(t.getIntitule())
                 << "|" << t.getDuree() << "s";
    }*/
    etatOuverture = FERME;


}

TiroirCD::~TiroirCD()
{
    delete leCD;
    qDebug() << "TiroirCD::Destruction du tiroirCD après la destruction d'un éventuel CD" << Qt::endl;
}

// getters
//------------------------------
TiroirCD::UnEtatOuverture TiroirCD::getEtatOuverture() {
    return etatOuverture;
}

TiroirCD::UnEtatOccupation TiroirCD::getEtatOccupation() {
    return ((leCD==nullptr)?VIDE:OCCUPE);
}

LecteurCD *TiroirCD::getLeLecteurCD()
{
    return leLecteurCD;
}

Cd *TiroirCD::getLeCD()
{
    return leCD;
}

// setters
//------------------------------
void TiroirCD::ouvrir() {
    qDebug() << "TiroirCD::ouvrir()" << Qt::endl;
    etatOuverture = OUVERT;

}

void TiroirCD::fermer() {
    qDebug() << "TiroirCD::fermer()" << Qt::endl;
    etatOuverture = FERME;
}

void TiroirCD::insererCD(Cd *pCD) {
    leCD = pCD;
    qDebug() << "TiroirCD::insererCD()" << Qt::endl;
    if (getEtatOccupation() == OCCUPE)
    {
        qDebug() << "TiroirCD::insererCD() : leTiroirCD est OCCUPE, voici ses titres :" << Qt::endl;
        for (unsigned int i = 0; i < leCD->getNbTitres(); i++) {
            qDebug() << leCD->getTitre(i).getUrl() << Qt::endl;
        }
    }

}

void TiroirCD::retirerCD() {
    delete leCD;
    leCD = nullptr;
    qDebug() << "TiroirCD::retirerCD()" << Qt::endl;
}

void TiroirCD::setLeLecteurCD (LecteurCD *pLecteur)  {
    leLecteurCD = pLecteur;
}


