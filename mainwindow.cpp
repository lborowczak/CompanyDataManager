#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasehandler.h"
#include <QFileDialog>
//#include <QDir>

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
    DatabaseHandler DBH;
    DBH.Connect(DBPath);
}

void MainWindow::on_actionNew_Database_triggered()
{
    QString DBPath = QFileDialog::getSaveFileName(this, tr("test"), QDir::homePath(), tr("Database files (*.db)"));
    QFile::remove(DBPath); //Delete file to make new one, user confirmed overwriting it
    DatabaseHandler DBH;
    std::cout << DBH.CreateDatabase(DBPath) << std::endl;
}
