#include "models/ColaReproduccion.h"

ColaReproduccion::ColaReproduccion()
    : id_cola(0), id_usuario(0) {}

ColaReproduccion::ColaReproduccion(int id_usuario)
    : id_cola(0), id_usuario(id_usuario) {}

// Getters
int ColaReproduccion::getIdCola() {
    return id_cola;
}

int ColaReproduccion::getIdUsuario() {
    return id_usuario;
}

// Setters
void ColaReproduccion::setIdCola(int id) {
    id_cola = id;
}

void ColaReproduccion::setIdUsuario(int id_usu) {
    id_usuario = id_usu;
}
