/****************************************************************************
** Meta object code from reading C++ file 'common_inputs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../end2end_functional_test/common_inputs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'common_inputs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Common_Inputs_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Common_Inputs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Common_Inputs_t qt_meta_stringdata_Common_Inputs = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Common_Inputs"
QT_MOC_LITERAL(1, 14, 10), // "Ign_Status"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "IgnStatus"
QT_MOC_LITERAL(4, 36, 18), // "emit_signal_IgnAcc"
QT_MOC_LITERAL(5, 55, 21), // "ShowForm_CommonInputs"
QT_MOC_LITERAL(6, 77, 8), // "onIgnOff"
QT_MOC_LITERAL(7, 86, 7) // "onIgnOn"

    },
    "Common_Inputs\0Ign_Status\0\0IgnStatus\0"
    "emit_signal_IgnAcc\0ShowForm_CommonInputs\0"
    "onIgnOff\0onIgnOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Common_Inputs[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Common_Inputs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Common_Inputs *_t = static_cast<Common_Inputs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Ign_Status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->emit_signal_IgnAcc(); break;
        case 2: _t->ShowForm_CommonInputs(); break;
        case 3: _t->onIgnOff(); break;
        case 4: _t->onIgnOn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Common_Inputs::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Common_Inputs::Ign_Status)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Common_Inputs::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Common_Inputs.data,
      qt_meta_data_Common_Inputs,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Common_Inputs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Common_Inputs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Common_Inputs.stringdata0))
        return static_cast<void*>(const_cast< Common_Inputs*>(this));
    return QWidget::qt_metacast(_clname);
}

int Common_Inputs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Common_Inputs::Ign_Status(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
