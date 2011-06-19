/****************************************************************************
** Meta object code from reading C++ file 'new_version.h'
**
** Created: Sun Jun 19 11:52:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "new_version.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_version.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Plansza[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      19,    8,    8,    8, 0x08,
      29,    8,    8,    8, 0x08,
      39,    8,    8,    8, 0x08,
      49,    8,    8,    8, 0x08,
      59,    8,    8,    8, 0x08,
      69,    8,    8,    8, 0x08,
      79,    8,    8,    8, 0x08,
      89,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Plansza[] = {
    "Plansza\0\0oznacz1()\0oznacz2()\0oznacz3()\0"
    "oznacz4()\0oznacz5()\0oznacz6()\0oznacz7()\0"
    "oznacz8()\0oznacz9()\0"
};

const QMetaObject Plansza::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Plansza,
      qt_meta_data_Plansza, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Plansza::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Plansza::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Plansza::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plansza))
        return static_cast<void*>(const_cast< Plansza*>(this));
    if (!strcmp(_clname, "Ui_Plansza"))
        return static_cast< Ui_Plansza*>(const_cast< Plansza*>(this));
    return QDialog::qt_metacast(_clname);
}

int Plansza::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: oznacz1(); break;
        case 1: oznacz2(); break;
        case 2: oznacz3(); break;
        case 3: oznacz4(); break;
        case 4: oznacz5(); break;
        case 5: oznacz6(); break;
        case 6: oznacz7(); break;
        case 7: oznacz8(); break;
        case 8: oznacz9(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
