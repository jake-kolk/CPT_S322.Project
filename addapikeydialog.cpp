#include "addapikeydialog.h"
#include "ui_addapikeydialog.h"

addAPIKeyDialog::addAPIKeyDialog(QWidget *parent, QString APIKEY)
    : QDialog(parent)
    , ui(new Ui::addAPIKeyDialog)
{
    ui->setupUi(this);
    this->ui->APIKeyTextEdit->setText(APIKEY);
}

addAPIKeyDialog::~addAPIKeyDialog()
{
    delete ui;
}

void addAPIKeyDialog::on_buttonBox_accepted()
{
    this->APIKEY = QString(this->ui->APIKeyTextEdit->toPlainText());
}

QString addAPIKeyDialog::getAPIKey()
{
    return this->APIKEY;
}
