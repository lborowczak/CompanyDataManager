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

private slots:
    void on_AddEntryButton_clicked();

    void on_SpecificTimeRadioButton_toggled(bool checked);

    void on_YearCheckbox_toggled(bool checked);

    void on_MonthCheckbox_toggled(bool checked);

    void on_DayCheckbox_toggled(bool checked);

private:
    Ui::DatabaseOpenWindow *ui;
};

#endif // DATABASEOPENWINDOW_H
