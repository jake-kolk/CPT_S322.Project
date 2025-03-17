#include "mainwindow.h"
#include "ui_mainwindow.h"

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

// click on search button
void MainWindow::on_searchButton_clicked()
{
    QString search = ui->recipeSearchbox->text(); // search value
    if (search != "")
    {
        ui->searchResult->addItem(search); //Add to list (temp)
        //do search
    }
}


// push Enter key on search box
void MainWindow::on_recipeSearchbox_returnPressed()
{
    QString search = ui->recipeSearchbox->text(); // search value
    if (search != "")
    {
        ui->searchResult->addItem(search); //Add to list (temp)
        //do search
    }
}

// select a recipe in search result
void MainWindow::on_searchResult_itemActivated(QListWidgetItem *item)
{
    QString recipeName = item->text();
    ui->recipeName->setText(recipeName);
    //ui->recipeDesc->setText();
}


void MainWindow::on_saveRecipeButton_clicked()
{
    QString recipe = ui->recipeName->text();
    if (recipe != "[Recipe Name]")
    {
        ui->savedRecipeList->addItem(recipe);
        // save desc
    }
}


void MainWindow::on_savedRecipeList_itemActivated(QListWidgetItem *item)
{
    QString recipeName = item->text();
    ui->savedRecipeName->setText(recipeName);
    //ui->recipeDesc->setText();
}


void MainWindow::on_deleteRecipeButton_clicked()
{
}

