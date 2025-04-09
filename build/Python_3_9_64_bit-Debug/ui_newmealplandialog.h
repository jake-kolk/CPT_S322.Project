/********************************************************************************
** Form generated from reading UI file 'newmealplandialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMEALPLANDIALOG_H
#define UI_NEWMEALPLANDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NewMealPlanDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *dateEdit_2;

    void setupUi(QDialog *NewMealPlanDialog)
    {
        if (NewMealPlanDialog->objectName().isEmpty())
            NewMealPlanDialog->setObjectName("NewMealPlanDialog");
        NewMealPlanDialog->resize(312, 190);
        buttonBox = new QDialogButtonBox(NewMealPlanDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 130, 221, 41));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEdit = new QLineEdit(NewMealPlanDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 10, 181, 24));
        dateEdit = new QDateEdit(NewMealPlanDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(150, 50, 110, 25));
        label = new QLabel(NewMealPlanDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 61, 16));
        label_2 = new QLabel(NewMealPlanDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 61, 16));
        dateEdit_2 = new QDateEdit(NewMealPlanDialog);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(150, 90, 110, 25));

        retranslateUi(NewMealPlanDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewMealPlanDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewMealPlanDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewMealPlanDialog);
    } // setupUi

    void retranslateUi(QDialog *NewMealPlanDialog)
    {
        NewMealPlanDialog->setWindowTitle(QCoreApplication::translate("NewMealPlanDialog", "Create Meal Plan", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("NewMealPlanDialog", "Enter name", nullptr));
        label->setText(QCoreApplication::translate("NewMealPlanDialog", "Start date:", nullptr));
        label_2->setText(QCoreApplication::translate("NewMealPlanDialog", "End date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewMealPlanDialog: public Ui_NewMealPlanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMEALPLANDIALOG_H
