#include "../../include/database/Conexion.h"
#include <iostream>

using namespace std;

// Constructor: Inicializamos los datos por defecto igual que en PHP
Conexion::Conexion() {
    this->host = "localhost";
    this->user = "root";
    this->pass = "";             // Vacía por defecto en XAMPP
    this->db = "spotcloud";       // Tu base de datos compartida
    this->puerto = 3306;         // Puerto por defecto de MySQL
    this->charset = "utf8mb4";   // Para que soporte tildes y eñes
    this->conn = nullptr;
}

bool Conexion::conectar() {
    // Inicializa el objeto mysql (equivalente a preparar la estructura del DSN)
    conn = mysql_init(nullptr);
    if (conn == nullptr) {
        cout << "Error de Conexión: No se pudo inicializar la estructura MYSQL." << endl;
        return false;
    }

    // Intenta establecer la conexión real (Igual al "new PDO" dentro de tu try-catch)
    if (!mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), puerto, nullptr, 0)) {
        // Si entra acá, funciona como el "catch (\PDOException $e)"
        cout << "Error de Conexión: " << mysql_error(conn) << endl;
        mysql_close(conn);
        conn = nullptr;
        return false;
    }

    // Aplicamos el charset recomendado que tenías en PHP
    mysql_set_character_set(conn, charset.c_str());
    
    return true;
}

void Conexion::desconectar() {
    if (conn != nullptr) {
        mysql_close(conn);
        conn = nullptr;
    }
}