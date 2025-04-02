#include "newmealplandialog.h"
#include "ui_newmealplandialog.h"

NewMealPlanDialog::NewMealPlanDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewMealPlanDialog)
{
    ui->setupUi(this);
}

NewMealPlanDialog::~NewMealPlanDialog()
{
    delete ui;
}

QString NewMealPlanDialog::getName() const
{
    return (*ui).lineEdit->text();
}

QDate NewMealPlanDialog::getStartDate() const {
    return ui->dateEdit->date();
}

QDate NewMealPlanDialog::getEndDate() const {
    return ui->dateEdit_2->date();
}
