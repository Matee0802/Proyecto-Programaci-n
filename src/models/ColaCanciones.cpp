#include "models/ColaCanciones.h"

ColaCanciones::ColaCanciones()
    : id_cola(0), id_cancion(0), orden(0), reproducida(false) {}

ColaCanciones::ColaCanciones(int id_cola, int id_cancion, int orden, bool reproducida)
    : id_cola(id_cola), id_cancion(id_cancion), orden(orden), reproducida(reproducida) {}

// Getters
int ColaCanciones::getIdCola() {
    return id_cola;
}

int ColaCanciones::getIdCancion() {
    return id_cancion;
}

int ColaCanciones::getOrden() {
    return orden;
}

bool ColaCanciones::getReproducida() {
    return reproducida;
}

// Setters
void ColaCanciones::setIdCola(int id) {
    id_cola = id;
}

void ColaCanciones::setIdCancion(int id_can) {
    id_cancion = id_can;
}

void ColaCanciones::setOrden(int o) {
    orden = o;
}

void ColaCanciones::setReproducida(bool r) {
    reproducida = r;
}
