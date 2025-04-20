#include "grocerylist.h"

groceryList::groceryList(QString name, std::vector<recipe::recipeIngredientStruct*>* ingredeints)
{
    this->name = name;
    this->ingredients = ingredeints;
}

groceryList::groceryList(QString name)
{
    this->ingredients = new std::vector<recipe::recipeIngredientStruct*>();
    this->name = name;
}

groceryList::groceryList(QJsonObject groceryListOBJ )
{
    QString name = groceryListOBJ["name"].toString();
    this->name = name;
    recipe::recipeIngredientStruct* ingredientStruct;
    std::vector<recipe::recipeIngredientStruct*>* ingredientVector = new std::vector<recipe::recipeIngredientStruct*>;
    QJsonArray ingredients = groceryListOBJ["ingredients"].toArray();
    for (const auto ingredient : ingredients) {
        if (!ingredient.isObject()) continue;
        QJsonObject ingredientObj = ingredient.toObject();

        ingredientStruct = new recipe::recipeIngredientStruct;

        double ingredientName = ingredientObj["quantity"].toDouble();
        ingredientStruct->amount = ingredientName;

        QString quantity = ingredientObj["unit"].toString();
        ingredientStruct->units = quantity;

        QString unit = ingredientObj["name"].toString();
        ingredientStruct->ingredient = unit;

        ingredientVector->push_back(ingredientStruct);
    }
    this->ingredients = ingredientVector;
}

void groceryList::addItem(double amount, QString units, QString name)
{
    recipe::recipeIngredientStruct* s = new recipe::recipeIngredientStruct;
    s->amount = amount;
    s->units = units;
    s->ingredient = name;
    this->ingredients->push_back(s);
}

void groceryList::addItem(recipe::recipeIngredientStruct* r)
{
    this->ingredients->push_back(r);
}

void groceryList::removeItem(QString name)
{
    auto& items = *this->ingredients;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->ingredient.compare(name, Qt::CaseInsensitive) == 0) {
            delete *it;
            items.erase(it);
            break;
        }
    }
}


void groceryList::modifyItem(QString itemNameToBeModified, double newAmount)
{

}
void groceryList::modifyItem(QString itemNameToBeModified, QString newUnits)
{

}


QJsonObject* groceryList::makeListObject()
{
    QJsonArray ingredients;
    QJsonObject* groceryListOBJ = new QJsonObject;
    (*groceryListOBJ)["name"] = this->name;

    for(unsigned long j = 0; j < this->ingredients->size(); j++)//for all recipes in those days
    {
        ingredients.append(QJsonObject{{"quantity", (*(*this->ingredients)[j]).amount},
                                       {"unit", (*(*this->ingredients)[j]).units},
                                       {"name", (*(*this->ingredients)[j]).ingredient }});
    }
    (*groceryListOBJ)["ingredients"] = ingredients;
    while(ingredients.count()) {//remove all elements for next interation
        ingredients.pop_back();
    }
    return groceryListOBJ;
}
