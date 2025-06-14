#include "recipesearch.h"
#include "QMessageBox"
std::vector<recipe*>* recipeSearch::makeRequest(QString cuisine, std::vector<QString> ingredients, QString diet, QString mealType, int NumRecipes, QString searchQuery, QProgressBar *progressBar, QString sort) {
    QUrl url("https://api.spoonacular.com/recipes/complexSearch");
    //https://api.spoonacular.com/recipes/complexSearch
    QUrlQuery query;

    progressBar->setVisible(true);
    progressBar->setValue(0);

    query.addQueryItem("apiKey", this->ApiKey);
    query.addQueryItem("number", QString::number(NumRecipes));  // Request multiple recipes
    if(sort != "") query.addQueryItem("sort", sort);
    query.addQueryItem("addRecipeInformation", "true");
    query.addQueryItem("addRecipeNutrition", "true");
    query.addQueryItem("addRecipeInstructions", "true");
    query.addQueryItem("number", QString::number(NumRecipes));
    QString CSingredients;
    for (const auto& ingredient : ingredients) {
        bool isNumeric;
        ingredient.toInt(&isNumeric);
        if (!isNumeric) {
            CSingredients.append(ingredient);
            CSingredients.append(",");
        }
    }

    progressBar->setValue(10);

    if (!CSingredients.isEmpty()) {
        CSingredients.chop(1);
        query.addQueryItem("includeIngredients", CSingredients);
    }

    progressBar->setValue(20);

    if (!diet.isEmpty()) query.addQueryItem("diet", diet);
    if (!cuisine.isEmpty()) query.addQueryItem("cuisine", cuisine);
    if (!mealType.isEmpty()) query.addQueryItem("type", mealType);
    if(searchQuery != "") query.addQueryItem("query", searchQuery);
    url.setQuery(query);

    progressBar->setValue(40);

    qDebug() << "Query: " << url;

    QNetworkRequest request(url);
    qDebug() << "Sending search request for " << NumRecipes << " recipes...";

    progressBar->setValue(50);

    QNetworkReply* reply = manager->get(request);  // Expecting multiple recipes

    // **Wait for reply synchronously**
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();  // Blocks execution until the request is complete

    //added in case there is no response
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->start(7000); // Timeout in (7 seconds)

    connect(timer, &QTimer::timeout, this, [=]() {
        if (reply->isRunning()) {
            reply->abort();  // Cancel the request
            qDebug() << "Request timed out.";
            QMessageBox::information(nullptr, "Error", "Search request timed out!");
            return nullptr;
        }
    });

    progressBar->setValue(90);

    qDebug() << "Recipe search request received...";

    // **Process the response and return recipes**
    std::vector<recipe*>* recipes = handleResponse(reply);
    progressBar->setValue(100);
    reply->deleteLater();

    progressBar->setVisible(false);
    progressBar->setValue(0);

    return recipes;  // Return all recipes
}

std::vector<recipe*>* recipeSearch::handleResponse(QNetworkReply* reply) {
    std::vector<recipe*>* recipes = new std::vector<recipe*>;  // Store multiple recipes
    if (!reply) {
        qDebug() << "Error: Null QNetworkReply received!";
        return recipes;
    }

    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::information(nullptr, "Error", reply->errorString());
        qDebug() << "Error: " << reply->errorString();
        return recipes;
    }

    QByteArray responseData = reply->readAll();
    //qDebug() << "Raw response data: " << responseData;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    if (jsonResponse.isNull() || !jsonResponse.isObject()) {
        qDebug() << "Invalid JSON response!";
        QMessageBox::information(nullptr,  "Error", "Invalid esponse!");
        return recipes;
    }

    //qDebug() << "Raw Response Data: " << responseData;

    QJsonObject jsonObject = jsonResponse.object();
    if (jsonObject.contains("results")) {
        QJsonArray results = jsonObject["results"].toArray();
        if (!results.isEmpty()) {
            for (const QJsonValue& value : results) {
                if (!value.isObject()) continue;
                QJsonObject recipeObj = value.toObject();

                QString title = recipeObj["title"].toString(); //get title
                int recipeID = recipeObj["id"].toInt(); //get recipe id
                QUrl recipeURL("https://spoonacular.com/recipes/" + title.replace(" ", "-") + "-" + QString::number(recipeID)); //get recipeURL
                int servings = recipeObj["servings"].toInt();//getServings
                QUrl imageURL = recipeObj["image"].toString();
                QString description = (recipeObj["summary"].toString()).remove(QRegularExpression("<[^>]*>"));

                if (title.isEmpty() || recipeID == 0) continue; //check to make sure we are reading valid recipe

                // Debug output
                //qDebug() << "Recipe: " << title;
                //qDebug() << "Recipe ID: " << recipeID;
                //qDebug() << "URL: " << recipeURL.toString();
                //qDebug() << "Servings: " << servings;
                //qDebug() << "Image URL: " << imageURL;
                //qDebug() << "Decription: " << description;

                std::vector<recipe::recipeIngredientStruct*>* ingredeintVector = new std::vector<recipe::recipeIngredientStruct*>;
                recipe::recipeIngredientStruct* is;
                QJsonObject nutritionObj = recipeObj["nutrition"].toObject();

                QJsonArray nutrientsArray = nutritionObj["nutrients"].toArray();
                QJsonObject caloriesObj = nutrientsArray.first().toObject();
                double calories = caloriesObj["amount"].toDouble();
                //qDebug() << "Calories: " << calories;

                QJsonArray ingredientsArray = nutritionObj["ingredients"].toArray();\

                QString unit;

                // Iterate over ingredients
                //qDebug() << "Ingredients:";
                for (const QJsonValue &ingredientVal : ingredientsArray) {
                    QJsonObject ingredientObj = ingredientVal.toObject();
                    is = new recipe::recipeIngredientStruct;

                    QString name = ingredientObj["name"].toString();
                    QString unit = ingredientObj["unit"].toString();
                    if(name.mid(0,3) == "tsp")// API has error in their DB, tsp is included in name, this fixes it
                    {
                        unit = name.mid(0,3);
                        name.remove(0,4);
                        is->ingredient = name;
                        is->units = unit;
                    }else if(name.mid(0,2) == "pd")// API has error in their DB, pd is included in name, this fixes it
                    {
                        unit = name.mid(0,2);
                        name.remove(0,3);
                        is->ingredient = name;
                        is->units = unit;
                    }else if (unit.toLower() == "teaspoon" || unit.toLower() == "teaspoons")
                    {
                        is->ingredient = name;
                        is->units = "tsp";
                    }
                    else if (unit.toLower() == "tablespoon" || unit.toLower() == "tablespoons")
                    {
                        is->ingredient = name;
                        is->units = "tbsp";
                    }
                    else{
                        is->ingredient = name;
                        QString unit = ingredientObj["unit"].toString();
                        is->units = unit;
                    }

                    double amount = ingredientObj["amount"].toDouble();
                    is->amount = amount;

                    ingredeintVector->push_back(is);
                    //qDebug() << "Ingredient:" << name << "- Amount:" << amount << unit;
                }
                // Create new recipe object and store in the vector
                //(int id, QUrl inRecipeURL, QString inTitle, std::vector<recpieIngredientStruct*>* inIngredients,
                //int inServings, double inCalories, QUrl inImageURL, QString inDescription
                recipe* newRecipe = new recipe(recipeID, recipeURL, title.replace("-", " "), ingredeintVector,
                                                servings, calories, imageURL, description);
                recipes->push_back(newRecipe);
            }
        } else {
            qDebug() << "No recipes found.";
        }
    } else {
        qDebug() << "API response does not contain 'results'.";
    }
    return recipes;
}
