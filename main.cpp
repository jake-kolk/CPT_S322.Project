#include "mainwindow.h"
#include "recipeSearch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<MealPlan>("MealPlan");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
