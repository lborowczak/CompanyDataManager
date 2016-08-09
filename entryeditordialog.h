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

    void on_PaymentDateSelector_clicked(const QDate &date);

private:
    Ui::EntryEditorDialog *ui;

    void setPaymentDate(const QDate &date);

    void setPaymentWeekDates(QPair<const QDate, const QDate> dates);

    void setDefaultDates();
    void setDefaultDates(const QDate &date);

    QPair<const QDate, const QDate> calculateWeekDates(const QDate &date);
};

#endif // ENTRYEDITORDIALOG_H
