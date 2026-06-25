#include "models/Cancion.h"

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