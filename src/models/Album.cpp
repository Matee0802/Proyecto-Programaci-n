#include "models/Album.h"

// Asegurate de que los nombres coincidan con tu Album.h
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