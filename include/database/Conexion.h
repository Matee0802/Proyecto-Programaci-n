#ifndef CONEXION_H
#define CONEXION_H

#include <mysql/mysql.h>
#include <string>

using namespace std;

class Conexion {
private:
    // Mismos valores de configuración que tu archivo conexion.php
    string host;
    string user;
    string pass;
    string db;
    int puerto;
    string charset;

public:
    // Este objeto "conn" va a cumplir la funcion de tu variable "$pdo" en PHP
    MYSQL* conn;

    Conexion();
    bool conectar();
    void desconectar();
};
#endif