/**
 * @file        recipe.h
 * @brief       define recipe class attributes and behavior
 * @author      Jacob Kolk
 * @date        2025-3-7
 */

#ifndef RECIPE_H
#define RECIPE_H
#include <QString>
#include <QUrl>
#include <QDebug>
class recipe
{
public:
    struct recpieIngredientStruct{
        double amount;
        QString units;
        QString ingredient;
    };
    int recipeID;
    QUrl recipeURL;
    QString title;
    std::vector<recpieIngredientStruct*>* ingredients;
    int servings;
    double calories;
    QUrl imageURL;
    QString description;

    recipe(int id, QUrl inRecipeURL, QString inTitle, std::vector<recpieIngredientStruct*>* inIngredients,
           int inServings, double inCalories, QUrl inImageURL, QString inDescription)
    {
        this->recipeID = id;
        this->recipeURL = inRecipeURL;
        this->title = inTitle;
        this->ingredients = inIngredients;
        this->servings = inServings;
        this->calories = inCalories;
        this->imageURL = inImageURL;
        this->description = inDescription;
    }
    void printRecipeToDebug();

};
#endif // RECIPE_H

