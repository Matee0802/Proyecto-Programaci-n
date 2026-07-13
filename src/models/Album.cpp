#include "models/Album.h"

Album::Album()
    : id_album(0), titulo(""), anio(0), id_artista(0), ruta_portada(""), id_usuario(0) {}

Album::Album(string titulo, int anio, int id_artista, string ruta_portada, int id_usuario)
    : id_album(0), titulo(titulo), anio(anio), id_artista(id_artista),
      ruta_portada(ruta_portada), id_usuario(id_usuario) {}

// Getters
int Album::getIdAlbum() {
    return id_album;
}

string Album::getTitulo() {
    return titulo;
}
int Album::getIdArtista() {
    return id_artista;
}

int Album::getAnio() {
    return anio;
}

string Album::getRutaPortada() {
    return ruta_portada;
}

int Album::getIdUsuario() {
    return id_usuario;
}

// Setters
void Album::setIdAlbum(int id) {
    id_album = id;
}

void Album::setTitulo(string t) {
    titulo = t;
}

void Album::setAnio(int a) {
    anio = a;
}

void Album::setIdArtista(int id_art) {
    id_artista = id_art;
}

void Album::setRutaPortada(string r) {
    ruta_portada = r;
}

void Album::setIdUsuario(int id_usu) {
    id_usuario = id_usu;
}
