#include "models/Historial.h"

Historial::Historial()
    : id_historial(0), id_usuario(0), id_cancion(0), fecha_reproduccion("") {}

Historial::Historial(int id_usuario, int id_cancion, string fecha_reproduccion)
    : id_historial(0), id_usuario(id_usuario), id_cancion(id_cancion),
      fecha_reproduccion(fecha_reproduccion) {}

// Getters
int Historial::getIdHistorial() {
    return id_historial;
}

int Historial::getIdUsuario() {
    return id_usuario;
}

int Historial::getIdCancion() {
    return id_cancion;
}

string Historial::getFechaReproduccion() {
    return fecha_reproduccion;
}

// Setters
void Historial::setIdHistorial(int id) {
    id_historial = id;
}

void Historial::setIdUsuario(int id_usu) {
    id_usuario = id_usu;
}

void Historial::setIdCancion(int id_can) {
    id_cancion = id_can;
}

void Historial::setFechaReproduccion(string f) {
    fecha_reproduccion = f;
}
