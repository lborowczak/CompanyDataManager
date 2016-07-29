#include "databaseopenwindow.h"
#include "ui_databaseopenwindow.h"
#include "entryeditordialog.h"

DatabaseOpenWindow::DatabaseOpenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseOpenWindow)
{
    ui->setupUi(this);
    //QMainWindow::showFullScreen();
}

DatabaseOpenWindow::~DatabaseOpenWindow()
{
    delete ui;
}

void DatabaseOpenWindow::on_AddEntryButton_clicked()
{
    EntryEditorDialog newEntryWindow;
    newEntryWindow.setModal(true);
    newEntryWindow.exec();
}

void DatabaseOpenWindow::on_SpecificTimeRadioButton_toggled(bool checked)
{
    ui->YearCheckbox->setEnabled(checked);
    bool enabledYears = checked && ui->YearCheckbox->isChecked();
    ui->YearsList->setEnabled(enabledYears);
    ui->MonthCheckbox->setEnabled(enabledYears);
    bool enabledMonths = enabledYears && ui->MonthCheckbox->isChecked();
    ui->MonthsList->setEnabled(enabledMonths);
    ui->DayCheckbox->setEnabled(enabledMonths);
    bool enabledDays = enabledMonths && ui->DayCheckbox->isChecked();
    ui->DaysList->setEnabled(enabledDays);
}

void DatabaseOpenWindow::on_YearCheckbox_toggled(bool checked)
{
    ui->YearsList->setEnabled(checked);
    ui->MonthCheckbox->setEnabled(checked);
    if (!checked){
        ui->MonthCheckbox->setChecked(false);
    }
}

void DatabaseOpenWindow::on_MonthCheckbox_toggled(bool checked)
{
    ui->MonthsList->setEnabled(checked);
    ui->DayCheckbox->setEnabled(checked);
    if (!checked){
        ui->DayCheckbox->setChecked(false);
    }
}

void DatabaseOpenWindow::on_DayCheckbox_toggled(bool checked)
{
    ui->DaysList->setEnabled(checked);
}
