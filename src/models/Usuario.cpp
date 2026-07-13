#include "models/Usuario.h"

Usuario::Usuario()
    : id_usuario(0), nombre(""), correo(""), password("") {}

Usuario::Usuario(string nombre, string correo, string password)
    : id_usuario(0), nombre(nombre), correo(correo), password(password) {}

// Getters
int Usuario::getId() {
    return id_usuario;
}

string Usuario::getNombreS() {
    return nombre;
}

string Usuario::getCorreo() {
    return correo;
}

string Usuario::getPassword() {
    return password;
}

// Setters
void Usuario::setId(int id) {
    id_usuario = id;
}

void Usuario::setNombre(string n) {
    nombre = n;
}

void Usuario::setCorreo(string c) {
    correo = c;
}

void Usuario::setPassword(string p) {
    password = p;
}
