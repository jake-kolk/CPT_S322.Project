/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "on_addGrocery_clicked",
    "",
    "on_grocerySelect_currentIndexChanged",
    "index",
    "on_removeMealPlan_clicked",
    "on_mealPlanSelect_currentIndexChanged",
    "on_searchButton_clicked",
    "on_recipeSearchbox_returnPressed",
    "on_removeGrocery_clicked",
    "on_searchResult_itemActivated",
    "QListWidgetItem*",
    "item",
    "on_saveRecipeButton_clicked",
    "on_savedRecipeList_itemActivated",
    "on_deleteRecipeButton_clicked",
    "on_item_clicked",
    "on_searchResult_itemClicked",
    "on_addAPIKeyButton_triggered",
    "on_mealPlanNewButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    1,  105,    2, 0x08,    2 /* Private */,
       5,    0,  108,    2, 0x08,    4 /* Private */,
       6,    1,  109,    2, 0x08,    5 /* Private */,
       7,    0,  112,    2, 0x08,    7 /* Private */,
       8,    0,  113,    2, 0x08,    8 /* Private */,
       9,    0,  114,    2, 0x08,    9 /* Private */,
      10,    1,  115,    2, 0x08,   10 /* Private */,
      13,    0,  118,    2, 0x08,   12 /* Private */,
      14,    1,  119,    2, 0x08,   13 /* Private */,
      15,    0,  122,    2, 0x08,   15 /* Private */,
      16,    0,  123,    2, 0x08,   16 /* Private */,
      17,    1,  124,    2, 0x08,   17 /* Private */,
      18,    0,  127,    2, 0x08,   19 /* Private */,
      19,    0,  128,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_addGrocery_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_grocerySelect_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_removeMealPlan_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mealPlanSelect_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_searchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_recipeSearchbox_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeGrocery_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchResult_itemActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_saveRecipeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_savedRecipeList_itemActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_deleteRecipeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_item_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchResult_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_addAPIKeyButton_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_mealPlanNewButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_addGrocery_clicked(); break;
        case 1: _t->on_grocerySelect_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_removeMealPlan_clicked(); break;
        case 3: _t->on_mealPlanSelect_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_searchButton_clicked(); break;
        case 5: _t->on_recipeSearchbox_returnPressed(); break;
        case 6: _t->on_removeGrocery_clicked(); break;
        case 7: _t->on_searchResult_itemActivated((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 8: _t->on_saveRecipeButton_clicked(); break;
        case 9: _t->on_savedRecipeList_itemActivated((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 10: _t->on_deleteRecipeButton_clicked(); break;
        case 11: _t->on_item_clicked(); break;
        case 12: _t->on_searchResult_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 13: _t->on_addAPIKeyButton_triggered(); break;
        case 14: _t->on_mealPlanNewButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
