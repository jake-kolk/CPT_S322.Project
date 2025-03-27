#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipesearch.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    QString apiKey = "KEY";  //this will be loaded from a local .json file to aviod key being exposed in source
    recipeSearch searchEngine(apiKey);

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


void MainWindow::on_mealPlanSelect_currentIndexChanged(int index)
{

}



void MainWindow::on_recipeSearchbox_returnPressed()
{
    on_searchButton_clicked();
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

/* void MainWindow::on_saveRecipeButton_clicked()
{
    QString recipe = ui->recipeName->text();
    if (recipe != "[Recipe Name]")
    {
        ui->savedRecipeList->addItem(recipe);
        // save desc
    }
} */


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

