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
    QString search = ui->recipeSearchbox->text();
    if (search.isEmpty()) return;

    QString apiKey = "KEY";  //this will be loaded from a local .json file to aviod key being exposed in source
    recipeSearch searchEngine(apiKey);

    std::vector<QString> ingredients = {search};  // search by ingredient
    std::vector<recipe*>* results = searchEngine.makeRequest("", ingredients, "", "", 5);

    ui->searchResult->clear();
    for (recipe* r : *results)
    {
        QListWidgetItem* item = new QListWidgetItem(r->title, ui->searchResult);
        item->setData(Qt::UserRole, QVariant::fromValue(r));  // store recipe pointer
    }
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
    }
}


void MainWindow::on_saveRecipeButton_clicked()
{
    if (selectedRecipe)
    {
        QListWidgetItem* item = new QListWidgetItem(selectedRecipe->title, ui->savedRecipeList);
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




