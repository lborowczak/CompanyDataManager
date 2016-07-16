#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>


class DatabaseHandler
{
public:
    DatabaseHandler();
    bool Connect(const QString &DBFile);
    bool CreateDatabase(const QString &DBFile);
    void CloseConnection();
private:
    QSqlDatabase db;
    bool CreateInitialTables();
};

#endif // DATABASEHANDLER_H
