#include "mainwindow.h"
#include "recipeSearch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<MealPlan>("MealPlan");
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icon.jpg"));
    MainWindow w;
    w.show();
    return a.exec();

}

