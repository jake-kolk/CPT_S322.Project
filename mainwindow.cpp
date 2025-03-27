#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipesearch.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Loading json data...\n";
    loadDataFromJson(QString("")); // QString("") means default location
    this->APIKEY = "1774c84e2269496eb5a1c180961918fa";
    this->savedRecipes = new std::vector<recipe*>;



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchButton_clicked()
{
    qDebug() << "Search Button Clicked";
    QString search = ui->recipeSearchbox->text();
    //if (search.isEmpty()) return;



    recipeSearch searchEngine(this->APIKEY);


    std::vector<QString> ingredients = {"flour", "cheese"};  // search by ingredient, temp stuff in the now for proof of concept
    std::vector<recipe*>* results = searchEngine.makeRequest("Italian", ingredients, "", "", 5);

    ui->searchResult->clear();
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





void MainWindow::on_searchResult_itemActivated(QListWidgetItem *item)
{
    QVariant data = item->data(Qt::UserRole);
    selectedRecipe = data.value<recipe*>();  // Store selected recipe

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


void MainWindow::on_saveRecipeButton_clicked()
{
    if (selectedRecipe)
    {
        QListWidgetItem* item = new QListWidgetItem(selectedRecipe->title, ui->savedRecipesList);
        item->setData(Qt::UserRole, QVariant::fromValue(selectedRecipe));
    }
}




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


void MainWindow::on_deleteRecipeButton_clicked()
{
}





void MainWindow::on_searchResult_itemClicked(QListWidgetItem *item)
{
    QString selectedRecipeTitle = item->text();

    //this is probably not the best way to do it, if you know a better way please change
    for(unsigned long i = 0; i < foundRecipes->size(); i++)
    {
        if(selectedRecipeTitle == (*foundRecipes)[i]->title)
        {
            selectedRecipe = (*foundRecipes)[i];
            break;
        }
    }

    if(this->selectedRecipe == nullptr) return;
    QString recipeSummary = "Servings: " + QString::number(this->selectedRecipe->servings);
    recipeSummary.append("\nCalories per serving: " + QString::number(this->selectedRecipe->calories));
    recipeSummary.append("\n\n" + this->selectedRecipe->description);
    recipeSummary.append("\n\nIngredeints: \n");
    for(unsigned long i = 0; i < this->selectedRecipe->ingredients->size(); i++)
    {
        recipeSummary.append(QString::number((*this->selectedRecipe->ingredients)[i]->amount) +" ");
        recipeSummary.append((*this->selectedRecipe->ingredients)[i]->units + " ");
        recipeSummary.append((*this->selectedRecipe->ingredients)[i]->ingredient + "\n");
    }
    recipeSummary.append("\nURL: " + this->selectedRecipe->recipeURL.toString());
    this->ui->recipeName->setText(selectedRecipeTitle);
    this->ui->recipeDesc->setText(recipeSummary);

}


void MainWindow::on_addAPIKeyButton_triggered()
{


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

            qDebug() << "\nRecipe Title:" << title;
            qDebug() << "Servings:" << servings;
            qDebug() << "Calories:" << calories;
            qDebug() << "Description:" << description;
            qDebug() << "Image URL:" << imageURL;
            qDebug() << "Recipe URL:" << recipeURL;
            qDebug() << "Recipe ID:" << recipeID;

            // Extract Ingredients
            if (recipeObj.contains("ingredients") && recipeObj["ingredients"].isArray()) {
                QJsonArray ingredientsArray = recipeObj["ingredients"].toArray();

                ingredientVector = new std::vector<recipe::recipeIngredientStruct*>;

                qDebug() << "Ingredients:";
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

                    qDebug() << "  -" << ingredientName << ":" << quantity << unit;

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
            recipes.append(*recipeOBJ);
        }
        savedData.append(recipes);
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

}

void MainWindow::closeEvent(QCloseEvent *event) {

    qDebug() << "MainWindow is closing! Performing cleanup...";

    saveDatatoJson();

    event->accept();
}
