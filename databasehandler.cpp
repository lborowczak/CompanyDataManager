#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DatabaseHandler::~DatabaseHandler(){
    CloseConnection();
}

bool DatabaseHandler::Connect(const QString &DBFile)
{
    db.setDatabaseName(DBFile);
    if (!db.open()){
        return false; //Database connection failed
    }
    return true;
}

bool DatabaseHandler::CreateDatabase(const QString &DBFile)
{
    db.setDatabaseName(DBFile);
    if (!db.open() || !CreateInitialTables()){
        return false; //Database unable to be opened or saved
    }
    CloseConnection();
    return true;
}

bool DatabaseHandler::CreateInitialTables()
{
    QSqlQuery PragmaQuery, AmountsCreationQuery, DatesCreationQuery, MainInfoCreationQuery;
    PragmaQuery.prepare("PRAGMA foreign_keys = ON");
    AmountsCreationQuery.prepare("CREATE TABLE Amounts("
                                 "AMOUNTS_ID int PRIMARY KEY,"
                                 "Gross_Pay_In_Cents bigint,"
                                 "Gross_Overpay_In_Cents bigint,"
                                 "Gross_Breakdown_Info text,"
                                 "Federal_Withholding_In_Cents bigint,"
                                 "Federal_Withholding_Overpay_In_Cents bigint,"
                                 "Medicare_Employee_Withholding_In_Cents bigint,"
                                 "Social_Security_Employee_Witholding_In_Cents bigint,"
                                 "State_Withholding_In_Cents bigint,"
                                 "State_Withholding_Overpay_In_Cents bigint"
                                 ")"
                                 );

    DatesCreationQuery.prepare("CREATE TABLE Dates("
                               "DATES_ID int PRIMARY KEY,"
                               "Start_Day tinyint,"
                               "Start_Month tinyint,"
                               "Start_Year smallint,"
                               "End_Day tinyint,"
                               "End_Month tinyint,"
                               "End_Year smallint,"
                               "Pay_Day tinyint,"
                               "Pay_Month tinyint,"
                               "Pay_Year smallint)"
                               );

    MainInfoCreationQuery.prepare("CREATE TABLE MainInfo("
                                  "ID int PRIMARY KEY,"
                                  "Company_Name text,"
                                  "Month tinyint,"
                                  "Quarter tinyint,"
                                  "Year smallint,"
                                  "DATES_ID int,"
                                  "AMOUNTS_ID int,"
                                  "FOREIGN KEY(DATES_ID) REFERENCES Dates(DATES_ID),"
                                  "FOREIGN KEY (AMOUNTS_ID) REFERENCES Amounts(AMOUNTS_ID))"
                                  );
    PragmaQuery.exec();
    if (!AmountsCreationQuery.exec()
    ||!DatesCreationQuery.exec()
    ||!MainInfoCreationQuery.exec()
    ){
        return false;  //File cannot be created or saved
    }
    return true;
}

void DatabaseHandler::CloseConnection(){
    db.commit();
    db.close();
}
