
#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <QString>
#include <QDate>

class MealPlan
{
public:
    MealPlan();
    MealPlan(const QString &name, const QDate &startDate, const QDate &endDate);

    QString getName() const;
    void setName(const QString &name);

    QDate getStartDate() const;
    void setStartDate(const QDate &startDate);

    QDate getEndDate() const;
    void setEndDate(const QDate &endDate);

private:
    QString name;
    QDate startDate;
    QDate endDate;
};

#endif // MEALPLAN_H
