#include "lecteurvue.h"
#include "LecteurCD.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // déclaration application
    QApplication a(argc, argv);

    // déclaration lecteurCD
    LecteurCD* l = new LecteurCD();

    // déclaration Vue
    LecteurVue* w = new LecteurVue(l);

    // association Vue <--> LecteurCD
    l->setVue(w);

    // Mise en conformité de l'interface avec l'état initial du lecteur
    w->ordreMajControlesTiroirEtLecture(l->getEtat());
    w->ordreMajinfosCD();
    w->ordreMajInfosTitreEnCours();

    // affichage du volume de la SortieSon
    int vollnt = static_cast<int>(l->getLeSon()->volume()*100.00);
    w->ordreMajVolume(vollnt);

    // démarrage de l'application
    w->show();
    return a.exec();
}
