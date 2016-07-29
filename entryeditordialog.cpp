#include "entryeditordialog.h"
#include "ui_entryeditordialog.h"

EntryEditorDialog::EntryEditorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryEditorDialog)
{
    ui->setupUi(this);
}

EntryEditorDialog::~EntryEditorDialog()
{
    delete ui;
}

void EntryEditorDialog::on_AddExpenseButton_clicked()
{
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
