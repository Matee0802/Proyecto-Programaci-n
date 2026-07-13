#include "models/Cancion.h"

Cancion::Cancion()
    : id_cancion(0), titulo(""), duracion(""), id_album(0), ruta_archivo_mp3("") {}

Cancion::Cancion(string titulo, string duracion, int id_album, string ruta)
    : id_cancion(0), titulo(titulo), duracion(duracion), id_album(id_album), ruta_archivo_mp3(ruta) {}

// Getters
int Cancion::getId() {
    return id_cancion;
}

string Cancion::getTitulo() {
    return titulo;
}

int Cancion::getIdAlbum() {
    return id_album;
}

string Cancion::getDuracion(){
    return duracion;
}

string Cancion::getRuta() {
    return ruta_archivo_mp3;
}

// Setters
void Cancion::setId(int id) {
    id_cancion = id;
}

void Cancion::setTitulo(string t) {
    titulo = t;
}

void Cancion::setDuracion(string d) {
    duracion = d;
}

void Cancion::setIdAlbum(int id_alb) {
    id_album = id_alb;
}

void Cancion::setRuta(string r) {
    ruta_archivo_mp3 = r;
}
