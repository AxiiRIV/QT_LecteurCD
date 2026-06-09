/****************************************************************************
** Meta object code from reading C++ file 'sortieson.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../sortieson.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortieson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
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
struct qt_meta_tag_ZN9SortieSonE_t {};
} // unnamed namespace

template <> constexpr inline auto SortieSon::qt_create_metaobjectdata<qt_meta_tag_ZN9SortieSonE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SortieSon",
        "setVolume",
        "",
        "pVolume",
        "desactiverSon",
        "activerSon"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'setVolume'
        QtMocHelpers::SlotData<void(float)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 3 },
        }}),
        // Slot 'desactiverSon'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'activerSon'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SortieSon, qt_meta_tag_ZN9SortieSonE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SortieSon::staticMetaObject = { {
    QMetaObject::SuperData::link<QAudioOutput::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SortieSonE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SortieSonE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9SortieSonE_t>.metaTypes,
    nullptr
} };

void SortieSon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SortieSon *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setVolume((*reinterpret_cast<std::add_pointer_t<float>>(_a[1]))); break;
        case 1: _t->desactiverSon(); break;
        case 2: _t->activerSon(); break;
        default: ;
        }
    }
}

const QMetaObject *SortieSon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortieSon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SortieSonE_t>.strings))
        return static_cast<void*>(this);
    return QAudioOutput::qt_metacast(_clname);
}

int SortieSon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAudioOutput::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
