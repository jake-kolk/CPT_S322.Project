
#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <QString>
#include <QDate>
#include "recipe.h"
class MealPlan
{
public:
    MealPlan();
    MealPlan(const QString &name, const QDate &startDate, const QDate &endDate);
    MealPlan(QString name);

    QString getName() const;
    void setName(const QString &name);

    QDate getStartDate() const;
    void setStartDate(const QDate &startDate);

    QDate getEndDate() const;
    void setEndDate(const QDate &endDate);
    std::unordered_map<QString,std::vector<recipe*>>* mealPlan;
    recipe* getRecipesAt(QDate date);
    void addRecipe(QDate date, recipe* r);
    void removeRecipe(QDate date, recipe* r);
    void clearDate(QDate date);
    bool operator==(const MealPlan& other) const {
        if(this->startDate == other.startDate)
        {
            if(this->endDate == other.endDate)
            {
                if(this->name == other.name)
                {
                    if(this->mealPlan->size() == other.mealPlan->size())
                    {
                        for(auto& day : (*this->mealPlan))
                        {
                            for(auto meal : day.second)
                            {

                            }
                        }
                    }
                }
            }
        }
        return false;
    }
private:
    QString name;
    QDate startDate;
    QDate endDate;
};
Q_DECLARE_METATYPE(MealPlan)
#endif // MEALPLAN_H
