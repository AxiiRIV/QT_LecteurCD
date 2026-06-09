#include "lecteurvue.h"
#include "LecteurCD.h"
#include "ui_lecteurvue.h"
#include <QPixmap>
#include <QTime>
#include <cd.h>//on en a besoin pour recupérer les données du cd....



LecteurVue::LecteurVue(LecteurCD* pLecteur,QWidget *parent)
    : QMainWindow(parent),leLecteur(pLecteur), ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->bOnOff, SIGNAL(toggled(bool)), this, SLOT(demanderBasculerOnOff(bool)));
    QObject:: connect(ui->bAleatoire, SIGNAL(clicked()), this, SLOT(demanderAleatoire()));
    QObject:: connect(ui->bAuto, SIGNAL(clicked()),this,SLOT(demanderAuto()));
    QObject:: connect(ui->bPause, SIGNAL(clicked()),this,SLOT(demanderPauseOuPlay()));
    QObject:: connect(ui->bPrecedent, SIGNAL(clicked()),this,SLOT(demanderPrecedent()));
    QObject:: connect(ui->bSuivant, SIGNAL(clicked()),this,SLOT(demanderSuivant()));
    QObject:: connect(ui->bArreter, SIGNAL(clicked()),this,SLOT(demanderArreter()));
    QObject:: connect(ui->bBoucle, SIGNAL(clicked()),this,SLOT(demanderBoucle()));
    QObject:: connect(ui->bOuvrirTiroir, SIGNAL(clicked()),this,SLOT(demanderOuvrirTiroir()));
    QObject:: connect(ui->bFermerTiroir, SIGNAL(clicked()),this,SLOT(demanderFermerTiroir()));
    QObject:: connect(ui->bInsererCD, SIGNAL(clicked()), this, SLOT(demanderInsertionCD()));
    QObject:: connect(ui->bRetirerCd, SIGNAL(clicked()), this, SLOT(demanderRetraitCD())); //pour faire comme ci on insserait un cd...
    QObject:: connect(ui->bActiverSon, SIGNAL(clicked()), this, SLOT(demanderActiverSon())); // le boutton radion n'est pas conmpatible donc il faute 2 bouttons et ses methodes....
    QObject:: connect(ui->bDesactiverSon, SIGNAL(clicked()), this, SLOT(demanderDesactiverSon()));

    QObject::connect(ui->slideSon, SIGNAL(valueChanged(int)), this, SLOT(demanderChangervolume(int)));

}

void LecteurVue::majInterfaceMarche()
{







        //changemtn des informations du cd
        ui->lbintituleCD->setText("Lecteur allumé !");
        ui->lbintituleMusique->setText("-");
        ui->lbTempTotMusic->setText("--.--");
        ui->lbTempActMusic->setText("--.--");
        ui->lbrangTitre->setText("-");
        ui->lbNbTitres->setText("-");

        //changement des boutons du tirroir :
        ui->bOuvrirTiroir->setEnabled(true);
        ui->bFermerTiroir->setEnabled(false);//le tirroir reste fermé quand on allume le lecteur.
        ui->bInsererCD->setEnabled(false); //pas possible d'incerer un cd tant qu'on a pas ouver le tirroir.
        ui->bRetirerCd->setEnabled(false); //pas possible de retirer un cd tant qu'on a pas ouver le tirroir.

        //changement de l'etat du bouton du son :
        ui->slideSon->setEnabled(true);
        ui->bActiverSon->setEnabled(false);
        //le son est déjà activé donc pas besoin de l'activer...
        //Boutton est utille que si on desacitve le son....
        ui->bDesactiverSon->setEnabled(true);


        //changement des etats des boutons d'actions sur la musique
        //rien n'est activé à ce niveau là tant qu'il n'y a pas de cd.
        ui->bArreter->setEnabled(false);
        ui->bAuto->setEnabled(false);
        ui->bBoucle->setEnabled(false);
        ui->bPause->setEnabled(false);
        ui->bSuivant->setEnabled(false);
        ui->bPrecedent->setEnabled(false);

}

void LecteurVue::majInterfaceLecturePause(string pLabel)
{
    ui->bPause->setText(QString::fromStdString(pLabel));
}

void LecteurVue::ordreMajControlesTiroirEtLecture(LecteurCD::UnEtat pEtat)
{
    switch (pEtat) {
    case LecteurCD::VIDE_ARRET :
        // Tiroir et CD
        ui->bOuvrirTiroir->setEnabled(true);
        ui->bInsererCD->setEnabled(false);
        ui->bRetirerCd->setEnabled(false);
        ui->bFermerTiroir->setEnabled(false);

        // lecture
        ui->bPause->setEnabled(false);
        ui->bArreter->setEnabled(false);
        ui->bPrecedent->setEnabled(false);
        ui->bSuivant->setEnabled(false);
        break;
    case LecteurCD::OUVERT_ARRET :
        // Tiroir et CD
        ui->bOuvrirTiroir->setEnabled(false);
        ui->bInsererCD->setEnabled(true);
        ui->bRetirerCd->setEnabled(true);
        ui->bFermerTiroir->setEnabled(true);
        // lecture
        ui->bPause->setEnabled(false);
        ui->bArreter->setEnabled(false);
        ui->bSuivant->setEnabled(false);
        ui->bPrecedent->setEnabled(false);
        break;
    case LecteurCD::CHARGE_ARRET:
        // Tiroir et CD
        ui->bOuvrirTiroir->setEnabled(true);
        ui->bInsererCD->setEnabled(false);
        ui->bRetirerCd->setEnabled(false);
        ui->bFermerTiroir->setEnabled(false);
        // lecture
        ui->bPause->setEnabled(true);
        ui->bArreter->setEnabled(false);
        ui->bSuivant->setEnabled(true);
        ui->bPrecedent->setEnabled(true);
        break;
    case LecteurCD::PAUSE :
        // Tiroir et CD
        ui->bOuvrirTiroir->setEnabled(true);
        ui->bInsererCD->setEnabled(false);
        ui->bRetirerCd->setEnabled(false);
        ui->bFermerTiroir->setEnabled(false);
        // lecture
        ui->bPause->setEnabled(true);
        ui->bArreter->setEnabled(true);
        ui->bSuivant->setEnabled(true);
        ui->bPrecedent->setEnabled(true);
        break;
    case LecteurCD::LECTURE :
        // Tiroir et CD
        ui->bOuvrirTiroir->setEnabled(true);
        ui->bInsererCD->setEnabled(false);
        ui->bRetirerCd->setEnabled(false);
        ui->bFermerTiroir->setEnabled(false);
        // lecture
        ui->bPause->setEnabled(true);
        ui->bArreter->setEnabled(true);
        ui->bSuivant->setEnabled(true);
        ui->bPrecedent->setEnabled(true);
        break;
    default : break;
    }
}

void LecteurVue::ordreMajInfosTitreEnCours(string pIntitule, int pRang)
{
    if (pRang == constantes::PAS_DE_TITRE)
    {
        ui->lbrangTitre->setText(QString::fromStdString("--"));
    }
    else
    {
        ui->lbrangTitre->setText(QString::number(pRang));
    }
    ui->lbintituleMusique->setText(QString::fromStdString(pIntitule));
}

void LecteurVue::ordreMajDureeTitreEnCours(int pDuree)
{
    // labelDuree, pour affichage au format hh:mm:ss
    QString strDuree;
    QTime duree ((pDuree/3600)%60,(pDuree/60)%60,pDuree%60, (pDuree*1000)%1000);
    QString format = "mm:ss";
    strDuree = duree.toString(format);
    ui->lbTempTotMusic->setText(strDuree);
}

void LecteurVue::ordreMajinfosCD(string pIntitule, string pPochette, string pGenre, int pDuree, int pNbTitres)
{
    // Maj des infos sur le CD
    ui->lbintituleCD->setText(QString::fromStdString(pIntitule));
    ui->lbPochette->setPixmap(QPixmap(QString::fromUtf8(pPochette)));
    ui->lbPochette->setAlignment(Qt::AlignCenter);
    ui->lbGenre->setText(QString::fromStdString(pGenre));

    QString strDuree;
    QTime duree ((pDuree/3600)%60,(pDuree/60)%60,pDuree%60, (pDuree*1000)%1000);
    QString format = "mm:ss";

    strDuree= duree.toString(format);
    ui->lbTempTotMusic->setText(strDuree);
    qDebug() << pNbTitres << Qt::endl;
    ui->lbNbTitres->setText(QString::number(pNbTitres));
}

void LecteurVue::ordreMajProgression(int pPosition)
{
    // affichage numérique de la durée en mm:ss
    QString strPosition;
    QTime position ((pPosition/3600)%60,(pPosition/60)%60,pPosition%60,(pPosition*1000)%1000);
    QString format = "mm:ss";
    strPosition = position.toString(format);
    ui->lbTempActMusic->setText(strPosition);
}

void LecteurVue::ordreMajControlesActivationDesactivationSon(bool pSonActif)
{
    if (pSonActif) {
        ui->bActiverSon->setEnabled(false);
        ui->bDesactiverSon->setEnabled(true);
    }
    else {
        ui->bActiverSon->setEnabled(true);
        ui->bDesactiverSon->setEnabled(false);
    }
}

void LecteurVue::ordreMajVolume(int pVolume)
{
    ui->slideSon->setValue(pVolume);
}

void LecteurVue::ordreOuvertureDialogue(QSqlQueryModel *pModeleRequete, int &pIdCD)
{
    // Créer une fenêtre de dialogue
    dlg = new Dialog(pModeleRequete, this);

    // Ouvrir la fenêtre et récupérer la réponse (valider/annuler) de l'utilisateur
    int reponse = dlg -> exec();

    // Traiter la réponse
    pIdCD = 0 ;         // par défaut, c'est Annulé
    if (reponse == QDialog::Accepted)
    {
        pIdCD = dlg->getIdCD();        // mise à jour si Accepté
    }
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::majInterfaceArret()
{
    //changemtn des informations du cd
    ui->lbintituleCD->setText("Lecteur éteint !");
    ui->lbintituleMusique->setText("-");
    ui->lbTempTotMusic->setText("--.--");
    ui->lbTempActMusic->setText("--.--");
    ui->lbrangTitre->setText("-");
    ui->lbNbTitres->setText("-");

    //changement des boutons du tirroir :
    ui->bOuvrirTiroir->setEnabled(false);
    ui->bFermerTiroir->setEnabled(false);
    ui->bInsererCD->setEnabled(false);
    ui->bRetirerCd->setEnabled(false);

    //changement de l'etat du bouton du son :
    ui->slideSon->setEnabled(false);
    ui->bActiverSon->setEnabled(false);
    ui->bDesactiverSon->setEnabled(false);

    //changement des etats des boutons d'actions sur la musique
    ui->bArreter->setEnabled(false);
    ui->bAuto->setEnabled(false);
    ui->bBoucle->setEnabled(false);
    ui->bPause->setEnabled(false);
    ui->bSuivant->setEnabled(false);
    ui->bPrecedent->setEnabled(false);
}

void LecteurVue::demanderBasculerOnOff(bool pAllume)
{
    if (pAllume) {
        qDebug() << "Allumage demande...";
        leLecteur->allumer();
    } else {
        qDebug() << "Extinction demandee...";
        leLecteur->eteindre();
    }
}

void LecteurVue::demanderPauseOuPlay()
{

    leLecteur->pauseOuLire();
}

void LecteurVue::demanderArreter()
{
    qDebug() << " lectureVue : bouton <bArreter> cliqué" << Qt ::endl ;
    leLecteur->arreter();
}

void LecteurVue::demanderSuivant()
{
    qDebug() << " lectureVue : bouton <bSuivant> cliqué" << Qt ::endl ;
    leLecteur->suivant();
}

void LecteurVue::demanderPrecedent()
{
    qDebug() << " lectureVue : bouton <bPrecedent> cliqué" << Qt ::endl ;
    leLecteur->precedent();
}

void LecteurVue::demanderAuto()
{
    qDebug() << " lectureVue : bouton <bAuto> cliqué" << Qt ::endl ;
    leLecteur->modeAuto();
}

void LecteurVue::demanderBoucle()
{
    qDebug() << " lectureVue : bouton <bBoucle> cliqué" << Qt ::endl ;
    leLecteur->modeBoucle();
}

void LecteurVue::demanderAleatoire()
{
    qDebug() << " lectureVue : bouton <bAleatoire> cliqué" << Qt ::endl ;
    leLecteur->modeAleatoire();
}

void LecteurVue::demanderOuvrirTiroir()
{
    leLecteur->ouvrirTiroir();

}

void LecteurVue::demanderFermerTiroir()
{
    leLecteur->fermerTiroir();

}



void LecteurVue::demanderInsertionCD()
{
    leLecteur->insererCd();

}

void LecteurVue::demanderRetraitCD()
{
    leLecteur->retirerCd();

}

void LecteurVue::demanderChangervolume(int pVolume)
{
    qDebug() << "lectureVue : envoie de la demande de changer de volume au lecteurCD"<< Qt ::endl ;
    leLecteur->changerVolume(pVolume);
    // On met à jour le label du volume que en chiffre...
    ui->lbVolumeActuel->setText(QString::number(pVolume));
}

void LecteurVue::demanderActiverSon()
{
    qDebug() << "LectureVue : le boutton d'activation du son est solicité.";
    leLecteur->activerSon();
    ui->slideSon->setEnabled(true);
    ui->bActiverSon->setEnabled(false);
}

void LecteurVue::demanderDesactiverSon()
{
    qDebug() << "LectureVue : le boutton de desactivation du son est solicité.";
    leLecteur->desactiverSon();
    ui->slideSon->setEnabled(false);
    ui->bDesactiverSon->setEnabled(false);
    ui->bActiverSon->setEnabled(true);

}




