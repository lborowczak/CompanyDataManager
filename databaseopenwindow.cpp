#include "databaseopenwindow.h"
#include "ui_databaseopenwindow.h"

DatabaseOpenWindow::DatabaseOpenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseOpenWindow)
{
    ui->setupUi(this);
    QMainWindow::showFullScreen();
}

DatabaseOpenWindow::~DatabaseOpenWindow()
{
    delete ui;
}
