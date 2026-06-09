#include "database.h"
Database::Database() {}
bool Database::openDataBase()
{
    mydb.setHostName("MySQLWorkbench");
    mydb.setDatabaseName(DATABASE_NAME);
    mydb.setUserName("msouharce_bd");
    mydb.setPassword("msouharce_bd");
    bool ok = mydb.open();
    return ok;

}

/*
Database::Database() {}
bool Database::openDataBase()
{
    mydb.setHostName("MySQLWorkbench");
    mydb.setDatabaseName(DATABASE_NAME);
    mydb.setUserName("wdescat_bd");
    mydb.setPassword("wdescat_bd");
    bool ok = mydb.open();
    return ok;

}
*/

void Database::closeDataBase()
{
    QSqlDatabase::removeDatabase(CONNECT_TYPE);
}
