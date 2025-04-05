
#ifndef RECIPE_H
#define RECIPE_H
#include <QString>
#include <QUrl>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
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
    recipe*  createClone();
    bool operator==(const recipe& other) const {
        if(this->recipeID == other.recipeID)
        {
            if(this->recipeURL == other.recipeURL)
            {
                if(this->calories == this->calories)
                {
                    if(this->servings == other.servings)
                    {
                        if(this->description == other.description)
                        {
                            if(this->title == other.title){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    recipe* clone(){
        recipe* newRecipe = new recipe(this->recipeID, this->recipeURL, this->title, this->ingredients,
                                       this->servings, this->calories,this->imageURL, this->description);
        return newRecipe;
    }
    QJsonObject* makeRecipeObject();

};

#endif // RECIPE_H


