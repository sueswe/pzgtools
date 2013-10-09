/****************************************************************************
** Meta object code from reading C++ file 'pzgtools.h'
**
** Created: Sat Sep 22 21:15:04 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pzgtools.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pzgtools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_pzgtools[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      26,    9,    9,    9, 0x0a,
      41,    9,    9,    9, 0x0a,
      51,    9,    9,    9, 0x0a,
      63,    9,    9,    9, 0x0a,
      75,    9,    9,    9, 0x0a,
      87,    9,    9,    9, 0x0a,
      99,    9,    9,    9, 0x0a,
     111,    9,    9,    9, 0x0a,
     118,    9,    9,    9, 0x0a,
     132,    9,    9,    9, 0x0a,
     141,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pzgtools[] = {
    "pzgtools\0\0open_datafile()\0open_workdir()\0extract()\0opendata1()\0"
    "opendata2()\0opendata3()\0opendata4()\0opendata5()\0plot()\0"
    "get_climate()\0set_wd()\0about()\0"
};

const QMetaObject pzgtools::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pzgtools,
      qt_meta_data_pzgtools, 0 }
};

const QMetaObject *pzgtools::metaObject() const
{
    return &staticMetaObject;
}

void *pzgtools::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pzgtools))
	return static_cast<void*>(const_cast<pzgtools*>(this));
    return QWidget::qt_metacast(_clname);
}

int pzgtools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open_datafile(); break;
        case 1: open_workdir(); break;
        case 2: extract(); break;
        case 3: opendata1(); break;
        case 4: opendata2(); break;
        case 5: opendata3(); break;
        case 6: opendata4(); break;
        case 7: opendata5(); break;
        case 8: plot(); break;
        case 9: get_climate(); break;
        case 10: set_wd(); break;
        case 11: about(); break;
        }
        _id -= 12;
    }
    return _id;
}
