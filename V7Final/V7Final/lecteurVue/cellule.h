#ifndef CELLULE_H
#define CELLULE_H
#include <QMediaPlayer>

#include <QObject>


class LecteurCD;
class Cellule : public QObject
{
    Q_OBJECT
public:
    enum UnEtatMoteurCellule {ARRET, MARCHE};
    explicit Cellule(LecteurCD* pLecteur, QObject *parent = nullptr);
    virtual ~Cellule();

    // getters - v4
    UnEtatMoteurCellule getEtatMoteur();
    LecteurCD* getLeLecteurCD();
    QMediaPlayer* getPlayer();

    // méthodes 'métier' et setters - v4
    void demarrerLecture();
        // met en marche le moteur de la cellule, la lecture du média courant démarre à partir
    //de l'emplacement actuel de la tête de lecture (= du player) sur le media
    //sera à mettre dans plays pour démarer la lecture du son.
    void arreterLecture();
        // arrête le moteur de la cellule, la tête de lecture reste sur place sur le média courant
    // à mettre pour le boutton pause.
    void allerADebutMedia();
        // déplace la tête de lecture en début du média en cours
    // a mettre pour le boutton arréter.
    void setSource(const QString& source);
        // fournit au player le chemin d'accès du fichier media à lire
    //jsp ou mettre ce truc...
    void setLecteurCD(LecteurCD* pLecteur);
    //pour s'assurer que c'est le bon lecteur????
    void setPlayer(QMediaPlayer* pPlayer);
    //pour s'assurer que c'est le bon player????


private:
    QMediaPlayer *player;      // la 'tête de lecture' = le composant Qt qui lit les fichiers son
    UnEtatMoteurCellule etatMoteur;
    /* état du player :
     * ARRET (avec player en PAUSE-STOP) / MARCHE (avec player en PLAY)
       */
    LecteurCD* leLecteurCD; // pour communiquer avec le composé

private slots:
    void playerPositionChanged(qint64 pDuration);
};

#endif // CELLULE_H
