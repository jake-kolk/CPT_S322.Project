#include "mealplan.h"

MealPlan::MealPlan() {}

MealPlan::MealPlan(const QString &name, const QDate &startDate, const QDate &endDate)
    : name(name), startDate(startDate), endDate(endDate) {}

QString MealPlan::getName() const {
    return name;
}

void MealPlan::setName(const QString &name) {
    this->name = name;
}

QDate MealPlan::getStartDate() const {
    return startDate;
}

void MealPlan::setStartDate(const QDate &startDate) {
    this->startDate = startDate;
}

QDate MealPlan::getEndDate() const {
    return endDate;
}

void MealPlan::setEndDate(const QDate &endDate) {
    this->endDate = endDate;
}
