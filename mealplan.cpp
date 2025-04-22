#include "mealplan.h"

QString MealPlan::getName() const {
    return name;
}

MealPlan::MealPlan(QString name){
    this->name = name;
    this->mealPlan = new std::unordered_map<QString,std::vector<recipe*>>;
}

void MealPlan::setName(const QString &name) {
    this->name = name;
}

recipe* MealPlan::getRecipesAt(QDate date){
    return nullptr;//change this later
}

void MealPlan::addRecipe(QDate date, recipe* r){
    if(this->mealPlan == nullptr) return;
    (*this->mealPlan)[date.toString()].push_back(r);
}

void MealPlan::removeRecipe(QDate date, recipe* recipe){
    if(recipe == nullptr)return;
    for (auto it = (*this->mealPlan)[date.toString()].begin(); it != (*this->mealPlan)[date.toString()].end();) {
        if (*recipe == **it) {
        //delete *it;  // Free memory before erasing
        it = (*this->mealPlan)[date.toString()].erase(it);  // Erase returns next valid iterator
        (*this->mealPlan)[date.toString()].shrink_to_fit();
        return;
        }else
        {
            ++it;
        }
    }
}
void MealPlan::clearDate(QDate date){

}
