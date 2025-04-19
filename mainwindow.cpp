#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipesearch.h"
#include "addapikeydialog.h"
#include "mealplan.h"
#include "newmealplandialog.h"
#include "addingredient.h"
#include <QMessageBox>
#include <QTimer>
#include "ScaledLabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Loading json data...\n";
    //get saved recipes
    this->savedRecipes = new std::vector<recipe*>;
    this->groceryLists = std::vector<groceryList*>();
    loadDataFromJson("data.json"); // QString("") means default location
    addSavedRecipesToList();

    this->ui->searchRecipeInfoWidget->setVisible(false);
    this->ui->recipeURL->setVisible(false);

    this->ui->savedRecipeRecipeInfo->setVisible(false);
    this->ui->savedRecipeURL->setVisible(false);

    this->ui->progressBar->setVisible(false); // hide progress bar unless it is active

    //set combox box option for search filters
    QStringList cuisines =     {"All Cuisines", "African", "Asian", "American", "British", "Cajun", "Caribbean", "Chinese", "Eastern European", "European",
     "French",  "German", "Greek", "Indian", "Irish", "Italian", "Japanese", "Jewish", "Korean", "Latin American", "Mediterranean",
                            "Mexican", "Middle Eastern", "Nordic", "Southern", "Spanish", "Thai", "Vietnamese"};
    QStringList diets = {"All diets", "Gluten Free", "Ketogenic", "Vegetarian", "Lacto-Vegetarian", "Ovo-Vegetarian", "Vegan", "Pescetarian", "Paleo", "Primal",
                     "Low FODMAP", "Whole30"};
    QStringList types = {"All meal Types", "Main Course","Side dish", "Dessert", "Appetizer", "Salad", "Bread", "Breakfast", "Soup", "Beverage", "Sauce",
                         "Marinade", "Fingerfood", "Snack", "Drink"};
    this->ui->cuisineComboBox->addItems(cuisines);
    this->ui->dietComboBox->addItems(diets);
    this->ui->mealTypeComboBox->addItems(types);

    //set up search page to display popular recipes on start up
    recipeSearch searchEngine(this->APIKEY);
    std::vector<QString> ingredients = {};

    /*
    std::vector<recipe*>* results = searchEngine.makeRequest("", ingredients, "", "", 20, "", this->ui->progressBar, QString("popularity"));

    foundRecipes = results;
    this->ui->searchResultListLabel->setText("Popular With Users");
    if(this->foundRecipes->size() != 0) selectedRecipe = (*this->foundRecipes)[0];
    updateSearchResultList();*/

    //if(this->ui->searchResult->count() > 0)on_searchResult_itemClicked(this->ui->searchResult->item(0));

    //set up meal plan + meal plan combo box
    if(this->mealPlans.size() == 0)
    {
        this->mealPlans.push_back(new MealPlan("default"));
        this->selectedMealPlan = mealPlans[0];
    }

    updateMealPlanLists();

    //set up grocery lists

    /*
    this->groceryLists.push_back(new groceryList("listDawg"));
    this->selectedGroceryList = this->groceryLists[0];
    this->selectedGroceryList->addItem(3, "pounds", "grapes");
    */
    updateGroceryListList();
    updateGroceryListItems();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProgressBarProgress(bool visability, int progress)
{
    ui->progressBar->setVisible(visability);
    ui->progressBar->setValue(progress);
}

void MainWindow::updateSearchResultList()
{
    ui->searchResult->clear();//update search list
    for (recipe* r : *(this->foundRecipes))
    {
        QListWidgetItem* item = new QListWidgetItem(r->title, ui->searchResult);
        item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
    }
}

void MainWindow::on_searchButton_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    this->ui->searchResultListLabel->setText("Search Results");
    qDebug() << "Search Button Clicked";
    QString search = ui->recipeSearchbox->text();
    recipeSearch searchEngine(this->APIKEY);
    this->ui->recipeSearchbox->setPlaceholderText("Search for Recipes");

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
    foundRecipes = searchEngine.makeRequest(cuisine, ingredients, diet, mealType, 20, query, this->ui->progressBar);
    updateSearchResultList();

    this->ui->searchRecipeInfoWidget->setVisible(false);
    this->ui->recipeURL->setVisible(false);
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_item_clicked()
{

}

void MainWindow::on_addGrocery_clicked()//add grocery list
{
    NewMealPlanDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        if (!name.isEmpty()) {
            this->groceryLists.push_back(new groceryList(name));
            this->ui->grocerySelect->setCurrentIndex(groceryLists.size() - 1);
            statusBar()->showMessage("Created New Grocery List", 2000);
     } else {
            QMessageBox::warning(this, "Empty Name", "Please enter a meal plan name.");
        }
    }
    updateGroceryListList();
    updateGroceryListItems();
}

void MainWindow::updateGroceryListItems()
{

    QTableWidgetItem* item;
    this->ui->groceryIngredientsTable->clear();
    this->ui->groceryIngredientsTable->setRowCount(0);
    if(this->selectedGroceryList == nullptr)return;
    if(this->groceryLists.size() == 0)return;
    if(this->selectedGroceryList->ingredients == nullptr) return;
    for(auto ingredient : *this->selectedGroceryList->ingredients){//for every ingredient in the selected ingredient vector
        int lastRow = 0;
        this->ui->groceryIngredientsTable->insertRow(lastRow);//insert row at bottom

        item = new QTableWidgetItem(QString::number(ingredient->amount));
        item->setData(Qt::UserRole, QVariant::fromValue(&(ingredient->amount)));
        this->ui->groceryIngredientsTable->setItem(lastRow, 0, item);

        item = new QTableWidgetItem(ingredient->units);
        item->setData(Qt::UserRole, QVariant::fromValue(&(ingredient->units)));
        this->ui->groceryIngredientsTable->setItem(lastRow, 1, item);

        item = new QTableWidgetItem(ingredient->ingredient);
        item->setData(Qt::UserRole, QVariant::fromValue(&(ingredient->ingredient)));
        this->ui->groceryIngredientsTable->setItem(lastRow, 2, item);
    }
}

void MainWindow::updateGroceryListList()
{
    this->ui->grocerySelect->clear();
    for (groceryList* g : this->groceryLists)
    {
        this->ui->grocerySelect->addItem(g->name, QVariant::fromValue(g));
    }
    int i = this->ui->grocerySelect->findData(QVariant::fromValue(this->selectedRecipe));
    if(i != -1) this->ui->grocerySelect->setCurrentIndex(i);
    else if(this->ui->grocerySelect->count() > 0)
    {
        this->ui->grocerySelect->setCurrentIndex(0);
        this->selectedGroceryList = qvariant_cast<groceryList*>(this->ui->grocerySelect->currentData());
    }else this->selectedGroceryList = nullptr;
}
void MainWindow::on_removeGrocery_clicked()
{
    QVariant data = ui->grocerySelect->currentData();
    groceryList* deletedMealPlan = qvariant_cast<groceryList*>(data);
    auto it = std::find(this->groceryLists.begin(), this->groceryLists.end(), deletedMealPlan);

    int indexOfDeletedItem = std::distance(this->groceryLists.begin(), it);
    this->groceryLists.erase(this->groceryLists.begin() + indexOfDeletedItem);
    this->groceryLists.shrink_to_fit();
    this->ui->grocerySelect->removeItem(this->ui->grocerySelect->currentIndex());
    if(this->ui->grocerySelect->count() == 0)//if list is empty clear calendar
    {
        this->selectedMealPlan = nullptr;
        updateGroceryListList();
        updateGroceryListItems();
    }
    else{//if meal plan list not empty get new seleced list
        QVariant data = ui->grocerySelect->currentData();
        groceryList* newlySelectedList = qvariant_cast<groceryList*>(data);
        this->selectedGroceryList = newlySelectedList;
        updateGroceryListList();
        updateGroceryListItems();
    }
    statusBar()->showMessage("Removed Grocery List", 2000);

}

void MainWindow::on_grocerySelect_currentIndexChanged(int index)
{
    QVariant data = ui->grocerySelect->itemData(index);
    this->selectedGroceryList = qvariant_cast<groceryList*>(data);
    updateGroceryListItems();
}


void MainWindow::on_removeMealPlan_clicked()
{

}


void MainWindow::on_mealPlanNewButton_clicked()
{
    NewMealPlanDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        if (!name.isEmpty()) {
            MealPlan* plan = new MealPlan(name);
            mealPlans.push_back(plan);
            ui->mealPlanSelect->addItem(name, QVariant::fromValue(plan));
            ui->mealPlanSelect->setCurrentIndex(this->ui->mealPlanSelect->count() - 1);
            this->selectedMealPlan = plan;
            statusBar()->showMessage("Created New Meal Plan", 2000);
        } else {
            QMessageBox::warning(this, "Empty Name", "Please enter a meal plan name.");
        }
    }
    this->ui->grocerySelect->setCurrentIndex(this->ui->grocerySelect->count()-1);
}

void MainWindow::on_saveRecipeButton_clicked()
{

    if(this->selectedRecipe == nullptr)return;
    this->savedRecipes->push_back(selectedRecipe);
    addSavedRecipesToList();
    statusBar()->showMessage("Recipe Saved", 2000);
}

void MainWindow::on_deleteRecipeButton_clicked()
{

}

void MainWindow::on_addAPIKeyButton_triggered()
{
    addAPIKeyDialog w(this);
    w.exec();
    this->APIKEY = w.getAPIKey();
    //qDebug() << "API key is now: " << this->APIKEY;
    statusBar()->showMessage("API key set", 2000);


}


void MainWindow::on_mealPlanSelect_currentIndexChanged(int index)
{
    QVariant data = ui->mealPlanSelect->itemData(index);
    this->selectedMealPlan = qvariant_cast<MealPlan*>(data);
    updateMealPlanLists();
}



void MainWindow::on_recipeSearchbox_returnPressed()
{
    on_searchButton_clicked();
}


void MainWindow::loadDataFromJson(QString filepath)
{

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
    if(rootArray.size() > 1 && rootArray[2].isArray())
    {
        QJsonArray mealPlanArray = rootArray[2].toArray();
        for(const auto& mealPlanQJsonVaueRef : mealPlanArray)//for each meal plan in meal plan array
        {
            if(!mealPlanQJsonVaueRef.isObject()) continue;
            QJsonObject mealPlanObj = mealPlanQJsonVaueRef.toObject();
            MealPlan* currentPlan = new MealPlan(mealPlanObj["title"].toString());
            QStringList keys = mealPlanObj.keys();

            for(int i = 0; i < mealPlanObj.size(); i++)//for each recipe in mealPlan
            {
                QDate testDate = QDate::fromString(keys[i]);
                if(!testDate.isValid())continue;
                QString recipeDate = testDate.toString();
                QJsonArray recipeListOBJ = mealPlanObj[keys[i]].toArray();
                for(auto recipe : recipeListOBJ){
                    QJsonObject recipeOBJ = recipe.toObject();
                    if (recipeOBJ.contains("ingredients")) {
                        QJsonArray ingredientsArray = recipeOBJ["ingredients"].toArray();

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

                            ingredientVector->push_back(ingredientStruct);
                        }
                        class recipe* newRecipe = new class recipe(recipeOBJ["recipeID"].toInt(),
                                                       QUrl(recipeOBJ["recipeURL"].toString()), recipeOBJ["title"].toString(),
                                                       ingredientVector, recipeOBJ["servings"].toInt(),
                                                       recipeOBJ["calories"].toDouble(), QUrl(recipeOBJ["imageURL"].toString()),
                                                       recipeOBJ["description"].toString());

                        currentPlan->addRecipe(QDate::fromString(recipeDate), newRecipe);
                    }
                }

            }

            this->mealPlans.push_back(currentPlan);
            this->ui->mealPlanSelect->addItem(currentPlan->getName(), QVariant::fromValue(currentPlan));
        }
    }
    if(rootArray.size() > 2 && rootArray[3].isArray())
    {
        QJsonArray groceryListArray = rootArray[3].toArray();
        for(auto list : groceryListArray){
            this->groceryLists.push_back(new groceryList(list.toObject()));
        }
        if(this->groceryLists.size() > 0) this->selectedGroceryList = this->groceryLists[0];
    }

}

void MainWindow::saveDatatoJson()
{
    QJsonObject* recipeOBJ;
    QJsonArray recipes;
    QJsonArray savedData;
    QJsonArray ingredients;

    QJsonObject apikeyOBJ;
    apikeyOBJ["APIKEY"] = this->APIKEY;
    savedData.append(apikeyOBJ);

    if(this->savedRecipes != nullptr){
        for(unsigned long i = 0; i < this->savedRecipes->size(); i++)
        {
            recipeOBJ = (*savedRecipes)[i]->makeRecipeObject();
            recipes.append(*recipeOBJ);
        }
        savedData.append(recipes);
        while(recipes.count()) {//remove all elements for next meal plans
            recipes.pop_back();
        }
    }
    MealPlan* currentPlan;
    QJsonArray mealPlans;
    QJsonObject mealPlanInfo;
    if(this->mealPlans.size() != 0)
    {
        for(unsigned long i = 0; i <this->mealPlans.size(); i++)//for all meal plans
        {
            currentPlan = this->mealPlans[i];
            (mealPlanInfo)["title"] = currentPlan->getName();
            auto& currentHashTable = this->mealPlans[i]->mealPlan;
            for(auto& hashValue : *currentHashTable)//for all days in those meal plans
            {
                if(hashValue.second.size() == 0) continue;
                for(auto& currentRecipe : hashValue.second){//for all recipes in those days
                    recipeOBJ = currentRecipe->makeRecipeObject();
                    recipes.append(*recipeOBJ);
                }
                mealPlanInfo[QString::fromStdString(hashValue.first.toStdString())] = recipes;
                recipes = QJsonArray();
                delete recipeOBJ;
                recipeOBJ = new QJsonObject;
            }
            mealPlans.append(mealPlanInfo);
            mealPlanInfo = QJsonObject();
        }
    }
    savedData.append(mealPlans);

    QJsonArray groceryLists;
    for(auto lists : this->groceryLists)
    {
        groceryLists.append(*lists->makeListObject());
    }
    savedData.append(groceryLists);

    QJsonDocument jsonDoc(savedData);

    QFile file("data.json");

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open file for writing: " << file.errorString();
        statusBar()->showMessage("Could not open file for writing", 2000);
        return;
    }

    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();

    qDebug() << "JSON file saved successfully at:" << QFileInfo(file).absoluteFilePath();
    statusBar()->showMessage("JSON file saved successful", 2000);

    delete recipeOBJ;
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
    for (recipe* r : (*this->savedRecipes))//there is an issue here not saving to the list proply, when I do to delete it crashes on loading recipe from list
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
    this->ui->savedRecipeRecipeInfo->setVisible(true);
    this->ui->savedRecipeURL->setVisible(true);

    QVariant data = item->data(Qt::UserRole);
    this->selectedRecipe = data.value<recipe*>();  // Store selected recipe
    if (selectedRecipe)
    {

        ui->savedRecipeName->setText(selectedRecipe->title);

        ui->savedRecipeDesc->setText(selectedRecipe->description);

        // testing
        ui->savedRecipeURL->setText(selectedRecipe->recipeURL.toString());
        ui->savedRecipeServings->setText(QString::number(selectedRecipe->servings));
        ui->savedRecipeCalPerSevings->setText(QString::number(selectedRecipe->calories));
        //ui->savedRecipeImage->scene()->clear();//this causes crashes for some reason, idk
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);

        QUrl imageUrl(selectedRecipe->imageURL.toString());

        QNetworkReply *reply = manager->get(QNetworkRequest(imageUrl));
         connect(reply, &QNetworkReply::finished, [=]() {
             if (reply->error() == QNetworkReply::NoError) {
                QPixmap pixmap;
                pixmap.loadFromData(reply->readAll());
                QPixmap scaledPixmap = pixmap.scaledToWidth(395, Qt::SmoothTransformation);
                ui->savedRecipeImage->setPixmap(scaledPixmap);
             } else {
                 qDebug() << "Failed to load image:" << reply->errorString();
                 statusBar()->showMessage("Failed to load image", 2000);
             }
             reply->deleteLater();
         });

        ui->savedRecipeIngredientTable->setRowCount(0); //reset table
        for (auto* ingredient : *(selectedRecipe->ingredients)) {
            int row = ui->savedRecipeIngredientTable->rowCount();
            ui->recipeIngredientTable->insertRow(row);


            ui->savedRecipeIngredientTable->setItem(row, 0, new QTableWidgetItem(QString::number(ingredient->amount)));
            ui->savedRecipeIngredientTable->setItem(row, 1, new QTableWidgetItem(ingredient->units));
            ui->savedRecipeIngredientTable->setItem(row, 2, new QTableWidgetItem(ingredient->ingredient));
        }

    }

}


void MainWindow::on_searchResult_itemClicked(QListWidgetItem *item)
{
    this->ui->searchRecipeInfoWidget->setVisible(true);
    this->ui->recipeURL->setVisible(true);

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
                QPixmap scaledPixmap = pixmap.scaledToWidth(395, Qt::SmoothTransformation);
                ui->recipeImage->setPixmap(scaledPixmap);
            } else {
                qDebug() << "Failed to load image:" << reply->errorString();
                statusBar()->showMessage("Failed to load image", 2000);
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
    if(deletedItems.size() == 0) return;
    recipe* recipeToDelete = deletedItems[0]->data(Qt::UserRole).value<recipe*>();
    qDebug() << "Found " << deletedItems.size() << " item(s) to delete";
    if(deletedItems.size() != 0)
    {
        QListWidgetItem* deletedItem = deletedItems[0];
        QVariant data = deletedItem->data(Qt::UserRole);
        selectedRecipe = data.value<recipe*>();
        for (auto it = savedRecipes->begin(); it != savedRecipes->end();) {
            if (recipeToDelete == *it) {
                delete *it;  // Free memory before erasing
                it = savedRecipes->erase(it);  // Erase returns next valid iterator
                this->savedRecipes->shrink_to_fit();
                addSavedRecipesToList();//to update list
                statusBar()->showMessage("Removed Recipe", 2000);
                return;
            } else {
                ++it;
            }
        }
    }
}


void MainWindow::on_savedRecipeName_textChanged(const QString &arg1)
{
    this->selectedRecipe->title = arg1;
    //find selected recipe in list and change it
    this->ui->savedRecipesList->selectedItems()[0]->setText(arg1);
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


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 2)//if meal plan tab is selected
    {
        updateMealPlanLists();
    }
}

void MainWindow::updateMealPlanLists(){
    ui->mealPlanRecipesList->clear();
    for (recipe* r : (*this->savedRecipes))
    {
        QListWidgetItem* item = new QListWidgetItem(r->title, this->ui->mealPlanRecipesList);
        item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
    }
    ui->mealPlanSelectedDayRecipesList->clear();
    if(selectedMealPlan == nullptr) return;//if list if empty, leave clear list, if not populate list
    const auto& second = (*this->selectedMealPlan->mealPlan)[this->ui->mealPlanCalender->selectedDate().toString()];
    if(second.size() == 0)return;
        for(recipe* r : second){
            QListWidgetItem* item = new QListWidgetItem(r->title, this->ui->mealPlanSelectedDayRecipesList);
            item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
        }

}
void MainWindow::on_mealPlanAddRecipeButton_clicked()
{
    if(selectedRecipe == nullptr) return;
    this->selectedMealPlan->addRecipe(this->ui->mealPlanCalender->selectedDate(), selectedRecipe);
    updateMealPlanLists();
}


void MainWindow::on_mealPlanRecipesList_itemClicked(QListWidgetItem *item)
{
    QVariant data = item->data(Qt::UserRole);
    selectedRecipe = data.value<recipe*>();
}


void MainWindow::on_mealPlanCalender_selectionChanged()
{
    updateMealPlanLists();
}


void MainWindow::on_mealPlanRemoveRecipeButton_clicked()
{
    this->selectedMealPlan->removeRecipe(this->ui->mealPlanCalender->selectedDate(), selectedRecipe);
    updateMealPlanLists();
}




void MainWindow::on_mealPlanSelectedDayRecipesList_itemClicked(QListWidgetItem *item)
{
    QVariant data = item->data(Qt::UserRole);
    selectedRecipe = data.value<recipe*>();
}


void MainWindow::on_mealPlanSelectedDayRecipesList_itemActivated(QListWidgetItem *item)
{

}


void MainWindow::on_mealPlanDeleteButton_clicked()
{
    QVariant data = ui->mealPlanSelect->currentData();
    MealPlan* deletedMealPlan = qvariant_cast<MealPlan*>(data);
    auto it = std::find(this->mealPlans.begin(), this->mealPlans.end(), deletedMealPlan);

    int indexOfDeletedItem = std::distance(this->mealPlans.begin(), it);
    this->mealPlans.erase(this->mealPlans.begin() + indexOfDeletedItem);
    this->mealPlans.shrink_to_fit();
    this->ui->mealPlanSelect->removeItem(this->ui->mealPlanSelect->currentIndex());
    if(this->ui->mealPlanSelect->count() == 0)//if list is empty clear calendar
    {
        this->selectedMealPlan = nullptr;
        updateMealPlanLists();
    }
    else{//if meal plan list not empty get new seleced list
        QVariant data = ui->mealPlanSelect->currentData();
        MealPlan* newlySelectedMealPlan = qvariant_cast<MealPlan*>(data);
        this->selectedMealPlan = newlySelectedMealPlan;
        updateMealPlanLists();
    }
}


void MainWindow::on_savedRecipeName_textEdited(const QString &arg1)
{

}


void MainWindow::on_recipeSearchbox_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_groceryIngredientsTable_cellChanged(int row, int column)
{
    if(column == 0)//amount is double*
    {
        QTableWidgetItem* t = this->ui->groceryIngredientsTable->currentItem();
        if(t == nullptr) return;
        double* value = reinterpret_cast<double*>(t->data(Qt::UserRole).data());
        qDebug() << "double is: " << *value;
        *value = this->ui->groceryIngredientsTable->currentItem()->text().toDouble();
        qDebug() << "double changed to " << *value;
    }
    else if(column == 1 || column == 2)
    {
        QTableWidgetItem* t = this->ui->groceryIngredientsTable->currentItem();
        if(t == nullptr) return;
        QString* value = reinterpret_cast<QString*>(t->data(Qt::UserRole).data());
        *value = this->ui->groceryIngredientsTable->currentItem()->text();
        qDebug() << "Qstring changed to " << *value;
    }

}


void MainWindow::on_addIngredientButton_clicked()
{
    addIngredient dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        recipe::recipeIngredientStruct* ingredient = dialog.getIngredientStruct();
        this->selectedGroceryList->addItem(ingredient);
    }
    updateGroceryListItems();
}


void MainWindow::on_recipeAddIngredientButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->recipeIngredientTable->selectionModel();
    QModelIndexList selectedIndex = selectionModel->selectedRows();

    if (!selectedIndex.isEmpty())
    {
        foreach (const QModelIndex &index, selectedIndex)
        {
            int row = ui->groceryIngredientsTable->rowCount();
            ui->groceryIngredientsTable->insertRow(row);
            ui->groceryIngredientsTable->setItem(row, 0, new QTableWidgetItem(ui->recipeIngredientTable->item(index.row(), 0)->text()));
            ui->groceryIngredientsTable->setItem(row, 1, new QTableWidgetItem(ui->recipeIngredientTable->item(index.row(), 1)->text()));
            ui->groceryIngredientsTable->setItem(row, 2, new QTableWidgetItem(ui->recipeIngredientTable->item(index.row(), 2)->text()));
        }
        statusBar()->showMessage("Ingredient saved to Grocery List", 2000);
    }
    else
    {
        statusBar()->showMessage("No Ingredient selected", 2000);
    }
}


void MainWindow::on_savedRecipeAddIngredientButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->savedRecipeIngredientTable->selectionModel();
    QModelIndexList selectedIndex = selectionModel->selectedRows();

    if (!selectedIndex.isEmpty())
    {
        foreach (const QModelIndex &index, selectedIndex)
        {
            int row = ui->groceryIngredientsTable->rowCount();
            ui->groceryIngredientsTable->insertRow(row);
            ui->groceryIngredientsTable->setItem(row, 0, new QTableWidgetItem(ui->savedRecipeIngredientTable->item(index.row(), 0)->text()));
            ui->groceryIngredientsTable->setItem(row, 1, new QTableWidgetItem(ui->savedRecipeIngredientTable->item(index.row(), 1)->text()));
            ui->groceryIngredientsTable->setItem(row, 2, new QTableWidgetItem(ui->savedRecipeIngredientTable->item(index.row(), 2)->text()));
        }
        statusBar()->showMessage("Ingredient saved to Grocery List", 2000);
    }
    else
    {
        statusBar()->showMessage("No Ingredient selected", 2000);
    }
}

