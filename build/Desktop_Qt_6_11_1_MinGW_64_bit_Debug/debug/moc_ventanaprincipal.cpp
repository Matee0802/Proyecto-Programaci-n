/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ventanaprincipal.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN16VentanaPrincipalE_t {};
} // unnamed namespace

template <> constexpr inline auto VentanaPrincipal::qt_create_metaobjectdata<qt_meta_tag_ZN16VentanaPrincipalE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VentanaPrincipal",
        "cambiarPosicion",
        "",
        "posicion",
        "on_tablaCanciones_doubleClicked",
        "QModelIndex",
        "index",
        "actualizarEstadoReproduccion",
        "QMediaPlayer::PlaybackState",
        "estado",
        "actualizarDuracionMaxima",
        "duracion",
        "on_btnNext_clicked",
        "on_btnPrev_clicked",
        "cargarYReproducir",
        "fila",
        "on_btnShuffle_clicked",
        "on_btnRepeat_clicked",
        "on_tablaBusqueda_doubleClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'cambiarPosicion'
        QtMocHelpers::SlotData<void(int)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'on_tablaCanciones_doubleClicked'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'actualizarEstadoReproduccion'
        QtMocHelpers::SlotData<void(QMediaPlayer::PlaybackState)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'actualizarDuracionMaxima'
        QtMocHelpers::SlotData<void(qint64)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 11 },
        }}),
        // Slot 'on_btnNext_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnPrev_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'cargarYReproducir'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 15 },
        }}),
        // Slot 'on_btnShuffle_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRepeat_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tablaBusqueda_doubleClicked'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VentanaPrincipal, qt_meta_tag_ZN16VentanaPrincipalE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VentanaPrincipal::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16VentanaPrincipalE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16VentanaPrincipalE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16VentanaPrincipalE_t>.metaTypes,
    nullptr
} };

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VentanaPrincipal *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cambiarPosicion((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_tablaCanciones_doubleClicked((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->actualizarEstadoReproduccion((*reinterpret_cast<std::add_pointer_t<QMediaPlayer::PlaybackState>>(_a[1]))); break;
        case 3: _t->actualizarDuracionMaxima((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 4: _t->on_btnNext_clicked(); break;
        case 5: _t->on_btnPrev_clicked(); break;
        case 6: _t->cargarYReproducir((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_btnShuffle_clicked(); break;
        case 8: _t->on_btnRepeat_clicked(); break;
        case 9: _t->on_tablaBusqueda_doubleClicked((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16VentanaPrincipalE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
