#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QDebug>
#include "recipe.h"

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

private slots:

    void on_addGrocery_clicked();

    void on_grocerySelect_currentIndexChanged(int index);

    void on_removeMealPlan_clicked();

    void on_addMealPlan_clicked();

    void on_mealPlanSelect_currentIndexChanged(int index);

    void on_searchButton_clicked();

    void on_recipeSearchbox_returnPressed();

    void on_removeGrocery_clicked();

    void on_searchResult_itemActivated(QListWidgetItem *item);

    void on_saveRecipeButton_clicked();

    void on_savedRecipeList_itemActivated(QListWidgetItem *item);

    void on_deleteRecipeButton_clicked();

private:
    Ui::MainWindow *ui;
    recipe* selectedRecipe = nullptr;
};
MAINWINDOW_H
#endif


