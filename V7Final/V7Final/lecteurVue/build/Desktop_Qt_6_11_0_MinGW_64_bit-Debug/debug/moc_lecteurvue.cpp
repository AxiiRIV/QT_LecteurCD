/****************************************************************************
** Meta object code from reading C++ file 'lecteurvue.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lecteurvue.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecteurvue.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10LecteurVueE_t {};
} // unnamed namespace

template <> constexpr inline auto LecteurVue::qt_create_metaobjectdata<qt_meta_tag_ZN10LecteurVueE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LecteurVue",
        "demanderPauseOuPlay",
        "",
        "demanderArreter",
        "demanderSuivant",
        "demanderPrecedent",
        "demanderAuto",
        "demanderBoucle",
        "demanderAleatoire",
        "demanderOuvrirTiroir",
        "demanderFermerTiroir",
        "demanderInsertionCD",
        "demanderRetraitCD",
        "demanderBasculerOnOff",
        "pAllume",
        "demanderChangervolume",
        "pVolume",
        "demanderActiverSon",
        "demanderDesactiverSon"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'demanderPauseOuPlay'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderArreter'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderSuivant'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderPrecedent'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderAuto'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderBoucle'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderAleatoire'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderOuvrirTiroir'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderFermerTiroir'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderInsertionCD'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderRetraitCD'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderBasculerOnOff'
        QtMocHelpers::SlotData<void(bool)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Slot 'demanderChangervolume'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'demanderActiverSon'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'demanderDesactiverSon'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LecteurVue, qt_meta_tag_ZN10LecteurVueE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject LecteurVue::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10LecteurVueE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10LecteurVueE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10LecteurVueE_t>.metaTypes,
    nullptr
} };

void LecteurVue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LecteurVue *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->demanderPauseOuPlay(); break;
        case 1: _t->demanderArreter(); break;
        case 2: _t->demanderSuivant(); break;
        case 3: _t->demanderPrecedent(); break;
        case 4: _t->demanderAuto(); break;
        case 5: _t->demanderBoucle(); break;
        case 6: _t->demanderAleatoire(); break;
        case 7: _t->demanderOuvrirTiroir(); break;
        case 8: _t->demanderFermerTiroir(); break;
        case 9: _t->demanderInsertionCD(); break;
        case 10: _t->demanderRetraitCD(); break;
        case 11: _t->demanderBasculerOnOff((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->demanderChangervolume((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->demanderActiverSon(); break;
        case 14: _t->demanderDesactiverSon(); break;
        default: ;
        }
    }
}

const QMetaObject *LecteurVue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LecteurVue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10LecteurVueE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int LecteurVue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
