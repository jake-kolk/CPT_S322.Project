#ifndef NEWMEALPLANDIALOG_H
#define NEWMEALPLANDIALOG_H

#include <QDialog>

namespace Ui {
class NewMealPlanDialog;
}

class NewMealPlanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMealPlanDialog(QWidget *parent = nullptr);
    ~NewMealPlanDialog();
    QString getName() const;
    QDate getStartDate() const;
    QDate getEndDate() const;

private:
    Ui::NewMealPlanDialog *ui;
};

#endif // NEWMEALPLANDIALOG_H
