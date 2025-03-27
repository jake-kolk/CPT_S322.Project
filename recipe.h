#ifndef RECIPE_H
#define RECIPE_H
#include <QString>
#include <QUrl>
#include <QDebug>

class recipe
{
public:
    struct recipeIngredientStruct{
        double amount;
        QString units;
        QString ingredient;
    };
    int recipeID;
    QUrl recipeURL;
    QString title;
    std::vector<recipeIngredientStruct*>* ingredients;
    int servings;
    double calories;
    QUrl imageURL;
    QString description;

    recipe(int id, QUrl inRecipeURL, QString inTitle, std::vector<recipeIngredientStruct*>* inIngredients,
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



