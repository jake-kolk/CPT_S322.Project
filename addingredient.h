#ifndef ADDINGREDIENT_H
#define ADDINGREDIENT_H
#include "recipe.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class addIngredient;
}

class addIngredient : public QDialog
{
    Q_OBJECT

public:
    explicit addIngredient(QWidget *parent = nullptr);
    ~addIngredient();
    recipe::recipeIngredientStruct* getIngredientStruct();

private:
    Ui::addIngredient *ui;
    recipe::recipeIngredientStruct* r = nullptr;
    void accept();


};

#endif // ADDINGREDIENT_H
