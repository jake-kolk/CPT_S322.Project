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

void MainWindow::on_pushButton_clicked()
{
    QString KEY = "APIKEY"; //this will be loaded from a local .json file to aviod key being exposed in source
    recipeSearch* s = new recipeSearch(KEY);
    std::vector<recipe*>* r1 = s->makeRequest("", std::vector<QString>({"Mozzarella"}), "gluten free", "", 5);
    for(unsigned long long i = 0; i < r1->size(); i++) (*r1)[i]->printRecipeToDebug();
}

