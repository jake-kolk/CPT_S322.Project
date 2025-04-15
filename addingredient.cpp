#include "addingredient.h"
#include "ui_addingredient.h"

addIngredient::addIngredient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addIngredient)
{
    ui->setupUi(this);
}

void addIngredient::accept() {
    bool ok;
    this->ui->quantityLineEdit->text().toDouble(&ok);
    if (ok) {
        if(!this->ui->unitsLineEdit->text().isEmpty())
        {
            if(!this->ui->ingredientLineEdit->text().isEmpty())
            {
                recipe::recipeIngredientStruct* r = new recipe::recipeIngredientStruct;
                r->ingredient = this->ui->ingredientLineEdit->text();
                r->amount = this->ui->quantityLineEdit->text().toDouble();
                r->units = this->ui->unitsLineEdit->text();
                this->r = r;
                QDialog::accept();
            }else QMessageBox::warning(this, "Ingredient Error", "Please enter an ingredient");
        }else QMessageBox::warning(this, "Unit Error", "Please enter a unit");
    }else QMessageBox::warning(this, "Quantity Error", "Please enter a valid quantity");
}

recipe::recipeIngredientStruct* addIngredient::getIngredientStruct()
{
    return r;
}

addIngredient::~addIngredient()
{
    delete ui;
}
