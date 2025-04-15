#ifndef GROCERYLIST_H
#define GROCERYLIST_H
#include "recipe.h"
class groceryList
{
public:
    std::vector<recipe::recipeIngredientStruct*>* ingredients;
    QString name;

    groceryList(QString name, std::vector<recipe::recipeIngredientStruct*>* ingredeints);
    groceryList(QString name);
    groceryList(QJsonObject groceryListOBJ);
    void addItem(double amount, QString units, QString name);
    void addItem(recipe::recipeIngredientStruct* newItem);
    void removeItem(QString name);
    void modifyItem(QString itemNameToBeModified, double newAmount);
    void modifyItem(QString itemNameToBeModified, QString newUnits);
    QJsonObject* makeListObject();
};

#endif // GROCERYLIST_H
