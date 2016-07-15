#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_Database_triggered()
{
    QString DBPath = QFileDialog::getOpenFileName(this, tr("File selection"), QDir::homePath(), tr("Database files (*.db)"));
    DBHandler.Connect(DBPath);
    DBManagementWindow = new DatabaseOpenWindow();
    DBManagementWindow->show();
    //this->setHidden(true); TODO figure out a better way to hide the window while the other window is open
}

void MainWindow::on_actionNew_Database_triggered()
{
    QString DBPath = QFileDialog::getSaveFileName(this, tr("test"), QDir::homePath(), tr("Database files (*.db)"));
    QFile::remove(DBPath); //Delete file to make new one, user confirmed overwriting it
    DBHandler.CreateDatabase(DBPath);
}
