#ifndef ADDAPIKEYDIALOG_H
#define ADDAPIKEYDIALOG_H

#include <QDialog>

namespace Ui {
class addAPIKeyDialog;
}

class addAPIKeyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addAPIKeyDialog(QWidget *parent = nullptr, QString APIKEY = "");
    ~addAPIKeyDialog();
    QString getAPIKey();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addAPIKeyDialog *ui;
    QString APIKEY;
};

#endif // ADDAPIKEYDIALOG_H
