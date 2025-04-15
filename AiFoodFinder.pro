QT       += core gui
QT       += core
QT       += core network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addapikeydialog.cpp \
    addingredient.cpp \
    grocerylist.cpp \
    main.cpp \
    mainwindow.cpp \
    mealplan.cpp \
    newmealplandialog.cpp \
    recipe.cpp \
    recipesearch.cpp

HEADERS += \
    addapikeydialog.h \
    addingredient.h \
    grocerylist.h \
    mainwindow.h \
    mealplan.h \
    newmealplandialog.h \
    recipe.h \
    recipesearch.h \
    search.h

FORMS += \
    addapikeydialog.ui \
    addingredient.ui \
    mainwindow.ui \
    newmealplandialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
