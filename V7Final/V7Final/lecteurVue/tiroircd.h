#ifndef TIROIRCD_H
#define TIROIRCD_H

#include <QObject>
#include "cd.h"
class LecteurCD;
class TiroirCD : public QObject
{
    Q_OBJECT
public:
    enum UnEtatOuverture {FERME, OUVERT};
    enum UnEtatOccupation {VIDE, OCCUPE};
    explicit TiroirCD(LecteurCD *pLecteur, QObject *parent = nullptr);
    virtual ~TiroirCD();

    // getters
    UnEtatOuverture getEtatOuverture();
    UnEtatOccupation getEtatOccupation();
    /* getter informant du contenu de l'attribut leCD :
       VIDE si leCD = nullptr, OCCUPE sinon */
    LecteurCD* getLeLecteurCD();
    Cd* getLeCD();

    // setters
    void ouvrir();
        // modifie etatOuverture : devient OUVERT
    void fermer();
        // modifie étatOuverture : devient FERME
    void insererCD(Cd *pCD);
        // met à jour leCD avec l'adresse de l'objet CD inséré
    void retirerCD();
        // met à jour leCD (nullptr)
    void setLeLecteurCD (LecteurCD *pLecteur)  ;
        // mémorise l'adresse du lecteur pour lui faire remonter des informations




private:
    Cd *leCD = nullptr;                 /* pointeur sur l'objet CD qui sera présent dans le tiroir
                                            // implémente la relation TiroirCD --> CD */
    UnEtatOuverture etatOuverture;      // FERME, OUVERT
    LecteurCD *leLecteurCD = nullptr;   /* pointeur vers le composé LecteurCD
                                            // implémente la relation TiroirCD -->LecteurCD
                                               nécessaire pour faire remonter des informations au lecteur */
};

#endif // TIROIRCD_H
