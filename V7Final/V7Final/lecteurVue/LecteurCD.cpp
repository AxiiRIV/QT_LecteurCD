#include "LecteurCD.h"
#include "lecteurvue.h"
#include <QDebug>

LecteurCD::LecteurCD(QObject *parent)
    : QObject(parent), monTiroirCD(this), laCellule(this), leSon(this)
{
    // Initialise le lecteurCD à l'état ETEINT
    setEtat(VIDE_ARRET);

    // Relier les composants Cellule (et son player) et sortieSon
    getLaCellule()->getPlayer()->setAudioOutput(getLeSon());

    // Régler le volume de la sortieSon
    leSon.setVolume(0.5);

    // Initialisation des attributs utilent pour la diffusion et l'affichage du titre en cours
    setTitreEnCours(nullptr);
    setRangTitreEnCours(constantes::PAS_DE_TITRE);

}

LecteurCD::~LecteurCD()
{
    delete this;
}

LecteurVue* LecteurCD::getVue()
{
    return laVue;
}


LecteurCD::UnEtat LecteurCD::getEtat()
{
    return etatLecteur;
}



TiroirCD* LecteurCD::getMonTiroirCD()
{
    return &monTiroirCD;
}

Cellule* LecteurCD::getLaCellule()
{
    return &laCellule;
}

SortieSon *LecteurCD::getLeSon()
{
    return &leSon;
}

LecteurCD::UnEtatModeLecture LecteurCD::getEtatModeLecture()
{
    return etatModeLecture;
}

int LecteurCD::getRangTitreEnCours()
{
    return rangTitreEnCours;
}

Titre *LecteurCD::getTitreEnCours()
{
    return titreEnCours;
}



void LecteurCD::setVue(LecteurVue *pVue)
{
    laVue = pVue;
}

/*void LecteurCD::setTiroirCD(TiroirCD& pTiroirCD)
{
    monTiroirCD = pTiroirCD;
}
*/


void LecteurCD::setEtat(UnEtat pEtat)
{
    etatLecteur = pEtat;
}

void LecteurCD::setEtatModeLecture(UnEtatModeLecture pEtatModeLecture)
{
    etatModeLecture = pEtatModeLecture;
}

void LecteurCD::setTitreEnCours(Titre *pTitreEnCours)
{
    titreEnCours = pTitreEnCours;
}

void LecteurCD::setRangTitreEnCours(int pRangTitreEnCours)
{
    rangTitreEnCours = pRangTitreEnCours;
}



void LecteurCD::changerVolume(int pVolume)
{
    // action métier
    float fVolume = static_cast<float>(pVolume) /100.00;
    leSon.setVolume(fVolume);
}

void LecteurCD::capterCellulePositionChanged(int pPosition)
{
    laVue->ordreMajProgression(pPosition);
}

void LecteurCD::allumer()
{
    laVue->majInterfaceMarche();

}

void LecteurCD::eteindre()
{
    laVue->majInterfaceArret();
}

void LecteurCD::arreter()
{
    qDebug()<< "Lecture arrétée. La lecture est reinitialisée!"<< Qt:: endl;

}

void LecteurCD::modeAleatoire()
{
    qDebug() << "Mode Aleatoire active" << Qt::endl;

    /*if (monCd != nullptr && monCd->getNbTitres() > 0)
    {
        // rand() génère un indice au hasard entre 0 et (nbTitres - 1) c'est bien pour aléatoire...
        // rand() % nb donne un nombre entre 0 et nb-1
        int indiceHasard = rand() % monCd->getNbTitres();

        //récupère le titre pris au hazard
        Titre t = monCd->getTitre(indiceHasard);

        qDebug() << "Lecture aleatoire de la piste :" << QString::fromStdString(t.getIntitule());
    }
*/
}

void LecteurCD::precedent()
{
    qDebug()<<"Musique precedante !"<< Qt:: endl;
    /*if (monCd != nullptr && monCd->getNbTitres() > 0)
    {
        // 1. Décrémenter l'index
        int positionActuelle = monCd->getPosition();
        positionActuelle--;

        // Sécurité : si on était à la première piste, on boucle à la fin
        if (positionActuelle < 0)
        {
            positionActuelle = monCd->getNbTitres() - 1;
        }

        // Récupérer le titre
        Titre t = monCd->getTitre(positionActuelle);


        etatLecteur = LECTURE;
    }
*/
}

void LecteurCD::suivant()
{
    qDebug()<<"Musique suivante !"<< Qt:: endl;
}

void LecteurCD::pauseOuLire()
{
    switch (this->getEtat()){
    case VIDE_ARRET: break;

    case OUVERT_ARRET: break;
    case LECTURE :
        getLaCellule()->arreterLecture();
        setEtat(PAUSE);
        laVue->majInterfaceLecturePause("Play");
        break;
    case CHARGE_ARRET :
    case PAUSE :
        /* action_D */
        getLaCellule()->demarrerLecture();
        setEtat(LECTURE);
        laVue->majInterfaceLecturePause("Pause");
        laVue->ordreMajControlesTiroirEtLecture(this->getEtat());
        break;
    default : break;
    }
}


void LecteurCD::modeBoucle()
{
    qDebug()<< "mode boucle activé"<< Qt::endl;

}

void LecteurCD::modeAuto()
{
    qDebug()<< "mode sequentiel activé"<< Qt::endl;

}

void LecteurCD::ouvrirTiroir()
{
    const QString PAS_DE_MEDIA_SOURCE = QString::fromStdString("");
    switch (this->getEtat()) {
    case VIDE_ARRET :
        /* action_A */
        qDebug() << "bouh" << Qt::endl;
        // actions métier
        getMonTiroirCD()->ouvrir();
        // changement d'état
        setEtat(OUVERT_ARRET);
        // ordres à destination de la Vue
        laVue->ordreMajControlesTiroirEtLecture(this->getEtat());
        break;
    case OUVERT_ARRET: break;
    case LECTURE:
        /* action_N */
            // actions métier
            getLaCellule()->arreterLecture();
            getMonTiroirCD()->ouvrir();
            setTitreEnCours(nullptr);
            setRangTitreEnCours(constantes::PAS_DE_TITRE);
            getLaCellule()->setSource(PAS_DE_MEDIA_SOURCE);
            // changement d'état
            setEtat(OUVERT_ARRET);
            // ordre de mise à jour de l'interface
            laVue->ordreMajInfosTitreEnCours();
            laVue->ordreMajDureeTitreEnCours(0);
            laVue->ordreMajControlesTiroirEtLecture(this->getEtat());

        break;
    case CHARGE_ARRET:
    case PAUSE:
        /* action_P */
            // actions métier
            getMonTiroirCD()->ouvrir();
            setTitreEnCours(nullptr);
            setRangTitreEnCours(constantes::PAS_DE_TITRE);
            getLaCellule()->setSource(PAS_DE_MEDIA_SOURCE);
            // changement d'état
            setEtat(OUVERT_ARRET);
            // ordres de mise à jour de l'interface
            laVue->ordreMajInfosTitreEnCours();
            laVue->ordreMajDureeTitreEnCours(0);
            laVue->ordreMajControlesTiroirEtLecture(this->getEtat());
        break;
    default: break;
    }
}

void LecteurCD::insererCd()
{
    switch (this->getEtat()) {
    case VIDE_ARRET : break;
    case OUVERT_ARRET :
        // si tiroir vide, on lui donne le cd sélécetionné:
        if(getMonTiroirCD()->getEtatOccupation()== TiroirCD::VIDE){
            // action_B :

            //action metier :
            //créer un cd et le peupler :
            Cd* leCd = new Cd();
            UnIndicateurDePeuplement indicPeuplement;  // indique la manière dont se termine la tentative de peuplement de leCD
            peuplerCD(leCd, indicPeuplement); // le CD est soit peuplé en dur, soit à partir de la BD, soit pas peuplé

            if(indicPeuplement == BD_NOK_CD_OK || indicPeuplement == BD_OK_CD_OK)
            {
                //associer le cd au tirroir :
                getMonTiroirCD()->insererCD(leCd);

                //maj de l'interface:
                string sUrlFichier = DOSSIER_MEDIAS + getMonTiroirCD()->getLeCD()->getPochette();
                laVue->ordreMajinfosCD(getMonTiroirCD()->getLeCD()->getIntitule(), sUrlFichier,
                                       getMonTiroirCD()->getLeCD()->getGenre(),
                                       getMonTiroirCD()->getLeCD()->getDuree(),
                                       getMonTiroirCD()->getLeCD()->getNbTitres());
                // mettre à jour les boutons de contrôle de Tiroir CD et Lecture
                laVue->ordreMajControlesTiroirEtLecture(this->getEtat());
            }
            else
            {
                // situation BD_OK_CD_NOK : l'utilisateur n'a choisi aucun CD dans la BD
                delete leCd;
            }

            // Pas de changement d'état

            // maj de l'interface à faire dans tous les cas
            laVue->ordreMajControlesTiroirEtLecture(this->getEtat());


        }
        break;

    case LECTURE : break;
    case CHARGE_ARRET : break;
    case PAUSE : break;
    default:
        break;
    }

}

void LecteurCD::retirerCd()
{
    switch (this->getEtat()) {
    case VIDE_ARRET : break;
    case OUVERT_ARRET :
        // si tiroir vide, on lui donne le cd sélécetionné:
        if(getMonTiroirCD()->getEtatOccupation()== TiroirCD::OCCUPE){
            // action_K :

            //action metier :

            //associer le cd au tirroir :
            getMonTiroirCD()->retirerCD();


            //changement d'état : il n'y en a pas

            //maj de l'interface:
            laVue->ordreMajinfosCD();
            // mettre à jour les boutons de contrôle de Tiroir CD et Lecture
            laVue->ordreMajControlesTiroirEtLecture(this->getEtat());

        }
        break;

    case LECTURE : break;
    case CHARGE_ARRET : break;
    case PAUSE : break;
    default:
        break;
    }

}

void LecteurCD::fermerTiroir()
{
    switch (this->getEtat()) {
    case VIDE_ARRET : break;
    case OUVERT_ARRET:
        // si CD présent dans tiroir, action C_bis
        if (getMonTiroirCD()->getEtatOccupation() == TiroirCD::OCCUPE) {
            /* action_C */
            // actions métier
            getMonTiroirCD()->fermer();

            setRangTitreEnCours(0);
            Titre* t = &(getMonTiroirCD()->getLeCD()->getTitres()[0]);
            setTitreEnCours(t);

            QString urlFichier = QString::fromStdString(DOSSIER_MEDIAS + getTitreEnCours()->getUrl());
            getLaCellule()->setSource(urlFichier);

            getLaCellule()->allerADebutMedia();

            // changer d'état
            setEtat(CHARGE_ARRET);

            // Maj de l'interface
            laVue->ordreMajInfosTitreEnCours(getTitreEnCours()->getIntitule(), getRangTitreEnCours()+1);
            laVue->ordreMajDureeTitreEnCours(getTitreEnCours()->getDuree());
            laVue->ordreMajControlesTiroirEtLecture(this->getEtat());
            laVue->majInterfaceLecturePause("Play");
        }
        else { // le tiroir est vide
            /* action_M */
            // actions métier
            getMonTiroirCD()->fermer();

            // changer d'état
            setEtat(VIDE_ARRET);

            // Maj de l'interface
            laVue->ordreMajinfosCD();
            laVue->ordreMajInfosTitreEnCours();
            laVue->ordreMajDureeTitreEnCours(0);
            laVue->ordreMajControlesTiroirEtLecture(this->getEtat());
        }
    case LECTURE: break;
    case CHARGE_ARRET: break;
    case PAUSE: break;
    default: break;
    }

}

void LecteurCD::activerSon()
{
    // action métier
    leSon.activerSon();
    // maj de l'interface
    laVue->ordreMajControlesActivationDesactivationSon (leSon.isMuted() == false);
}

void LecteurCD::desactiverSon()
{
    // action métier
    leSon.desactiverSon();

    // maj de l'interface
    laVue->ordreMajControlesActivationDesactivationSon (leSon.isMuted() == true);
}

void LecteurCD::peuplerCD(Cd *pCD, UnIndicateurDePeuplement& pIndicPeuplement)
{

    /* Tenter de peupler le CD,  pIndicPeuplement retourne le résultat de cette tentative :
     * - Si pIndicPeuplement = BD_NOK_CD_OK : la BD est inaccessible, le CD a été peuplé 'en dur'
     * - Si pIndicPeuplement = BD_OK_CD_NOK : la BD est accessible mais l'utilisateur n'a choisi aucun CD
     * - Si pIndicPeuplement = BD_OK_CD_OK : la BD est accessible et un CD a été choisi
     * */
    pIndicPeuplement = BD_OK_CD_NOK; // l'utilisateur n'a rien sélectionné

    Database maBd;
    if(maBd.openDataBase())
    {
        /* < Proposer le choix d'un CD > */

        // Construire  la requête affichant la liste des CDS et leur genre
        QString chaineRequeteListeCDs = QString("SELECT cd.id_cd, cd.intitule_cd, genre.intitule_genre, cd.nbTitres_cd FROM cd INNER JOIN genre ON cd.genreMusical_cd = genre.id_genre;");

        // Exécuter la requête, récupérer ses résultats et les stocker dans queryModelCDs
        QSqlQueryModel* queryModelCDs = new QSqlQueryModel();
        queryModelCDs->setQuery(chaineRequeteListeCDs);

        // Ouverture de la fenetre dialogue
        int idCD; // identificateur en BD du CD sélectionné
        laVue->ordreOuvertureDialogue(queryModelCDs, idCD);

        if(idCD > 0)
        {
            /* < Initialiser le CD à partir de la Base de données > */

            // Infos relatives au CD

            // Récupérer les attributs du CD idCD (intiyulé, genre, durée, pochette)
            QString chaineRequeteCD = QString("SELECT cd.id_cd, cd.intitule_cd, genre.intitule_genre, cd.dureeTotale_cd, cd.pochette_cd, cd.nbTitres_cd FROM cd INNER JOIN genre ON cd.genreMusical_cd = genre.id_genre WHERE cd.id_cd =" + QString::number(idCD) + ";");
            QSqlQuery requeteCD(chaineRequeteCD);

            // Initialiser les attributs du CD (*leCD) avec les informations de l'UNIQUE ligne réponse
            initialiserInfosCD(pCD, &requeteCD);

            // Infos relatives aux titres du CD

            // Récupération dans la BD des titres de ce CD
            QString chaineRequeteTitres = QString("SELECT titre.intitule_titre, titre.duree_titre, titre.media_titre, cd_titre.rang ")
                                          + "FROM cd INNER JOIN genre ON cd.genreMusical_cd = genre.id_genre INNER JOIN cd_titre ON cd.id_cd = cd_titre.id_cd INNER JOIN titre ON cd_titre.id_titre = titre.id_titre "
                                          + "WHERE cd.id_cd = " +QString::number(idCD) + " "
                                          + "ORDER BY cd_titre.rang;";
            QSqlQuery requeteTitres(chaineRequeteTitres);

            // Ajouter au CD (*pCD) les infos contenues dans la réponse
            ajouterInfosTitres(pCD, &requeteTitres);

            // Mise à jour de l'indicateur de peuplement
            pIndicPeuplement = BD_OK_CD_OK;
        }
        else // l'utilisateur n'a pas désigné de CD
        {
            // Mise à jour de l'indicateur de peuplement
            pIndicPeuplement = BD_OK_CD_NOK;
        }

        // fermer la Base de données
        maBd.closeDataBase();
    }
    else
    {
        /* < Peupler le CD en dur > */
        qDebug() << "le fonctionnement est en mode dégradé"  << Qt::endl;
        peuplerCD(pCD);

        // Mise à jour de l'indicateur de peuplement
        pIndicPeuplement = BD_NOK_CD_OK;
    }
}

void LecteurCD::peuplerCD(Cd *pCD)
{
    pCD->ajouterTitre( "RossBugden-Notturno", 155, "titres/titre_01_RossBugden-Notturno.mp3");
    pCD->ajouterTitre( "LCE2C-RiversideII", 224, "titres/titre_02_LCE2C-RiversideII.mp3");
    pCD->ajouterTitre( "ZeroProject-PassMeBy", 204, "titres/titre_03_ZeroProject-PassMeBy.mp3");
    pCD->ajouterTitre( "NovaNoma-Gaia", 205, "titres/titre_04_NovaNoma-Gaia.mp3");
    pCD->setNbTitres(4);
    pCD->setDuree(788);
    pCD->setIntitule("Zero Project  - Whispering Iceland");
    pCD->setPochette("pochettes/pochette_cd01.jpg");
    pCD->setGenre("Pop");

    // Pour vérification
    for (unsigned int i = 0; i < pCD->getNbTitres(); i++)
    {
        qDebug() << pCD->getTitres()[i].getIntitule() << Qt::endl;
    }


}

void LecteurCD::initialiserInfosCD(Cd *pCD, QSqlQuery *pQuery)
{
    for (int i = 0; pQuery->next(); i++)
    {
        pCD->setIntitule(pQuery->value(1).toString().toStdString());
        pCD->setGenre(pQuery->value(2).toString().toStdString());
        pCD->setDuree(pQuery->value(3).toString().toInt());
        pCD->setPochette(pQuery->value(4).toString().toStdString());
        // pCD->NbTitres()     Sera calculé plus bas lors du chargement des titres

    }

}

void LecteurCD::ajouterInfosTitres(Cd *pCD, QSqlQuery *pQuery)
{
    for(int i = 0; pQuery->next(); i++)
    {
        pCD->ajouterTitre(pQuery->value(0).toString().toStdString(),       // intitule
                          pQuery->value(1).toString().toInt(),             // duree
                          pQuery->value(2).toString().toStdString()        // chemin accès relatif par rapport à LecteurCD::DOSSIER_MEDIAS
                          );
    }

}
