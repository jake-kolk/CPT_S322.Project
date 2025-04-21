/**
 * @file        recipeSearch.h
 * @brief       define how the recipe searches work
 * @author      Jacob Kolk
 * @date        2025-3-7
 */
#ifndef RECIPESEARCH_H
#define RECIPESEARCH_H

#include <QObject>
#include <QEventLoop>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>
#include <QProgressBar>

#include "recipe.h"
#include "search.h"
#include "mainwindow.h"

class recipeSearch : public search
{
private:
    std::vector<recipe*>* handleResponse(QNetworkReply *reply);
public:
    struct recipeSearchReturn{
        int recipeID;
        QUrl recipeURL;
        QString recipeTitle;
    };

    explicit recipeSearch(QString key) : search(key)
    {
        this->ApiKey = key;
    };
    virtual ~recipeSearch(){}; // Virtual destructor
    std::vector<recipe*>* makeRequest(QString cuisine, std::vector<QString> ingredients, QString diet, QString mealType, int numOfRecipes, QString query, QProgressBar* progressBar, QString sort="");
};

#endif // RECIPESEARCH_H
