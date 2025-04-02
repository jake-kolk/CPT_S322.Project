/********************************************************************************
** Form generated from reading UI file 'addapikeydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAPIKEYDIALOG_H
#define UI_ADDAPIKEYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addAPIKeyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *APIKeyTextEdit;

    void setupUi(QDialog *addAPIKeyDialog)
    {
        if (addAPIKeyDialog->objectName().isEmpty())
            addAPIKeyDialog->setObjectName("addAPIKeyDialog");
        addAPIKeyDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addAPIKeyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(addAPIKeyDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 111, 21));
        APIKeyTextEdit = new QTextEdit(addAPIKeyDialog);
        APIKeyTextEdit->setObjectName("APIKeyTextEdit");
        APIKeyTextEdit->setGeometry(QRect(30, 60, 341, 171));

        retranslateUi(addAPIKeyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addAPIKeyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addAPIKeyDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addAPIKeyDialog);
    } // setupUi

    void retranslateUi(QDialog *addAPIKeyDialog)
    {
        addAPIKeyDialog->setWindowTitle(QCoreApplication::translate("addAPIKeyDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addAPIKeyDialog", "Enter an API key:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addAPIKeyDialog: public Ui_addAPIKeyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAPIKEYDIALOG_H
