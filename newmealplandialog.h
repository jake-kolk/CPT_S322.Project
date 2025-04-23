#ifndef NEWMEALPLANDIALOG_H
#define NEWMEALPLANDIALOG_H

#include <QDialog>
#include <recipe.h>
#include <QMessageBox>
namespace Ui {
class NewMealPlanDialog;
}

class NewMealPlanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMealPlanDialog(QWidget *parent = nullptr);//mode = 0 for user, mode = 1 for system
    explicit NewMealPlanDialog(QString name);
    ~NewMealPlanDialog();
    QString getName() const;
    QDate getStartDate() const;
    QDate getEndDate() const;


    QString name;

private slots:
    void on_buttonBox_accepted();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::NewMealPlanDialog *ui;
protected:
    void accept() override {
        if (this->name.isEmpty()) {
            QMessageBox::warning(this, "Error", "You must enter a name!!");
            return; // Don't close dialog
        }
        QDialog::accept(); // Accept and close
    }

};

#endif // NEWMEALPLANDIALOG_H
