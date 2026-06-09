#ifndef LECTEURCD_H
#define LECTEURCD_H

#include <QObject>
#include "tiroircd.h"
#include "cellule.h"
#include "sortieson.h"
#include "dialog.h"


using namespace std;

class LecteurVue;
class LecteurCD : public QObject
{
    Q_OBJECT // marco pour utilisez des signaux/slots plus tard

public:
     LecteurCD(QObject *parent = nullptr);
    ~LecteurCD(); // destructeur

    // Déclaration type
    enum UnEtat {LECTURE, PAUSE,VIDE_ARRET,OUVERT_ARRET,CHARGE_ARRET};
    // va donner les differents états possible pour l'état du lecteur cd (Eteint ou allumé)
    // on a rajouté deux nouveaux états LECTURE et ARRET pour faire des choses avec la lecture du cd.
    //pour pouvoir lire les cd. comme un vrai lecteur.
    enum UnEtatModeLecture {MODE_AUTO, MODE_BOUCLE,MODE_ALEATOIRE};
    enum UnIndicateurDePeuplement {BD_NOK_CD_OK, BD_OK_CD_NOK, BD_OK_CD_OK};
    /* BD_NOK_CD_OK    : la BD est inaccessible, le CD a été peuplé 'en dur'
     * BD_OK_CD_NOK     : la BD est accessible mais aucun CD choisi
     * BD_OK_CD_OK        : la BD est accessible et un CD a été choisi
     */

    // getters
    LecteurVue* getVue();
    UnEtat getEtat();
    TiroirCD* getMonTiroirCD();
    Cellule* getLaCellule(); // sert à recupérer la Cellule pour savoir si la cellule est bien connectée.
    SortieSon* getLeSon();
    UnEtatModeLecture getEtatModeLecture();

    // getters pour l'action_D
    int getRangTitreEnCours();
    Titre* getTitreEnCours();

    // setter
    void setVue(LecteurVue* pVue);
    //void setTiroirCD(TiroirCD& pTiroirCD);
    void setEtat(UnEtat pEtat);
    void setEtatModeLecture(UnEtatModeLecture pEtatModeLecture);

    // setters pour action_D
    void setTitreEnCours(Titre* pTitreEnCours);
    void setRangTitreEnCours(int pRangTitreEnCours);

    // explicit LecteurCD(UnEtat pEtat = ETEINT, QObject *parent = nullptr);
    //met par defaut le lecteur eteint.


    void allumer();//allumer le lecteur
    void eteindre(); //etient le lecteur

    //actions des bouttons de la barres des actions sur la ecture :
    void arreter(); //arrete la lecture totalement et met à 0 la lecture du cd.
    void pauseOuLire();
    void modeBoucle(); //mode boucle
    void modeAuto(); //mode auto
    void modeAleatoire(); //mode aléatoire.
    void precedent();
    void suivant();

    //action de chargemant du lecteur avec l'objet cd :
    void ouvrirTiroir();
    // va simplement rendre possible l'action d'incerer le cd ou de le retirer et de le fermer aussi....

    void insererCd(); // mettra le cd (objet cd) dans le lecteru pour etre lu.
    void retirerCd(); // retire le cd.

    void fermerTiroir(); // ferme le tiroir du lecteur et là il y aura deux possibilités :
    //si un cd est présent et contien des titres, il va tout faire apparaitre et modifier les QLabels de l'aplication.
    //si non, il indiquera que le cd est vide, non lu, ou que le tiroir est vide.

    // Méthode en rapport avec le son
    void activerSon(); //permet d'activer le son et avoir acces au slide button.
    void desactiverSon(); //rend le slide innaccessible et coupe le son des hautparleurs.
    void changerVolume(int); //sera utilisé pour changer le volume

    // méthode pour capter que le player change
    void capterCellulePositionChanged(int pPosition);

    // méthode pour peupler le CD
    void peuplerCD(Cd *pCD, UnIndicateurDePeuplement& pIndicPeuplement);
    void peuplerCD(Cd *pCD);
private:
    LecteurVue *laVue; // Pointeur vers la vue donc la classe LecteurVue
    TiroirCD monTiroirCD; // Un des éléments du lecteur CD pour lire le CD.
    Cellule laCellule; // Un des éléments du lecteur CD pour l'allumer et l'éteindre
    SortieSon leSon; // Un des éléments du lecteur CD pour gérer le son

    UnEtat etatLecteur;
    //à utiliser pour déclarer l'etat du lecteur pour permettre l'utilisation des services de ce dernier

    //etats des modes de lectures : utiles pour les 3 modes possibles (boucle, sequentiel et aléatoire)
    UnEtatModeLecture etatModeLecture;

    std::string DOSSIER_MEDIAS = "I:/BUT_INFO/CDs/";     // lieu dépôt des fichiers médias
    // F:/iut/BUT1/S2/S2.01_dev-application/CDs/
    // attributs pour la diffusion et l'affichage du titre en cours action_D
    int rangTitreEnCours;
    Titre* titreEnCours;

private:
    // Méthode privée, sous-programmes de peuplerCD(Cd* pCD, UnIndicateurDePeuplement& pIndicPeuplement)

    void initialiserInfosCD(Cd* pCD, QSqlQuery* pQuery);
    /* renseigne les attributs de pCD (intitule, genre, dureeTotale, pochette, nbTitres
     * avec les colonnes 1 à 4 de (*pQuery))  */

    void ajouterInfosTitres(Cd* pCD, QSqlQuery* pQuery);
    /* Ajoute à (*pCD) les titres contenus dans (*pQuery)
     * 1 ligne = 1 titre ; colonne 0 = intitule  ; colonne 1 = duree ;  colonne 2 = url vers media */


signals :
    void ChangerEtatLecteur(LecteurCD::UnEtat nouvelEtat);
    // Le signal pour prévenir la vue que l'etat change si non ça crache....

};

#endif // LECTEURCD_H
