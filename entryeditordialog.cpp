#include "entryeditordialog.h"
#include "ui_entryeditordialog.h"

EntryEditorDialog::EntryEditorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryEditorDialog)
{
    ui->setupUi(this);
    setDefaultDates();
}

EntryEditorDialog::~EntryEditorDialog()
{

    delete ui;
}

void EntryEditorDialog::on_AddExpenseButton_clicked()
{
    //TODO refactor
    QHBoxLayout *newLayout = new QHBoxLayout();
    QComboBox *entryName = new QComboBox();
    newLayout->addWidget(entryName);
    entryName->setEditable(true);
    entryName->setMinimumWidth(150);
    newLayout->addStretch();
    QLineEdit *entryAmount = new QLineEdit();
    newLayout->addWidget(entryAmount);
    entryAmount->setMinimumWidth(100);
    entryAmount->setAlignment(Qt::AlignRight);

    ui->ExpenseEntryLayout->addLayout(newLayout);
}

void EntryEditorDialog::on_PaymentDateSelector_clicked(const QDate &date)
{
    setDefaultDates(date);
}

void EntryEditorDialog::setDefaultDates()
{
    //Code to set the payment date to the current Wednesday
    QDate currDate = QDate::currentDate();
    int currDOW = currDate.dayOfWeek();
    int DOWAdjustment = 3 - currDOW;
    QDate currWednesday = currDate.addDays(DOWAdjustment);

    setPaymentDate(currWednesday);
    setPaymentWeekDates(calculateWeekDates(currWednesday));

}

void EntryEditorDialog::setDefaultDates(const QDate &date)
{
    setPaymentDate(date);
    setPaymentWeekDates(calculateWeekDates(date));
}

QPair<const QDate, const QDate> EntryEditorDialog::calculateWeekDates(const QDate &date)
{
    //TODO implement
}

void EntryEditorDialog::setPaymentDate(const QDate &date)
{
    ui->PaymentDateSelector->setSelectedDate(date);
    ui->PaymentDate->setDate(date);
}

void EntryEditorDialog::setPaymentWeekDates(QPair<const QDate, const QDate> dates)
{
    ui->WeekStartDate->setDate(dates.first);
    ui->WeekEndDate->setDate(dates.second);
}
