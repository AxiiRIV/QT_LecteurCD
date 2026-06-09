/********************************************************************************
** Form generated from reading UI file 'lecteurvue.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTEURVUE_H
#define UI_LECTEURVUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LecteurVue
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *VLActionLecteur;
    QRadioButton *bOnOff;
    QPushButton *bOuvrirTiroir;
    QPushButton *bInsererCD;
    QPushButton *bRetirerCd;
    QPushButton *bFermerTiroir;
    QGridLayout *GrCentre;
    QLabel *lbhautParleurDroit;
    QVBoxLayout *verticalLayout;
    QLabel *lbPochette;
    QLabel *lbintituleCD;
    QLabel *lbGenre;
    QLabel *lbintituleMusique;
    QLabel *lbhautParleurGauche;
    QHBoxLayout *HTempMusic;
    QLabel *lbTempActMusic;
    QLabel *lbTempTotMusic;
    QHBoxLayout *HLTitre;
    QLabel *lbrangTitre;
    QLabel *lbNbTitres;
    QHBoxLayout *HBAction;
    QPushButton *bBoucle;
    QPushButton *bPrecedent;
    QPushButton *bPause;
    QPushButton *bArreter;
    QPushButton *bSuivant;
    QPushButton *bAuto;
    QPushButton *bAleatoire;
    QVBoxLayout *VLSon;
    QPushButton *bActiverSon;
    QPushButton *bDesactiverSon;
    QSlider *slideSon;
    QLabel *lbVolumeActuel;
    QMenuBar *BarreEnHauteur;

    void setupUi(QMainWindow *LecteurVue)
    {
        if (LecteurVue->objectName().isEmpty())
            LecteurVue->setObjectName("LecteurVue");
        LecteurVue->resize(876, 182);
        centralwidget = new QWidget(LecteurVue);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        VLActionLecteur = new QVBoxLayout();
        VLActionLecteur->setObjectName("VLActionLecteur");
        bOnOff = new QRadioButton(centralwidget);
        bOnOff->setObjectName("bOnOff");

        VLActionLecteur->addWidget(bOnOff);

        bOuvrirTiroir = new QPushButton(centralwidget);
        bOuvrirTiroir->setObjectName("bOuvrirTiroir");

        VLActionLecteur->addWidget(bOuvrirTiroir);

        bInsererCD = new QPushButton(centralwidget);
        bInsererCD->setObjectName("bInsererCD");

        VLActionLecteur->addWidget(bInsererCD);

        bRetirerCd = new QPushButton(centralwidget);
        bRetirerCd->setObjectName("bRetirerCd");

        VLActionLecteur->addWidget(bRetirerCd);

        bFermerTiroir = new QPushButton(centralwidget);
        bFermerTiroir->setObjectName("bFermerTiroir");

        VLActionLecteur->addWidget(bFermerTiroir);


        horizontalLayout->addLayout(VLActionLecteur);

        GrCentre = new QGridLayout();
        GrCentre->setObjectName("GrCentre");
        lbhautParleurDroit = new QLabel(centralwidget);
        lbhautParleurDroit->setObjectName("lbhautParleurDroit");
        lbhautParleurDroit->setAlignment(Qt::AlignCenter);

        GrCentre->addWidget(lbhautParleurDroit, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbPochette = new QLabel(centralwidget);
        lbPochette->setObjectName("lbPochette");
        lbPochette->setMaximumSize(QSize(167, 167));
        lbPochette->setScaledContents(true);
        lbPochette->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbPochette);

        lbintituleCD = new QLabel(centralwidget);
        lbintituleCD->setObjectName("lbintituleCD");
        lbintituleCD->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(lbintituleCD);

        lbGenre = new QLabel(centralwidget);
        lbGenre->setObjectName("lbGenre");
        lbGenre->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbGenre);

        lbintituleMusique = new QLabel(centralwidget);
        lbintituleMusique->setObjectName("lbintituleMusique");
        lbintituleMusique->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(lbintituleMusique);


        GrCentre->addLayout(verticalLayout, 0, 1, 2, 1);

        lbhautParleurGauche = new QLabel(centralwidget);
        lbhautParleurGauche->setObjectName("lbhautParleurGauche");
        lbhautParleurGauche->setAlignment(Qt::AlignCenter);

        GrCentre->addWidget(lbhautParleurGauche, 0, 2, 1, 1);

        HTempMusic = new QHBoxLayout();
        HTempMusic->setObjectName("HTempMusic");
        lbTempActMusic = new QLabel(centralwidget);
        lbTempActMusic->setObjectName("lbTempActMusic");
        lbTempActMusic->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        HTempMusic->addWidget(lbTempActMusic);

        lbTempTotMusic = new QLabel(centralwidget);
        lbTempTotMusic->setObjectName("lbTempTotMusic");
        lbTempTotMusic->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        HTempMusic->addWidget(lbTempTotMusic);


        GrCentre->addLayout(HTempMusic, 1, 0, 1, 1);

        HLTitre = new QHBoxLayout();
        HLTitre->setObjectName("HLTitre");
        lbrangTitre = new QLabel(centralwidget);
        lbrangTitre->setObjectName("lbrangTitre");
        lbrangTitre->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        HLTitre->addWidget(lbrangTitre);

        lbNbTitres = new QLabel(centralwidget);
        lbNbTitres->setObjectName("lbNbTitres");
        lbNbTitres->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        HLTitre->addWidget(lbNbTitres);


        GrCentre->addLayout(HLTitre, 1, 2, 1, 1);

        HBAction = new QHBoxLayout();
        HBAction->setObjectName("HBAction");
        bBoucle = new QPushButton(centralwidget);
        bBoucle->setObjectName("bBoucle");

        HBAction->addWidget(bBoucle);

        bPrecedent = new QPushButton(centralwidget);
        bPrecedent->setObjectName("bPrecedent");

        HBAction->addWidget(bPrecedent);

        bPause = new QPushButton(centralwidget);
        bPause->setObjectName("bPause");

        HBAction->addWidget(bPause);

        bArreter = new QPushButton(centralwidget);
        bArreter->setObjectName("bArreter");

        HBAction->addWidget(bArreter);

        bSuivant = new QPushButton(centralwidget);
        bSuivant->setObjectName("bSuivant");

        HBAction->addWidget(bSuivant);

        bAuto = new QPushButton(centralwidget);
        bAuto->setObjectName("bAuto");

        HBAction->addWidget(bAuto);

        bAleatoire = new QPushButton(centralwidget);
        bAleatoire->setObjectName("bAleatoire");

        HBAction->addWidget(bAleatoire);


        GrCentre->addLayout(HBAction, 2, 0, 1, 3);


        horizontalLayout->addLayout(GrCentre);

        VLSon = new QVBoxLayout();
        VLSon->setObjectName("VLSon");
        bActiverSon = new QPushButton(centralwidget);
        bActiverSon->setObjectName("bActiverSon");

        VLSon->addWidget(bActiverSon);

        bDesactiverSon = new QPushButton(centralwidget);
        bDesactiverSon->setObjectName("bDesactiverSon");

        VLSon->addWidget(bDesactiverSon);

        slideSon = new QSlider(centralwidget);
        slideSon->setObjectName("slideSon");
        slideSon->setOrientation(Qt::Vertical);

        VLSon->addWidget(slideSon);

        lbVolumeActuel = new QLabel(centralwidget);
        lbVolumeActuel->setObjectName("lbVolumeActuel");

        VLSon->addWidget(lbVolumeActuel);


        horizontalLayout->addLayout(VLSon);

        LecteurVue->setCentralWidget(centralwidget);
        BarreEnHauteur = new QMenuBar(LecteurVue);
        BarreEnHauteur->setObjectName("BarreEnHauteur");
        BarreEnHauteur->setGeometry(QRect(0, 0, 876, 17));
        LecteurVue->setMenuBar(BarreEnHauteur);

        retranslateUi(LecteurVue);

        QMetaObject::connectSlotsByName(LecteurVue);
    } // setupUi

    void retranslateUi(QMainWindow *LecteurVue)
    {
        LecteurVue->setWindowTitle(QCoreApplication::translate("LecteurVue", "LecteurVue", nullptr));
        bOnOff->setText(QCoreApplication::translate("LecteurVue", "Allumer/Eteindre", nullptr));
        bOuvrirTiroir->setText(QCoreApplication::translate("LecteurVue", "Ouvrir tiroir", nullptr));
        bInsererCD->setText(QCoreApplication::translate("LecteurVue", "Inserer un CD", nullptr));
        bRetirerCd->setText(QCoreApplication::translate("LecteurVue", "Retirer CD", nullptr));
        bFermerTiroir->setText(QCoreApplication::translate("LecteurVue", "Fermer tiroir", nullptr));
        lbhautParleurDroit->setText(QCoreApplication::translate("LecteurVue", "haut parleur gauche", nullptr));
        lbPochette->setText(QCoreApplication::translate("LecteurVue", "Pochette", nullptr));
        lbintituleCD->setText(QCoreApplication::translate("LecteurVue", "Intitul\303\251 du cd ", nullptr));
        lbGenre->setText(QCoreApplication::translate("LecteurVue", "Genre", nullptr));
        lbintituleMusique->setText(QCoreApplication::translate("LecteurVue", "Intitul\303\251 de la musique", nullptr));
        lbhautParleurGauche->setText(QCoreApplication::translate("LecteurVue", "haut parleur droit", nullptr));
        lbTempActMusic->setText(QCoreApplication::translate("LecteurVue", "Temps actuel de  la musique jou\303\251e", nullptr));
        lbTempTotMusic->setText(QCoreApplication::translate("LecteurVue", "Temps total de la musique jou\303\251e", nullptr));
        lbrangTitre->setText(QCoreApplication::translate("LecteurVue", "rang du titre", nullptr));
        lbNbTitres->setText(QCoreApplication::translate("LecteurVue", "nombre de titre", nullptr));
        bBoucle->setText(QCoreApplication::translate("LecteurVue", "Boucle", nullptr));
        bPrecedent->setText(QCoreApplication::translate("LecteurVue", "pr\303\251c\303\251dent", nullptr));
        bPause->setText(QCoreApplication::translate("LecteurVue", "Pause", nullptr));
        bArreter->setText(QCoreApplication::translate("LecteurVue", "Arreter", nullptr));
        bSuivant->setText(QCoreApplication::translate("LecteurVue", "suivant", nullptr));
        bAuto->setText(QCoreApplication::translate("LecteurVue", "Auto", nullptr));
        bAleatoire->setText(QCoreApplication::translate("LecteurVue", "ALeatoire", nullptr));
        bActiverSon->setText(QCoreApplication::translate("LecteurVue", "Activer Son", nullptr));
        bDesactiverSon->setText(QCoreApplication::translate("LecteurVue", "Desactiver Son", nullptr));
        lbVolumeActuel->setText(QCoreApplication::translate("LecteurVue", "SonActuel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LecteurVue: public Ui_LecteurVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTEURVUE_H
