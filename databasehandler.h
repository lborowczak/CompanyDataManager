#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>


class DatabaseHandler
{
public:
    DatabaseHandler();
    void Connect();
    void CreateDatabase();
};

#endif // DATABASEHANDLER_H
