#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#define DATABASE_NAME "BD_Nodenot_SAE"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();

private:
    QSqlDatabase mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
};

#endif // DATABASE_H
