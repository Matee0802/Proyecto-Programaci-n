#include "../../include/database/conexion.h"
#include <QSqlError>
#include <QDebug>

Conexion::Conexion(){
    // Configuramos Qt para usar ODBC en lugar del nativo de MySQL
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Conexion::conectar(){
    // ¡OJO! Acá cambiamos "autogest" por "spotcloud"
    db.setDatabaseName(
        "Driver={MySQL ODBC 9.7 Unicode Driver};"
        "Server=pma.torga.com.ar:3306;"
        "Database=s11_spotcloud;"
        "User=u11_9RmypvFBbx;"
        "Password=!.L+MW7E59phN+nlKvpzJQsJ;"
        );

    if (!db.open()){
        qDebug() << "Error al conectar por ODBC:";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "¡Conexión exitosa a SpotCloud via ODBC!";
    return true;
}

QSqlDatabase Conexion::getDB(){
    return db;
}

void Conexion::desconectar()
{
    if (db.isOpen()){
        db.close();
    }
}