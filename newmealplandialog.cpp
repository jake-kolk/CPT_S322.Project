#include "newmealplandialog.h"
#include "ui_newmealplandialog.h"

NewMealPlanDialog::NewMealPlanDialog(QWidget *parent)//mode = 0 for user mode = 1 for system
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

void NewMealPlanDialog::on_buttonBox_accepted()
{
    this->name = this->ui->lineEdit->text();
}

