#include "database/Conexion.h"
#include <QDebug>

Conexion::Conexion() {
    // Configuramos los datos de tu base de datos de XAMPP usando Qt
    host = "127.0.0.1";
    user = "root";
    pass = "";
    databaseName = "spotcloud";
    puerto = 3306;

    // Inicializamos el driver de MySQL nativo de Qt
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setUserName(user);
    db.setPassword(pass);
    db.setDatabaseName(databaseName);
    db.setPort(puerto);
}

bool Conexion::conectar() {
    if (db.open()) {
        qDebug() << "¡Conectado a la base de datos SpotCloud perfectamente!";
        return true;
    } else {
        qDebug() << "Error al conectar a la base de datos:" << db.lastError().text();
        return false;
    }
}

void Conexion::desconectar() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Base de datos desconectada.";
    }
}