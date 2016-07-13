#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>

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
    QFileDialog::getOpenFileName(this, tr("File selection"), QDir::homePath(), tr("Database files (*.db)"));
}

void MainWindow::on_actionNew_Database_triggered()
{
    QFileDialog::getSaveFileName(this, tr("test"),Dir::homePath(), tr("Database files (*.db)"));
}
