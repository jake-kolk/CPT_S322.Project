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
