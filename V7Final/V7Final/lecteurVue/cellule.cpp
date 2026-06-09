#include <QDebug>
#include "cellule.h"
#include "lecteurCD.h"
#include "cellule.h" // pour implémenter la cellue de lecture d'un disque.

Cellule::Cellule(LecteurCD* pLecteur, QObject *parent)
    : QObject{parent}, leLecteurCD(pLecteur)
{
    qDebug() << "Cellule::Construction début" << Qt::endl;
    // initialisation de la cellule
    etatMoteur = ARRET;
    player = new QMediaPlayer(this);
    player->setLoops(QMediaPlayer::Once);   // le lecteur se met par défaut en mode séquentiel
    qDebug() << "Cellule::Construction : tête de lecture (player) créée" << Qt::endl;

    if (getLeLecteurCD()->getLaCellule() == this)
    {
        qDebug() << "Cellule::Construction : liaison avec LecteurCD établie" << Qt::endl;
    } 
    qDebug() << "Cellule::Construction fin" << Qt::endl;

    // connexion
    QObject::connect(player, SIGNAL(positionChanged(qint64)),
                    this, SLOT(playerPositionChanged(qint64)),
                     Qt::QueuedConnection);

}

Cellule::~Cellule() {
    //delete player;
    player->~QMediaPlayer();
    qDebug() << "Destruction de la Cellule " << Qt::endl;
}

// getters - v4
//------------------------------
Cellule::UnEtatMoteurCellule Cellule::getEtatMoteur() {
    qDebug() << "Récupération de l'état du moteur.";
    return etatMoteur;
}

QMediaPlayer *Cellule::getPlayer()
{
    qDebug() << "Récupération du Player .";
    return player;
}

LecteurCD *Cellule::getLeLecteurCD()
{
    qDebug() << "Récupération du Lecteur .";

    return leLecteurCD;
}


// méthodes 'métier' et setters - v4
//------------------------------
void Cellule::demarrerLecture() {

    qDebug() << "Démarage de la lecture.";
    etatMoteur = MARCHE;
    player->play();
}

void Cellule::arreterLecture() {
    qDebug() << "Arret de la lecture.";
    etatMoteur = ARRET;
    player->pause();
}

void Cellule::allerADebutMedia()
{
    qDebug() << "Placement en debut de média.";
    player->setPosition(0);
}

void Cellule::setSource(const QString &source)
{
    qDebug() << "Chargement de la source.";
    getPlayer()->setSource(QUrl::fromLocalFile(source));
}

void Cellule::setPlayer(QMediaPlayer *pPlayer)
{
    qDebug() << "Chargement du player ;";
    player = pPlayer;
}

void Cellule::playerPositionChanged(qint64 pDuration)
{
    leLecteurCD->capterCellulePositionChanged(pDuration/1000);
}

void Cellule::setLecteurCD(LecteurCD *pLecteur)
{
    qDebug() << "Chargement du Lecteur.";
    leLecteurCD = pLecteur;
}


