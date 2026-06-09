#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QSqlQueryModel *pModeleRequete, QWidget *parent):

    QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // connexion entre boutons et slots
    QObject::connect (ui->bValider, SIGNAL(clicked(bool)), this, SLOT(valider()));
    QObject::connect (ui->bAnnuler, SIGNAL(clicked(bool)), this, SLOT(annuler()));
    QObject::connect (ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(elementClique(QModelIndex)));
    // Associer la TableView au modèle pModeleRequete.
    //      = La fenêtre de dialogue associe une vue au paramètre pModeleRequete,.
    //          Ce paramètre pointe sur un objet contenant les résultats de l'exécution d'une requête exécuté dans le sous-programme appelant
    ui->tableView->setModel(pModeleRequete);     // le remplissage de la tableView avec les résultats de la requête est automatique. Merci Qt !    :-)
    /* Paramétrage de la vue : améliorer le visuel  - interdire l'édition */
    //  cacher les colonnes que l'on ne veut pas montrer
    ui->tableView->hideColumn(0);

    // Entêtes en gras
    ui->tableView->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { font-weight: bold; }");

    // Adaptation des colonnes au contenu
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);

    // Interdire l'édition
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setIdCD(QString pIdCD)
{
    ui->labelIdCD->setText(pIdCD);
}

int Dialog::getIdCD()
{
    QString labelIdCD = ui->labelIdCD->text();

    // conversion en entier du contenu du label
    bool conversionOk;
    int entierIdCD = labelIdCD.toInt(&conversionOk);
    if (!conversionOk)          // l'utilisateur peut <Valider> sans avoir choisi de CD
    {
        entierIdCD = 0;
    }

    return entierIdCD;
}

void Dialog::elementClique(QModelIndex indexClique)
{
    // L'utilisateur a cliqué sur une cellule quelconque de la ligne souhaitée.
    // L'information souhaitée (idCD) se trouve à la colonne 0 de cette ligne.
    // Rappel : C'est le modèle qui détient les données et non la TableView.
    //               C'est donc le modèle qui sera interrogé pour récupérer le contenu souhaité.

    int ligne = indexClique.row();    // ligne de l'élément cliqué

    // l'idCD de la ligne cliquée se trouve en (ligne, colonne=0) du modèle
    QModelIndex emplacementIdCD =  ui->tableView->model()->index(ligne, 0);    // emplacement dans le modèle calculé
    QVariant valeur = emplacementIdCD.data();                                                          // accès au contenu dans le modèle

    // affichage de l'identifiant du CD choisi
    ui->labelIdCD->setText(valeur.toString());
}

void Dialog::annuler()
{ reject() ; // ferme le dialogue en le validant
}

void Dialog::valider()
{ accept() ;// ferme le dialogue en l'annulant
}
