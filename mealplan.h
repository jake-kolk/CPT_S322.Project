
#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <QString>
#include <QDate>
#include "recipe.h"
class MealPlan
{
public:
    MealPlan(QString name="default");

    QString getName() const;
    void setName(const QString &name);

    std::unordered_map<QString,std::vector<recipe*>>* mealPlan;
    recipe* getRecipesAt(QDate date);
    void addRecipe(QDate date, recipe* r);
    void removeRecipe(QDate date, recipe* r);
    void clearDate(QDate date);

private:
    QString name;
};
Q_DECLARE_METATYPE(MealPlan)
#endif // MEALPLAN_H
