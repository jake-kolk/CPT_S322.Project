
#include "recipe.h"
void recipe::printRecipeToDebug()
{
    qDebug() << "FROM printTORecipe(){";
    qDebug() << "Title: " << this->title;
    qDebug() << "Link to recipe: " << this->recipeURL;
    qDebug() << "Recipe Imgage URL: " << this->imageURL;
    qDebug() << "Servings made: " << this->servings;
    qDebug() << "Calories per serving: " << this->calories;
    qDebug() << "Ingredient list: \n";
    std::vector<recipeIngredientStruct*> v = *(this->ingredients);
    for(unsigned long long i = 0; i < this->ingredients->size(); i++)
        qDebug() << v[i]->amount << v[i]->units<< v[i]->ingredient;
    qDebug() << "}";
}

recipe* recipe::createClone()
{
    recipe* clone = new recipe(this->recipeID, this->recipeURL, this->title, this->ingredients,this->servings, this->calories, this->imageURL, this->description);
    return clone;
}

QJsonObject* recipe::makeRecipeObject()
{
    QJsonArray ingredients;
    QJsonObject* recipeOBJ = new QJsonObject;
    (*recipeOBJ)["title"] = this->title;
    (*recipeOBJ)["recipeID"] = this->recipeID;
    (*recipeOBJ)["recipeURL"] = this->recipeURL.toString();
    (*recipeOBJ)["servings"] = this->servings;
    (*recipeOBJ)["calories"] = this->calories;
    (*recipeOBJ)["imageURL"] = this->imageURL.toString();
    (*recipeOBJ)["description"] = this->description;
    for(unsigned long j = 0; j < this->ingredients->size(); j++)//for all recipes in those days
    {
        ingredients.append(QJsonObject{{"quantity", (*(*this->ingredients)[j]).amount},
                                       {"unit", (*(*this->ingredients)[j]).units},
                                       {"name", (*(*this->ingredients)[j]).ingredient }});
    }
    (*recipeOBJ)["ingredients"] = ingredients;
    while(ingredients.count()) {//remove all elements for next interation
        ingredients.pop_back();

    }
    return recipeOBJ;
}
