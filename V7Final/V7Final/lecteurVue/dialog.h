
#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QSqlQueryModel * pModeleRequete, QWidget *parent);
    ~Dialog();
public:
    void setIdCD(QString pIdCD);
    int getIdCD();
private slots:
    void annuler();
    void valider();
    void elementClique(QModelIndex indexClique);


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
