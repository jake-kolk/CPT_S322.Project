#include "newmealplandialog.h"
#include "ui_newmealplandialog.h"
#include <QPushButton>

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

void NewMealPlanDialog::on_buttonBox_accepted()
{
    this->name = this->ui->lineEdit->text();
}


void NewMealPlanDialog::on_lineEdit_textChanged(const QString &arg1)
{
    this->name = arg1;
}

