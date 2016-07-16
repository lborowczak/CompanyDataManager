#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <Qt>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    DBHandler.CloseConnection();
    delete ui;
}

void MainWindow::on_actionOpen_Database_triggered()
{
    QString DBPath = QFileDialog::getOpenFileName(this, tr("File selection"), QDir::homePath(), tr("Database files (*.db)"));
    DBHandler.Connect(DBPath);
    openDatabaseWindow();


}

void MainWindow::on_actionNew_Database_triggered()
{
    QString DBPath = QFileDialog::getSaveFileName(this, tr("test"), QDir::homePath(), tr("Database files (*.db)"));
    if (DBPath == NULL){
        return;
    }
    QFile::remove(DBPath); //Delete file to make new one, user confirmed overwriting it
    DBHandler.CreateDatabase(DBPath);
}

void MainWindow::openDatabaseWindow(){
    DBManagementWindow = new DatabaseOpenWindow();
    ui->mdiArea->addSubWindow(DBManagementWindow, Qt::FramelessWindowHint);
    DBManagementWindow->show();
}

