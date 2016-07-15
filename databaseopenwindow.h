#ifndef DATABASEOPENWINDOW_H
#define DATABASEOPENWINDOW_H

#include <QMainWindow>

namespace Ui {
class DatabaseOpenWindow;
}

class DatabaseOpenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseOpenWindow(QWidget *parent = 0);
    ~DatabaseOpenWindow();

private:
    Ui::DatabaseOpenWindow *ui;
};

#endif // DATABASEOPENWINDOW_H
