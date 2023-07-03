#include "database.h"


DataBase::DataBase()
{

}
void DataBase::connectToDataBase(QString a, QString b, QString c)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(a);
    db.setPort(5432);
    db.setDatabaseName("BaseTime");
    db.setUserName(b);
    db.setPassword(c);
    if (!db.open())
    {
        db.close();
        qDebug() << db.lastError().text();
    }
    else
    {
        qDebug() <<"Success!";
    }
}
QString DataBase::errorToDataBase()
{
 return db.lastError().text();
}
