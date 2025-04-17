#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define JSONFILEPATH
#include <QMainWindow>
#include <QListWidgetItem>
#include <QString>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QCloseEvent>
#include <QFileInfo>
#include <QTableWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "recipe.h"
#include "mealplan.h"
#include "newmealplandialog.h"
#include "mealplan.h"
#include "grocerylist.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadDataFromJson(QString filePath="data.json");//filepath should not be included unless user tried to load from non default filepath
    MealPlan* selectedMealPlan;
    groceryList* selectedGroceryList;
    std::vector<groceryList*> groceryLists;

private slots:

    void setProgressBarProgress(bool visability, int progress);

    void on_addGrocery_clicked();

    void on_grocerySelect_currentIndexChanged(int index);

    void on_removeMealPlan_clicked();


    //void on_addMealPlan_clicked();

    void on_mealPlanSelect_currentIndexChanged(int index);

    void on_searchButton_clicked();

    void on_recipeSearchbox_returnPressed();

    void on_removeGrocery_clicked();

    void on_saveRecipeButton_clicked();

    void on_deleteRecipeButton_clicked();

    void on_item_clicked();

    void on_searchResult_itemClicked(QListWidgetItem *item);

    void on_addAPIKeyButton_triggered();

    void on_mealPlanNewButton_clicked();

    void on_savedRecipesList_itemClicked(QListWidgetItem *item);

    void on_deleteSavedRecipesButton_clicked();

    void on_savedRecipeName_textChanged(const QString &arg1);

    void on_savedRecipeURL_textChanged(const QString &arg1);

    void on_savedRecipeDesc_textChanged();

    void on_savedRecipeServings_textChanged(const QString &arg1);

    void on_savedRecipeCalPerSevings_textChanged(const QString &arg1);

    void on_savedRecipeIngredientTable_cellChanged(int row, int column);

    void on_savedRecipeIngredientTable_itemChanged(QTableWidgetItem *item);

    void on_tabWidget_currentChanged(int index);

    void on_cloneSavedRecipeButton_clicked();

    void on_searchSavedRecipesBox_textChanged(const QString &arg1);



    void on_tabWidget_tabBarClicked(int index);

    void on_mealPlanAddRecipeButton_clicked();

    void on_mealPlanRecipesList_itemClicked(QListWidgetItem *item);


    void on_mealPlanCalender_selectionChanged();

    void on_mealPlanRemoveRecipeButton_clicked();

    void on_mealPlanSelectedDayRecipesList_itemClicked(QListWidgetItem *item);

    void on_mealPlanSelectedDayRecipesList_itemActivated(QListWidgetItem *item);

    void on_mealPlanDeleteButton_clicked();

    void on_savedRecipeName_textEdited(const QString &arg1);

    void on_recipeSearchbox_cursorPositionChanged(int arg1, int arg2);

    void on_groceryIngredientsTable_cellChanged(int row, int column);

    void on_addIngredientButton_clicked();

    void on_recipeAddIngredientButton_clicked();

    void on_savedRecipeAddIngredientButton_clicked();

private:
    Ui::MainWindow *ui;
    recipe* selectedRecipe = nullptr;
    std::vector<recipe*>* foundRecipes = nullptr;

    std::vector<recipe*>* savedRecipes = nullptr;
    QString user;
    QString APIKEY;

    void saveDatatoJson();
    std::vector<MealPlan*> mealPlans;

    void updateMealPlanLists();

    void addSavedRecipesToList();
    void updateSavedRecipesListWithSearch(QString search);
    void updateSearchResultList();
    void updateGroceryListItems();
    void updateGroceryListList();
protected:
    void closeEvent(QCloseEvent *event) override;

};
MAINWINDOW_H
#endif


