#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasehandler.h"
#include "databaseopenwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_Database_triggered();

    void on_actionNew_Database_triggered();

private:
    Ui::MainWindow *ui;
    DatabaseOpenWindow *DBManagementWindow;
    DatabaseHandler DBHandler;
};

#endif // MAINWINDOW_H
