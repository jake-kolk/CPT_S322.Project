/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addAPIKeyButton;
    QAction *actionExportRecipeTotxt;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *search;
    QGridLayout *gridLayout_3;
    QComboBox *cuisineComboBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *recipeSearchbox;
    QPushButton *searchButton;
    QPushButton *saveRecipeButton;
    QComboBox *dietComboBox;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QLabel *recipeServingsLabel;
    QLabel *recipeCalPerServingsLabel;
    QLineEdit *recipeCalPerSevings;
    QLineEdit *recipeServings;
    QTableWidget *recipeIngredientTable;
    QListWidget *searchResult;
    QComboBox *mealTypeComboBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QGraphicsView *recipeImage;
    QTextEdit *recipeDesc;
    QLineEdit *recipeName;
    QLabel *searchResultListLabel;
    QWidget *recipes;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QPushButton *saveSavedRecipeEditButton;
    QPushButton *createNewRecipeButton;
    QPushButton *cloneSavedRecipeButton;
    QLineEdit *searchSavedRecipesBox;
    QListWidget *savedRecipesList;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *savedRecipeName;
    QLineEdit *savedRecipeURL;
    QPushButton *deleteSavedRecipesButton;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_10;
    QGraphicsView *savedRecipeImage;
    QTextEdit *savedRecipeDesc;
    QWidget *widget_5;
    QGridLayout *gridLayout_8;
    QLineEdit *savedRecipeCalPerSevings;
    QLineEdit *savedRecipeServings;
    QLabel *savedRecipeServingsLabel;
    QLabel *savedRecipeCalPerServingsLabel;
    QTableWidget *savedRecipeIngredientTable;
    QWidget *mealPlan;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout;
    QComboBox *mealPlanSelect;
    QPushButton *mealPlanNewButton;
    QPushButton *mealPlanDeleteButton;
    QListWidget *mealPlanSelectedDayRecipesList;
    QListWidget *mealPlanRecipesList;
    QLabel *label;
    QLabel *label_2;
    QCalendarWidget *mealPlanCalender;
    QPushButton *mealPlanRemoveRecipeButton;
    QPushButton *mealPlanAddRecipeButton;
    QWidget *grocery;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *grocerySelect;
    QPushButton *addGrocery;
    QPushButton *removeGrocery;
    QTableWidget *groceryIngredientsTable;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *addIngredientButton;
    QPushButton *removeIngredientButton;
    QLineEdit *recipeURL;
    QMenuBar *menubar;
    QMenu *File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(961, 542);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 225));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        MainWindow->setFont(font);
        addAPIKeyButton = new QAction(MainWindow);
        addAPIKeyButton->setObjectName("addAPIKeyButton");
        actionExportRecipeTotxt = new QAction(MainWindow);
        actionExportRecipeTotxt->setObjectName("actionExportRecipeTotxt");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        search = new QWidget();
        search->setObjectName("search");
        sizePolicy.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(search);
        gridLayout_3->setObjectName("gridLayout_3");
        cuisineComboBox = new QComboBox(search);
        cuisineComboBox->setObjectName("cuisineComboBox");

        gridLayout_3->addWidget(cuisineComboBox, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);

        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 3);

        gridLayout_3->addLayout(horizontalLayout_3, 6, 1, 1, 4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout->setVerticalSpacing(7);
        recipeSearchbox = new QLineEdit(search);
        recipeSearchbox->setObjectName("recipeSearchbox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(recipeSearchbox->sizePolicy().hasHeightForWidth());
        recipeSearchbox->setSizePolicy(sizePolicy1);
        recipeSearchbox->setMaximumSize(QSize(16777215, 35));
        recipeSearchbox->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(12);
        recipeSearchbox->setFont(font1);

        gridLayout->addWidget(recipeSearchbox, 0, 0, 1, 1);

        searchButton = new QPushButton(search);
        searchButton->setObjectName("searchButton");
        sizePolicy.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy);
        searchButton->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(searchButton, 0, 1, 2, 1);

        gridLayout->setColumnStretch(0, 2);

        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 5);

        saveRecipeButton = new QPushButton(search);
        saveRecipeButton->setObjectName("saveRecipeButton");
        sizePolicy.setHeightForWidth(saveRecipeButton->sizePolicy().hasHeightForWidth());
        saveRecipeButton->setSizePolicy(sizePolicy);
        saveRecipeButton->setMaximumSize(QSize(16777215, 60));

        gridLayout_3->addWidget(saveRecipeButton, 5, 3, 1, 1);

        dietComboBox = new QComboBox(search);
        dietComboBox->setObjectName("dietComboBox");

        gridLayout_3->addWidget(dietComboBox, 1, 1, 1, 1);

        widget_2 = new QWidget(search);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        widget_2->setMaximumSize(QSize(260, 16777215));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName("gridLayout_5");
        recipeServingsLabel = new QLabel(widget_2);
        recipeServingsLabel->setObjectName("recipeServingsLabel");
        sizePolicy.setHeightForWidth(recipeServingsLabel->sizePolicy().hasHeightForWidth());
        recipeServingsLabel->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(recipeServingsLabel, 0, 0, 1, 1);

        recipeCalPerServingsLabel = new QLabel(widget_2);
        recipeCalPerServingsLabel->setObjectName("recipeCalPerServingsLabel");
        sizePolicy.setHeightForWidth(recipeCalPerServingsLabel->sizePolicy().hasHeightForWidth());
        recipeCalPerServingsLabel->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(recipeCalPerServingsLabel, 1, 0, 1, 1);

        recipeCalPerSevings = new QLineEdit(widget_2);
        recipeCalPerSevings->setObjectName("recipeCalPerSevings");
        sizePolicy.setHeightForWidth(recipeCalPerSevings->sizePolicy().hasHeightForWidth());
        recipeCalPerSevings->setSizePolicy(sizePolicy);
        recipeCalPerSevings->setReadOnly(true);

        gridLayout_5->addWidget(recipeCalPerSevings, 1, 1, 1, 1);

        recipeServings = new QLineEdit(widget_2);
        recipeServings->setObjectName("recipeServings");
        sizePolicy.setHeightForWidth(recipeServings->sizePolicy().hasHeightForWidth());
        recipeServings->setSizePolicy(sizePolicy);
        recipeServings->setReadOnly(true);

        gridLayout_5->addWidget(recipeServings, 0, 1, 1, 1);

        recipeIngredientTable = new QTableWidget(widget_2);
        if (recipeIngredientTable->columnCount() < 3)
            recipeIngredientTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        recipeIngredientTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        recipeIngredientTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        recipeIngredientTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        recipeIngredientTable->setObjectName("recipeIngredientTable");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(3);
        sizePolicy3.setHeightForWidth(recipeIngredientTable->sizePolicy().hasHeightForWidth());
        recipeIngredientTable->setSizePolicy(sizePolicy3);
        recipeIngredientTable->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        recipeIngredientTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        recipeIngredientTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        recipeIngredientTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        recipeIngredientTable->setTextElideMode(Qt::TextElideMode::ElideLeft);
        recipeIngredientTable->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        recipeIngredientTable->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        recipeIngredientTable->setRowCount(0);
        recipeIngredientTable->setColumnCount(3);
        recipeIngredientTable->horizontalHeader()->setVisible(true);
        recipeIngredientTable->horizontalHeader()->setCascadingSectionResizes(false);
        recipeIngredientTable->horizontalHeader()->setMinimumSectionSize(35);
        recipeIngredientTable->horizontalHeader()->setDefaultSectionSize(40);
        recipeIngredientTable->horizontalHeader()->setHighlightSections(true);
        recipeIngredientTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        recipeIngredientTable->horizontalHeader()->setStretchLastSection(true);
        recipeIngredientTable->verticalHeader()->setVisible(false);

        gridLayout_5->addWidget(recipeIngredientTable, 2, 0, 1, 2);


        gridLayout_3->addWidget(widget_2, 7, 3, 1, 1);

        searchResult = new QListWidget(search);
        searchResult->setObjectName("searchResult");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(searchResult->sizePolicy().hasHeightForWidth());
        searchResult->setSizePolicy(sizePolicy4);
        searchResult->setResizeMode(QListView::ResizeMode::Adjust);
        searchResult->setLayoutMode(QListView::LayoutMode::SinglePass);
        searchResult->setSpacing(0);

        gridLayout_3->addWidget(searchResult, 6, 0, 3, 1);

        mealTypeComboBox = new QComboBox(search);
        mealTypeComboBox->setObjectName("mealTypeComboBox");

        gridLayout_3->addWidget(mealTypeComboBox, 1, 3, 1, 1);

        scrollArea = new QScrollArea(search);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(5);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy5);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 433, 499));
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy6.setHorizontalStretch(3);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy6);
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(7);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy7);
        widget->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(7);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        recipeImage = new QGraphicsView(widget);
        recipeImage->setObjectName("recipeImage");
        sizePolicy.setHeightForWidth(recipeImage->sizePolicy().hasHeightForWidth());
        recipeImage->setSizePolicy(sizePolicy);
        recipeImage->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(recipeImage);

        recipeDesc = new QTextEdit(widget);
        recipeDesc->setObjectName("recipeDesc");
        sizePolicy.setHeightForWidth(recipeDesc->sizePolicy().hasHeightForWidth());
        recipeDesc->setSizePolicy(sizePolicy);
        recipeDesc->setMinimumSize(QSize(0, 300));
        recipeDesc->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        recipeDesc->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        recipeDesc->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        recipeDesc->setLineWrapColumnOrWidth(0);
        recipeDesc->setReadOnly(true);
        recipeDesc->setOverwriteMode(false);

        verticalLayout_5->addWidget(recipeDesc);


        verticalLayout_4->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 7, 1, 1, 1);

        recipeName = new QLineEdit(search);
        recipeName->setObjectName("recipeName");
        sizePolicy.setHeightForWidth(recipeName->sizePolicy().hasHeightForWidth());
        recipeName->setSizePolicy(sizePolicy);
        recipeName->setMaximumSize(QSize(16777215, 40));
        recipeName->setFont(font1);
        recipeName->setReadOnly(true);

        gridLayout_3->addWidget(recipeName, 5, 1, 1, 1);

        searchResultListLabel = new QLabel(search);
        searchResultListLabel->setObjectName("searchResultListLabel");

        gridLayout_3->addWidget(searchResultListLabel, 5, 0, 1, 1);

        tabWidget->addTab(search, QString());
        recipes = new QWidget();
        recipes->setObjectName("recipes");
        gridLayout_9 = new QGridLayout(recipes);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout_7->setVerticalSpacing(7);
        saveSavedRecipeEditButton = new QPushButton(recipes);
        saveSavedRecipeEditButton->setObjectName("saveSavedRecipeEditButton");
        sizePolicy.setHeightForWidth(saveSavedRecipeEditButton->sizePolicy().hasHeightForWidth());
        saveSavedRecipeEditButton->setSizePolicy(sizePolicy);
        saveSavedRecipeEditButton->setMaximumSize(QSize(16777215, 35));

        gridLayout_7->addWidget(saveSavedRecipeEditButton, 0, 2, 1, 1);

        createNewRecipeButton = new QPushButton(recipes);
        createNewRecipeButton->setObjectName("createNewRecipeButton");
        sizePolicy.setHeightForWidth(createNewRecipeButton->sizePolicy().hasHeightForWidth());
        createNewRecipeButton->setSizePolicy(sizePolicy);
        createNewRecipeButton->setMaximumSize(QSize(16777215, 35));

        gridLayout_7->addWidget(createNewRecipeButton, 0, 1, 1, 1);

        cloneSavedRecipeButton = new QPushButton(recipes);
        cloneSavedRecipeButton->setObjectName("cloneSavedRecipeButton");
        sizePolicy.setHeightForWidth(cloneSavedRecipeButton->sizePolicy().hasHeightForWidth());
        cloneSavedRecipeButton->setSizePolicy(sizePolicy);
        cloneSavedRecipeButton->setMaximumSize(QSize(16777215, 35));

        gridLayout_7->addWidget(cloneSavedRecipeButton, 0, 3, 1, 1);

        searchSavedRecipesBox = new QLineEdit(recipes);
        searchSavedRecipesBox->setObjectName("searchSavedRecipesBox");
        sizePolicy5.setHeightForWidth(searchSavedRecipesBox->sizePolicy().hasHeightForWidth());
        searchSavedRecipesBox->setSizePolicy(sizePolicy5);
        searchSavedRecipesBox->setMaximumSize(QSize(16777215, 35));
        searchSavedRecipesBox->setSizeIncrement(QSize(0, 0));

        gridLayout_7->addWidget(searchSavedRecipesBox, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 0, 1, 3);

        savedRecipesList = new QListWidget(recipes);
        savedRecipesList->setObjectName("savedRecipesList");
        sizePolicy4.setHeightForWidth(savedRecipesList->sizePolicy().hasHeightForWidth());
        savedRecipesList->setSizePolicy(sizePolicy4);
        savedRecipesList->setResizeMode(QListView::ResizeMode::Adjust);
        savedRecipesList->setLayoutMode(QListView::LayoutMode::SinglePass);
        savedRecipesList->setSpacing(0);

        gridLayout_9->addWidget(savedRecipesList, 1, 0, 2, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        savedRecipeName = new QLineEdit(recipes);
        savedRecipeName->setObjectName("savedRecipeName");
        sizePolicy.setHeightForWidth(savedRecipeName->sizePolicy().hasHeightForWidth());
        savedRecipeName->setSizePolicy(sizePolicy);
        savedRecipeName->setMaximumSize(QSize(16777215, 40));
        savedRecipeName->setReadOnly(false);

        verticalLayout_11->addWidget(savedRecipeName);

        savedRecipeURL = new QLineEdit(recipes);
        savedRecipeURL->setObjectName("savedRecipeURL");
        sizePolicy.setHeightForWidth(savedRecipeURL->sizePolicy().hasHeightForWidth());
        savedRecipeURL->setSizePolicy(sizePolicy);
        savedRecipeURL->setMaximumSize(QSize(16777215, 20));
        savedRecipeURL->setReadOnly(false);

        verticalLayout_11->addWidget(savedRecipeURL);

        verticalLayout_11->setStretch(0, 2);

        horizontalLayout_5->addLayout(verticalLayout_11);

        deleteSavedRecipesButton = new QPushButton(recipes);
        deleteSavedRecipesButton->setObjectName("deleteSavedRecipesButton");
        sizePolicy.setHeightForWidth(deleteSavedRecipesButton->sizePolicy().hasHeightForWidth());
        deleteSavedRecipesButton->setSizePolicy(sizePolicy);
        deleteSavedRecipesButton->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_5->addWidget(deleteSavedRecipesButton);

        horizontalLayout_5->setStretch(0, 3);

        gridLayout_9->addLayout(horizontalLayout_5, 1, 1, 1, 2);

        scrollArea_2 = new QScrollArea(recipes);
        scrollArea_2->setObjectName("scrollArea_2");
        sizePolicy5.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy5);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 448, 499));
        sizePolicy6.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy6);
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_9->setSpacing(7);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(scrollAreaWidgetContents_3);
        widget_4->setObjectName("widget_4");
        sizePolicy7.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy7);
        widget_4->setMinimumSize(QSize(0, 0));
        verticalLayout_10 = new QVBoxLayout(widget_4);
        verticalLayout_10->setSpacing(7);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        savedRecipeImage = new QGraphicsView(widget_4);
        savedRecipeImage->setObjectName("savedRecipeImage");
        sizePolicy.setHeightForWidth(savedRecipeImage->sizePolicy().hasHeightForWidth());
        savedRecipeImage->setSizePolicy(sizePolicy);
        savedRecipeImage->setMinimumSize(QSize(0, 0));

        verticalLayout_10->addWidget(savedRecipeImage);

        savedRecipeDesc = new QTextEdit(widget_4);
        savedRecipeDesc->setObjectName("savedRecipeDesc");
        sizePolicy.setHeightForWidth(savedRecipeDesc->sizePolicy().hasHeightForWidth());
        savedRecipeDesc->setSizePolicy(sizePolicy);
        savedRecipeDesc->setMinimumSize(QSize(0, 300));
        savedRecipeDesc->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        savedRecipeDesc->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        savedRecipeDesc->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        savedRecipeDesc->setLineWrapColumnOrWidth(0);
        savedRecipeDesc->setReadOnly(false);
        savedRecipeDesc->setOverwriteMode(false);

        verticalLayout_10->addWidget(savedRecipeDesc);


        verticalLayout_9->addWidget(widget_4);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        gridLayout_9->addWidget(scrollArea_2, 2, 1, 1, 1);

        widget_5 = new QWidget(recipes);
        widget_5->setObjectName("widget_5");
        sizePolicy2.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy2);
        widget_5->setMaximumSize(QSize(260, 16777215));
        gridLayout_8 = new QGridLayout(widget_5);
        gridLayout_8->setObjectName("gridLayout_8");
        savedRecipeCalPerSevings = new QLineEdit(widget_5);
        savedRecipeCalPerSevings->setObjectName("savedRecipeCalPerSevings");
        sizePolicy.setHeightForWidth(savedRecipeCalPerSevings->sizePolicy().hasHeightForWidth());
        savedRecipeCalPerSevings->setSizePolicy(sizePolicy);
        savedRecipeCalPerSevings->setReadOnly(false);

        gridLayout_8->addWidget(savedRecipeCalPerSevings, 1, 1, 1, 1);

        savedRecipeServings = new QLineEdit(widget_5);
        savedRecipeServings->setObjectName("savedRecipeServings");
        sizePolicy.setHeightForWidth(savedRecipeServings->sizePolicy().hasHeightForWidth());
        savedRecipeServings->setSizePolicy(sizePolicy);
        savedRecipeServings->setReadOnly(false);

        gridLayout_8->addWidget(savedRecipeServings, 0, 1, 1, 1);

        savedRecipeServingsLabel = new QLabel(widget_5);
        savedRecipeServingsLabel->setObjectName("savedRecipeServingsLabel");
        sizePolicy.setHeightForWidth(savedRecipeServingsLabel->sizePolicy().hasHeightForWidth());
        savedRecipeServingsLabel->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(savedRecipeServingsLabel, 0, 0, 1, 1);

        savedRecipeCalPerServingsLabel = new QLabel(widget_5);
        savedRecipeCalPerServingsLabel->setObjectName("savedRecipeCalPerServingsLabel");
        sizePolicy.setHeightForWidth(savedRecipeCalPerServingsLabel->sizePolicy().hasHeightForWidth());
        savedRecipeCalPerServingsLabel->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(savedRecipeCalPerServingsLabel, 1, 0, 1, 1);

        savedRecipeIngredientTable = new QTableWidget(widget_5);
        if (savedRecipeIngredientTable->columnCount() < 3)
            savedRecipeIngredientTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        savedRecipeIngredientTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        savedRecipeIngredientTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        savedRecipeIngredientTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        savedRecipeIngredientTable->setObjectName("savedRecipeIngredientTable");
        sizePolicy3.setHeightForWidth(savedRecipeIngredientTable->sizePolicy().hasHeightForWidth());
        savedRecipeIngredientTable->setSizePolicy(sizePolicy3);
        savedRecipeIngredientTable->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        savedRecipeIngredientTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        savedRecipeIngredientTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        savedRecipeIngredientTable->setEditTriggers(QAbstractItemView::EditTrigger::AnyKeyPressed|QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed);
        savedRecipeIngredientTable->setTextElideMode(Qt::TextElideMode::ElideLeft);
        savedRecipeIngredientTable->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        savedRecipeIngredientTable->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        savedRecipeIngredientTable->setRowCount(0);
        savedRecipeIngredientTable->setColumnCount(3);
        savedRecipeIngredientTable->horizontalHeader()->setVisible(true);
        savedRecipeIngredientTable->horizontalHeader()->setCascadingSectionResizes(false);
        savedRecipeIngredientTable->horizontalHeader()->setMinimumSectionSize(35);
        savedRecipeIngredientTable->horizontalHeader()->setDefaultSectionSize(40);
        savedRecipeIngredientTable->horizontalHeader()->setHighlightSections(true);
        savedRecipeIngredientTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        savedRecipeIngredientTable->horizontalHeader()->setStretchLastSection(true);
        savedRecipeIngredientTable->verticalHeader()->setVisible(false);

        gridLayout_8->addWidget(savedRecipeIngredientTable, 2, 0, 1, 2);


        gridLayout_9->addWidget(widget_5, 2, 2, 1, 1);

        tabWidget->addTab(recipes, QString());
        mealPlan = new QWidget();
        mealPlan->setObjectName("mealPlan");
        gridLayout_10 = new QGridLayout(mealPlan);
        gridLayout_10->setObjectName("gridLayout_10");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        mealPlanSelect = new QComboBox(mealPlan);
        mealPlanSelect->setObjectName("mealPlanSelect");
        sizePolicy1.setHeightForWidth(mealPlanSelect->sizePolicy().hasHeightForWidth());
        mealPlanSelect->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(mealPlanSelect);

        mealPlanNewButton = new QPushButton(mealPlan);
        mealPlanNewButton->setObjectName("mealPlanNewButton");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(2);
        sizePolicy8.setHeightForWidth(mealPlanNewButton->sizePolicy().hasHeightForWidth());
        mealPlanNewButton->setSizePolicy(sizePolicy8);

        horizontalLayout->addWidget(mealPlanNewButton);

        mealPlanDeleteButton = new QPushButton(mealPlan);
        mealPlanDeleteButton->setObjectName("mealPlanDeleteButton");
        sizePolicy.setHeightForWidth(mealPlanDeleteButton->sizePolicy().hasHeightForWidth());
        mealPlanDeleteButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(mealPlanDeleteButton);


        gridLayout_10->addLayout(horizontalLayout, 1, 0, 1, 4);

        mealPlanSelectedDayRecipesList = new QListWidget(mealPlan);
        mealPlanSelectedDayRecipesList->setObjectName("mealPlanSelectedDayRecipesList");

        gridLayout_10->addWidget(mealPlanSelectedDayRecipesList, 3, 1, 1, 1);

        mealPlanRecipesList = new QListWidget(mealPlan);
        mealPlanRecipesList->setObjectName("mealPlanRecipesList");
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy9.setHorizontalStretch(3);
        sizePolicy9.setVerticalStretch(2);
        sizePolicy9.setHeightForWidth(mealPlanRecipesList->sizePolicy().hasHeightForWidth());
        mealPlanRecipesList->setSizePolicy(sizePolicy9);

        gridLayout_10->addWidget(mealPlanRecipesList, 3, 2, 1, 2);

        label = new QLabel(mealPlan);
        label->setObjectName("label");

        gridLayout_10->addWidget(label, 2, 1, 1, 1);

        label_2 = new QLabel(mealPlan);
        label_2->setObjectName("label_2");

        gridLayout_10->addWidget(label_2, 2, 2, 1, 1);

        mealPlanCalender = new QCalendarWidget(mealPlan);
        mealPlanCalender->setObjectName("mealPlanCalender");
        QSizePolicy sizePolicy10(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy10.setHorizontalStretch(10);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(mealPlanCalender->sizePolicy().hasHeightForWidth());
        mealPlanCalender->setSizePolicy(sizePolicy10);
        mealPlanCalender->setGridVisible(false);
        mealPlanCalender->setSelectionMode(QCalendarWidget::SelectionMode::SingleSelection);
        mealPlanCalender->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::LongDayNames);
        mealPlanCalender->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);

        gridLayout_10->addWidget(mealPlanCalender, 2, 0, 3, 1);

        mealPlanRemoveRecipeButton = new QPushButton(mealPlan);
        mealPlanRemoveRecipeButton->setObjectName("mealPlanRemoveRecipeButton");

        gridLayout_10->addWidget(mealPlanRemoveRecipeButton, 4, 1, 1, 1);

        mealPlanAddRecipeButton = new QPushButton(mealPlan);
        mealPlanAddRecipeButton->setObjectName("mealPlanAddRecipeButton");
        QSizePolicy sizePolicy11(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(mealPlanAddRecipeButton->sizePolicy().hasHeightForWidth());
        mealPlanAddRecipeButton->setSizePolicy(sizePolicy11);

        gridLayout_10->addWidget(mealPlanAddRecipeButton, 4, 2, 1, 2);

        tabWidget->addTab(mealPlan, QString());
        grocery = new QWidget();
        grocery->setObjectName("grocery");
        sizePolicy.setHeightForWidth(grocery->sizePolicy().hasHeightForWidth());
        grocery->setSizePolicy(sizePolicy);
        gridLayout_11 = new QGridLayout(grocery);
        gridLayout_11->setObjectName("gridLayout_11");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        grocerySelect = new QComboBox(grocery);
        grocerySelect->setObjectName("grocerySelect");
        sizePolicy5.setHeightForWidth(grocerySelect->sizePolicy().hasHeightForWidth());
        grocerySelect->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(grocerySelect);

        addGrocery = new QPushButton(grocery);
        addGrocery->setObjectName("addGrocery");
        sizePolicy.setHeightForWidth(addGrocery->sizePolicy().hasHeightForWidth());
        addGrocery->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(addGrocery);

        removeGrocery = new QPushButton(grocery);
        removeGrocery->setObjectName("removeGrocery");
        sizePolicy.setHeightForWidth(removeGrocery->sizePolicy().hasHeightForWidth());
        removeGrocery->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(removeGrocery);


        gridLayout_11->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        groceryIngredientsTable = new QTableWidget(grocery);
        if (groceryIngredientsTable->columnCount() < 3)
            groceryIngredientsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        groceryIngredientsTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        groceryIngredientsTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        groceryIngredientsTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        groceryIngredientsTable->setObjectName("groceryIngredientsTable");
        sizePolicy3.setHeightForWidth(groceryIngredientsTable->sizePolicy().hasHeightForWidth());
        groceryIngredientsTable->setSizePolicy(sizePolicy3);
        groceryIngredientsTable->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groceryIngredientsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        groceryIngredientsTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        groceryIngredientsTable->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed);
        groceryIngredientsTable->setTextElideMode(Qt::TextElideMode::ElideLeft);
        groceryIngredientsTable->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        groceryIngredientsTable->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        groceryIngredientsTable->setRowCount(0);
        groceryIngredientsTable->setColumnCount(3);
        groceryIngredientsTable->horizontalHeader()->setVisible(true);
        groceryIngredientsTable->horizontalHeader()->setCascadingSectionResizes(false);
        groceryIngredientsTable->horizontalHeader()->setMinimumSectionSize(100);
        groceryIngredientsTable->horizontalHeader()->setDefaultSectionSize(100);
        groceryIngredientsTable->horizontalHeader()->setHighlightSections(true);
        groceryIngredientsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        groceryIngredientsTable->horizontalHeader()->setStretchLastSection(true);
        groceryIngredientsTable->verticalHeader()->setVisible(false);

        gridLayout_11->addWidget(groceryIngredientsTable, 1, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        addIngredientButton = new QPushButton(grocery);
        addIngredientButton->setObjectName("addIngredientButton");

        horizontalLayout_6->addWidget(addIngredientButton);

        removeIngredientButton = new QPushButton(grocery);
        removeIngredientButton->setObjectName("removeIngredientButton");

        horizontalLayout_6->addWidget(removeIngredientButton);


        gridLayout_11->addLayout(horizontalLayout_6, 2, 1, 1, 1);

        tabWidget->addTab(grocery, QString());

        gridLayout_2->addWidget(tabWidget, 0, 1, 1, 1);

        recipeURL = new QLineEdit(centralwidget);
        recipeURL->setObjectName("recipeURL");
        sizePolicy.setHeightForWidth(recipeURL->sizePolicy().hasHeightForWidth());
        recipeURL->setSizePolicy(sizePolicy);
        recipeURL->setMaximumSize(QSize(16777215, 20));
        recipeURL->setReadOnly(true);

        gridLayout_2->addWidget(recipeURL, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 961, 25));
        QSizePolicy sizePolicy12(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy12);
        menubar->setMinimumSize(QSize(25, 25));
        menubar->setMaximumSize(QSize(16777215, 16777215));
        menubar->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(9);
        font2.setKerning(true);
        menubar->setFont(font2);
        menubar->setStyleSheet(QString::fromUtf8(""));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        File = new QMenu(menubar);
        File->setObjectName("File");
        File->setMinimumSize(QSize(0, 10));
        File->setMaximumSize(QSize(16777215, 16777215));
        File->setFont(font2);
        File->setTearOffEnabled(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(File->menuAction());
        File->addAction(addAPIKeyButton);
        File->addAction(actionExportRecipeTotxt);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AI Food Finder", nullptr));
        addAPIKeyButton->setText(QCoreApplication::translate("MainWindow", "Add API Key", nullptr));
        actionExportRecipeTotxt->setText(QCoreApplication::translate("MainWindow", "Export Recipe to txt", nullptr));
        recipeSearchbox->setText(QString());
        recipeSearchbox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search for Recipes", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        saveRecipeButton->setText(QCoreApplication::translate("MainWindow", "Save Recipe", nullptr));
        recipeServingsLabel->setText(QCoreApplication::translate("MainWindow", "Servings:", nullptr));
        recipeCalPerServingsLabel->setText(QCoreApplication::translate("MainWindow", "Calories Per Serving: ", nullptr));
        recipeCalPerSevings->setText(QString());
        recipeServings->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = recipeIngredientTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = recipeIngredientTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = recipeIngredientTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Ingredients", nullptr));
        recipeDesc->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        searchResultListLabel->setText(QCoreApplication::translate("MainWindow", "  Search Results", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(search), QCoreApplication::translate("MainWindow", "Search", nullptr));
        saveSavedRecipeEditButton->setText(QCoreApplication::translate("MainWindow", "Save Recipe", nullptr));
        createNewRecipeButton->setText(QCoreApplication::translate("MainWindow", "New Recipe", nullptr));
        cloneSavedRecipeButton->setText(QCoreApplication::translate("MainWindow", "Clone Recipe", nullptr));
        searchSavedRecipesBox->setText(QString());
        searchSavedRecipesBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search for Saved Recipes", nullptr));
        deleteSavedRecipesButton->setText(QCoreApplication::translate("MainWindow", "Delete Recipe", nullptr));
        savedRecipeDesc->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        savedRecipeCalPerSevings->setText(QString());
        savedRecipeServings->setText(QString());
        savedRecipeServingsLabel->setText(QCoreApplication::translate("MainWindow", "Servings:", nullptr));
        savedRecipeCalPerServingsLabel->setText(QCoreApplication::translate("MainWindow", "Calories Per Serving: ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = savedRecipeIngredientTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = savedRecipeIngredientTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = savedRecipeIngredientTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Ingredients", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(recipes), QCoreApplication::translate("MainWindow", "Saved Recipes", nullptr));
        mealPlanNewButton->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        mealPlanDeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Recipes for selected day", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Saved Recipes", nullptr));
        mealPlanRemoveRecipeButton->setText(QCoreApplication::translate("MainWindow", "Remove Recipe", nullptr));
        mealPlanAddRecipeButton->setText(QCoreApplication::translate("MainWindow", "Add Recipe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mealPlan), QCoreApplication::translate("MainWindow", "Meal Plan", nullptr));
        addGrocery->setText(QCoreApplication::translate("MainWindow", "Add New", nullptr));
        removeGrocery->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = groceryIngredientsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = groceryIngredientsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = groceryIngredientsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Ingredients", nullptr));
        addIngredientButton->setText(QCoreApplication::translate("MainWindow", "Add Ingredient", nullptr));
        removeIngredientButton->setText(QCoreApplication::translate("MainWindow", "Remove Ingredient", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(grocery), QCoreApplication::translate("MainWindow", "Grocery List", nullptr));
        File->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
