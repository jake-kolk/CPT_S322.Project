#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipesearch.h"
#include "addapikeydialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Loading json data...\n";
    this->savedRecipes = new std::vector<recipe*>;
    loadDataFromJson(QString("")); // QString("") means default location
    addSavedRecipesToList();

    //set combox box option for search filters
    QStringList cuisines =     {"All Cuisines", "African", "Asian", "American", "British", "Cajun", "Caribbean", "Chinese", "Eastern European", "European",
     "French",  "German", "Greek", "Indian", "Irish", "Italian", "Japanese", "Jewish", "Korean", "Latin American", "Mediterranean",
                            "Mexican", "Middle Eastern", "Nordic", "Southern", "Spanish", "Thai", "Vietnamese"};
    QStringList diets = {"All diets", "Gluten Free", "Ketogenic", "Vegetarian", "Lacto-Vegetarian", "Ovo-Vegetarian", "Vegan", "Pescetarian", "Paleo", "Primal",
                     "Low FODMAP", "Whole30"};
    QStringList types = {"All meal Types", "main course","side dis", "dessert", "appetizer", "salad", "bread", "breakfast", "soup", "beverage", "sauce",
                         "marinade", "fingerfood", "snack", "drink"};
    this->ui->cuisineComboBox->addItems(cuisines);
    this->ui->dietComboBox->addItems(diets);
    this->ui->mealTypeComboBox->addItems(types);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchButton_clicked()
{
    qDebug() << "Search Button Clicked";
    QString search = ui->recipeSearchbox->text();
    recipeSearch searchEngine(this->APIKEY);


    std::vector<QString> ingredients = {};  // search by ingredient, temp stuff in the now for proof of concept

    QString cuisine = "";
    QString mealType = "";
    QString diet = "";
    QString query = "";
    if(this->ui->cuisineComboBox->currentText() != QString("All cuisines"))//check all combo boxed for their selection
    {
        cuisine = this->ui->cuisineComboBox->currentText();
    }
    if(this->ui->dietComboBox->currentText() != QString("All diets"))
    {
        diet = this->ui->dietComboBox->currentText();
    }
    if(this->ui->mealTypeComboBox->currentText() != QString("All meal types"))
    {
        mealType = this->ui->mealTypeComboBox->currentText();
    }
    if(this->ui->recipeSearchbox->text() != QString(""))
    {
        query = this->ui->recipeSearchbox->text();
    }
    std::vector<recipe*>* results = searchEngine.makeRequest(cuisine, ingredients, diet, mealType, 20, query);

    ui->searchResult->clear();//update search list
    for (recipe* r : *results)
    {
        QListWidgetItem* item = new QListWidgetItem(r->title, ui->searchResult);
        item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
    }
    this->foundRecipes = results;
}

void MainWindow::on_item_clicked()
{

}

void MainWindow::on_addGrocery_clicked()
{

}


void MainWindow::on_removeGrocery_clicked()
{

}

void MainWindow::on_grocerySelect_currentIndexChanged(int index)
{

}


void MainWindow::on_removeMealPlan_clicked()
{

}


void MainWindow::on_addMealPlan_clicked()
{

}

void MainWindow::on_saveRecipeButton_clicked()
{
<<<<<<< Updated upstream
    if (selectedRecipe)
    {
        QListWidgetItem* item = new QListWidgetItem(selectedRecipe->title, ui->savedRecipesList);
        item->setData(Qt::UserRole, QVariant::fromValue(selectedRecipe));
    }
    this->savedRecipes->push_back(selectedRecipe);
=======
    if(this->selectedRecipe == nullptr)return;
    this->savedRecipes->push_back(selectedRecipe);
    addSavedRecipesToList();
>>>>>>> Stashed changes
}




<<<<<<< Updated upstream
void MainWindow::on_savedRecipeList_itemActivated(QListWidgetItem *item)
{
    QVariant data = item->data(Qt::UserRole);
    recipe* savedRecipe = data.value<recipe*>();  // rSetrieve stored recipe

    if (savedRecipe)
    {
        ui->savedRecipeName->setText(savedRecipe->title);
        ui->savedRecipeDesc->setText(savedRecipe->description);
    }

}

=======
>>>>>>> Stashed changes

void MainWindow::on_deleteRecipeButton_clicked()
{

}

void MainWindow::on_addAPIKeyButton_triggered()
{
    addAPIKeyDialog w(this);
    w.exec();
    this->APIKEY = w.getAPIKey();
    qDebug() << "API key is now: " << this->APIKEY;


}


void MainWindow::on_mealPlanSelect_currentIndexChanged(int index)
{

}



void MainWindow::on_recipeSearchbox_returnPressed()
{
    on_searchButton_clicked();
}


void MainWindow::loadDataFromJson(QString filepath)
{
    if(filepath == "") filepath = "data.json";
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file for reading: " << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        qWarning() << "Invalid JSON format!";
        return;
    }

    QJsonArray rootArray = jsonDoc.array();

    // Extract API Key
    if (!rootArray.isEmpty() && rootArray[0].isObject()) {
        QJsonObject apiKeyObject = rootArray[0].toObject();
        QString apiKey = apiKeyObject.value("APIKEY").toString();

        this->APIKEY = apiKey;
        qDebug() << "API Key:" << apiKey;
    }
    this->savedRecipes = new std::vector<recipe*>;
    recipe* loadedRecipe;
    recipe::recipeIngredientStruct* ingredientStruct;
    std::vector<recipe::recipeIngredientStruct*>* ingredientVector;

    // Extract Recipes
    if (rootArray.size() > 1 && rootArray[1].isArray()) {
        QJsonArray recipesArray = rootArray[1].toArray();

        for (const QJsonValue &recipeValue : recipesArray) {
            if (!recipeValue.isObject()) continue;
            QJsonObject recipeObj = recipeValue.toObject();

            QString title = recipeObj["title"].toString();
            int servings = recipeObj["servings"].toInt();
            double calories = recipeObj["calories"].toDouble();
            QString description = recipeObj["description"].toString();
            QString imageURL = recipeObj["imageURL"].toString();
            QString recipeURL = recipeObj["recipeURL"].toString();
            int recipeID = recipeObj["recipeID"].toInt();

            //qDebug() << "\nRecipe Title:" << title;
            //qDebug() << "Servings:" << servings;
            //qDebug() << "Calories:" << calories;
            //qDebug() << "Description:" << description;
            //qDebug() << "Image URL:" << imageURL;
            //qDebug() << "Recipe URL:" << recipeURL;
            //qDebug() << "Recipe ID:" << recipeID;

            // Extract Ingredients
            if (recipeObj.contains("ingredients") && recipeObj["ingredients"].isArray()) {
                QJsonArray ingredientsArray = recipeObj["ingredients"].toArray();

                ingredientVector = new std::vector<recipe::recipeIngredientStruct*>;

                //qDebug() << "Ingredients:";
                for (const QJsonValue &ingredientValue : ingredientsArray) {
                    if (!ingredientValue.isObject()) continue;
                    QJsonObject ingredientObj = ingredientValue.toObject();

                    ingredientStruct = new recipe::recipeIngredientStruct;

                    QString ingredientName = ingredientObj["name"].toString();
                    ingredientStruct->ingredient = ingredientName;

                    double quantity = ingredientObj["quantity"].toDouble();
                    ingredientStruct->amount = quantity;

                    QString unit = ingredientObj["unit"].toString();
                    ingredientStruct->units = unit;

                    //qDebug() << "  -" << ingredientName << ":" << quantity << unit;

                    ingredientVector->push_back(ingredientStruct);
                }
            }
            loadedRecipe = new recipe(recipeID, recipeURL, title, ingredientVector,
                                     servings, calories,  imageURL,  description);
            this->savedRecipes->push_back(loadedRecipe);
        }
    }

}

void MainWindow::saveDatatoJson()
{
    QJsonObject* recipeOBJ = new QJsonObject;
    class recipe* currentRecipe;
    QJsonArray recipes;
    QJsonArray savedData;
    QJsonArray ingredients;

    QJsonObject apikeyOBJ;
    apikeyOBJ["APIKEY"] = this->APIKEY;
    savedData.append(apikeyOBJ);

    if(this->savedRecipes != nullptr){
        for(unsigned long i = 0; i < this->savedRecipes->size(); i++)
        {
            currentRecipe = (*this->savedRecipes)[i];
            (*recipeOBJ)["title"] = currentRecipe->title;
            (*recipeOBJ)["recipeID"] = currentRecipe->recipeID;
            (*recipeOBJ)["recipeURL"] = currentRecipe->recipeURL.toString();
            (*recipeOBJ)["servings"] = currentRecipe->servings;
            (*recipeOBJ)["calories"] = currentRecipe->calories;
            (*recipeOBJ)["imageURL"] = currentRecipe->imageURL.toString();
            (*recipeOBJ)["description"] = currentRecipe->description;
            for(unsigned long j = 0; j < currentRecipe->ingredients->size(); j++)
            {
                ingredients.append(QJsonObject{{"quantity", (*(*currentRecipe->ingredients)[j]).amount},
                                                {"unit", (*(*currentRecipe->ingredients)[j]).units},
                                                {"name", (*(*currentRecipe->ingredients)[j]).ingredient }});
            }
            (*recipeOBJ)["ingredients"] = ingredients;
            while(ingredients.count()) {//remove all elements fro next interation
                ingredients.pop_back();
            }
            recipes.append(*recipeOBJ);
        }
        savedData.append(recipes);
    }
    MealPlan currentPlan;
    QJsonArray mealPlans;
    QJsonObject* mealPlanObj = new QJsonObject;
    if(this->mealPlans.size())
    {
        for(unsigned long i = 0; i < mealPlans.size(); i++)
        {
            currentPlan = this->mealPlans[i];
            (*mealPlanObj)["title"] = currentPlan.getName();
            (*mealPlanObj)["startDate"] = currentPlan.getStartDate().toString();
            (*mealPlanObj)["endDate"] = currentPlan.getEndDate().toString();
            mealPlans.append(*mealPlanObj);
        }
    }
    QJsonDocument jsonDoc(savedData);

    QFile file("data.json");

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open file for writing: " << file.errorString();
        return;
    }

    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();

    qDebug() << "JSON file saved successfully at:" << QFileInfo(file).absoluteFilePath();

    delete recipeOBJ;
    delete mealPlanObj;

}

void MainWindow::addSavedRecipesToList()
{
    ui->savedRecipesList->clear();
    for (recipe* r : (*this->savedRecipes))
    {
        if(r == nullptr) return;
        QListWidgetItem* item = new QListWidgetItem(r->title, ui->savedRecipesList);
        item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
    }
}

void MainWindow::updateSavedRecipesListWithSearch(QString search)
{
    ui->savedRecipesList->clear();
    for (recipe* r : (*this->savedRecipes))
    {
        if(r == nullptr) return;
        if(r->title.toUpper().contains(search)){
            QListWidgetItem* item = new QListWidgetItem(r->title, ui->savedRecipesList);
            item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
        }
    }
}
void MainWindow::closeEvent(QCloseEvent *event) {

    qDebug() << "MainWindow is closing! Performing cleanup...";

    saveDatatoJson();

    event->accept();
}

void MainWindow::on_savedRecipesList_itemClicked(QListWidgetItem *item)
{
    QVariant data = item->data(Qt::UserRole);
    selectedRecipe = data.value<recipe*>();  // Store selected recipe

    if (selectedRecipe)
    {
        ui->savedRecipeName->setText(selectedRecipe->title);
        ui->savedRecipeDesc->setText(selectedRecipe->description);

        // testing
        ui->savedRecipeURL->setText(selectedRecipe->recipeURL.toString());
        ui->savedRecipeServings->setText(QString::number(selectedRecipe->servings));
        ui->savedRecipeCalPerSevings->setText(QString::number(selectedRecipe->calories));

        //ui->recipeImage->scene()->clear();
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QUrl imageUrl(selectedRecipe->imageURL.toString());

        QNetworkReply *reply = manager->get(QNetworkRequest(imageUrl));
        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QPixmap pixmap;
                pixmap.loadFromData(reply->readAll());

                QGraphicsScene *scene = new QGraphicsScene(this);
                scene->addPixmap(pixmap);

                ui->savedRecipeImage->setScene(scene);
                ui->savedRecipeImage->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
            } else {
                qDebug() << "Failed to load image:" << reply->errorString();
            }
            reply->deleteLater();
        });
        ui->savedRecipeIngredientTable->setRowCount(0); //reset table
        for (auto* ingredient : *(selectedRecipe->ingredients)) {
            int row = ui->savedRecipeIngredientTable->rowCount();
            ui->savedRecipeIngredientTable->insertRow(row);


            ui->savedRecipeIngredientTable->setItem(row, 0, new QTableWidgetItem(QString::number(ingredient->amount)));
            ui->savedRecipeIngredientTable->setItem(row, 1, new QTableWidgetItem(ingredient->units));
            ui->savedRecipeIngredientTable->setItem(row, 2, new QTableWidgetItem(ingredient->ingredient));
        }
    }
}


void MainWindow::on_searchResult_itemClicked(QListWidgetItem *item)
{
    QVariant data = item->data(Qt::UserRole);
    this->selectedRecipe = data.value<recipe*>();  // Store selected recipe
    if (selectedRecipe)
    {
        ui->recipeName->setText(selectedRecipe->title);
        ui->recipeDesc->setText(selectedRecipe->description);

        // testing
        ui->recipeURL->setText(selectedRecipe->recipeURL.toString());
        ui->recipeServings->setText(QString::number(selectedRecipe->servings));
        ui->recipeCalPerSevings->setText(QString::number(selectedRecipe->calories));

        //ui->recipeImage->scene()->clear();
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QUrl imageUrl(selectedRecipe->imageURL.toString());

        QNetworkReply *reply = manager->get(QNetworkRequest(imageUrl));
        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QPixmap pixmap;
                pixmap.loadFromData(reply->readAll());

                QGraphicsScene *scene = new QGraphicsScene(this);
                scene->addPixmap(pixmap);

                ui->recipeImage->setScene(scene);
                ui->recipeImage->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
            } else {
                qDebug() << "Failed to load image:" << reply->errorString();
            }
            reply->deleteLater();
        });
        ui->recipeIngredientTable->setRowCount(0); //reset table
        for (auto* ingredient : *(selectedRecipe->ingredients)) {
            int row = ui->recipeIngredientTable->rowCount();
            ui->recipeIngredientTable->insertRow(row);


            ui->recipeIngredientTable->setItem(row, 0, new QTableWidgetItem(QString::number(ingredient->amount)));
            ui->recipeIngredientTable->setItem(row, 1, new QTableWidgetItem(ingredient->units));
            ui->recipeIngredientTable->setItem(row, 2, new QTableWidgetItem(ingredient->ingredient));
        }
    }
}

void MainWindow::on_deleteSavedRecipesButton_clicked()
{
    QList<QListWidgetItem*> deletedItems = this->ui->savedRecipesList->selectedItems();
    recipe* recipeToDelete = deletedItems[0]->data(Qt::UserRole).value<recipe*>();
    qDebug() << "Found " << deletedItems.size() << " item(s) to delete";
    if(deletedItems.size() != 0)
    {
        QListWidgetItem* deletedItem = deletedItems[0];
        QVariant data = deletedItem->data(Qt::UserRole);
        selectedRecipe = data.value<recipe*>();
        QString titleToRemove = QString(selectedRecipe->title);
        for (auto it = savedRecipes->begin(); it != savedRecipes->end();) {
            if (recipeToDelete == *it) {
                delete *it;  // Free memory before erasing
                it = savedRecipes->erase(it);  // Erase returns next valid iterator
                this->savedRecipes->shrink_to_fit();
                addSavedRecipesToList();//to update list
                return;
            } else {
                ++it;
            }
        }

    }
    else return; //if no item selected return

}


void MainWindow::on_savedRecipeName_textChanged(const QString &arg1)
{
    this->selectedRecipe->title = arg1;
}


void MainWindow::on_savedRecipeURL_textChanged(const QString &arg1)
{
    this->selectedRecipe->recipeURL = arg1;
}


void MainWindow::on_savedRecipeDesc_textChanged()
{
    this->selectedRecipe->description = this->ui->savedRecipeDesc->toPlainText();
}


void MainWindow::on_savedRecipeServings_textChanged(const QString &arg1)
{
    this->selectedRecipe->servings = arg1.toInt();
}


void MainWindow::on_savedRecipeCalPerSevings_textChanged(const QString &arg1)
{
    this->selectedRecipe->calories = arg1.toDouble();
}


void MainWindow::on_savedRecipeIngredientTable_cellChanged(int row, int column)
{
    /*
    std::vector<recipe::recipeIngredientStruct*>* selectedRecipeIngredientStruct = selectedRecipe->ingredients;
    (*selectedRecipeIngredientStruct)[row]->ingredient = this->ui->recipeIngredientTable->item(row, column)->text();
*/
}


void MainWindow::on_savedRecipeIngredientTable_itemChanged(QTableWidgetItem *item)
{
    /*
    int row = this->ui->savedRecipeIngredientTable->row(item);  // Get the row
    int column =  this->ui->savedRecipeIngredientTable->column(item);  // Get the column
    std::vector<recipe::recipeIngredientStruct*>* selectedRecipeIngredientStruct = selectedRecipe->ingredients;
    (*selectedRecipeIngredientStruct)[row]->ingredient = this->ui->recipeIngredientTable->item(row, column)->text();
*/
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    this->selectedRecipe = nullptr;
}


void MainWindow::on_cloneSavedRecipeButton_clicked()
{
    if(selectedRecipe == nullptr) return;
    this->savedRecipes->push_back(selectedRecipe->createClone());
    this->selectedRecipe = nullptr;
    addSavedRecipesToList();
}


void MainWindow::on_searchSavedRecipesBox_textChanged(const QString &arg1)
{
    updateSavedRecipesListWithSearch(arg1.toUpper());
}

