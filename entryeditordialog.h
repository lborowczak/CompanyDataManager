#ifndef ENTRYEDITORDIALOG_H
#define ENTRYEDITORDIALOG_H

#include <QDialog>

namespace Ui {
class EntryEditorDialog;
}

class EntryEditorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntryEditorDialog(QWidget *parent = 0);
    ~EntryEditorDialog();

private slots:
    void on_AddExpenseButton_clicked();

private:
    Ui::EntryEditorDialog *ui;
};

#endif // ENTRYEDITORDIALOG_H
