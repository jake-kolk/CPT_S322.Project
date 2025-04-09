#ifndef NEWMEALPLANDIALOG_H
#define NEWMEALPLANDIALOG_H

#include <QDialog>
#include <recipe.h>

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

private:
    Ui::NewMealPlanDialog *ui;

};

#endif // NEWMEALPLANDIALOG_H
