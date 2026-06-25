#ifndef CONEXION_H
#define CONEXION_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>

class Conexion {
private:
    QString host;
    QString user;
    QString pass;
    QString databaseName;
    int puerto;

public:
    QSqlDatabase db;

    Conexion();
    bool conectar();
    void desconectar();
};

#endif // CONEXION_H