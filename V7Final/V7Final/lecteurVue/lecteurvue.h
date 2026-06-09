#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "LecteurCD.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LecteurVue;
}
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(LecteurCD* pLecteur,QWidget *parent = nullptr);
    ~LecteurVue();

public:
    // Méthode de mise à jour d'interface
    void majInterfaceMarche();
    void majInterfaceArret();
    void majInterfaceLecturePause(string pLabel);
    void ordreMajControlesTiroirEtLecture(LecteurCD::UnEtat pEtat);
    void ordreMajInfosTitreEnCours(string pIntitule = "-", int pRang = constantes::PAS_DE_TITRE);
    void ordreMajDureeTitreEnCours(int pDuree);
    void ordreMajinfosCD(string pIntitule = "-", string pPochette = "-", string pGenre = "-", int pDuree = 0, int pNbTitres = 0);
    void ordreMajProgression(int pPosition);
    void ordreMajControlesActivationDesactivationSon (bool pSonActif);
    void ordreMajVolume(int pVolume);
    void ordreOuvertureDialogue(QSqlQueryModel* pModeleRequete, int& pIdCD);
    // Ouverture d'une fenêtre de dialogue affichant le contenu de *pModeleRequete
    // Il s'agit de la liste des CDs disponibles dans la Base de données
    // Retourne dans pIdCD l'identifiant (>0) en Base de données du CD choisi, ou 0 si aucun CD n'a été choisi

private slots:
    void demanderPauseOuPlay(); //met en pause/play
    void demanderArreter();
    void demanderSuivant();
    void demanderPrecedent();
    void demanderAuto();
    void demanderBoucle();
    void demanderAleatoire();
    void demanderOuvrirTiroir();
    void demanderFermerTiroir();
    void demanderInsertionCD(); //pour faire comme ci on insserait un cd...
    void demanderRetraitCD(); //pour faire comme ci on insserait un cd...


    /*======================================
     * AJOUT MANON 08/05/26
     * ===================================*/
    void demanderBasculerOnOff(bool pAllume); //réutilisation du concept de Vue, Presentation, Modele

    //au niveaux du son :
    void demanderChangervolume(int pVolume);
    void demanderActiverSon();
    void demanderDesactiverSon();



private:
    Ui::LecteurVue *ui;
    LecteurCD  *leLecteur;
    Cd *leCd;
    Dialog *dlg; // Pointeur vers la fenêtre dialogue modale
};
#endif // LECTEURVUE_H
