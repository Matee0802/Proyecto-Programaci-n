#include "models/UsuarioArtista.h"

UsuarioArtista::UsuarioArtista()
    : id_usuario(0), id_artista(0) {}

UsuarioArtista::UsuarioArtista(int id_usuario, int id_artista)
    : id_usuario(id_usuario), id_artista(id_artista) {}

// Getters
int UsuarioArtista::getIdUsuario() {
    return id_usuario;
}

int UsuarioArtista::getIdArtista() {
    return id_artista;
}

// Setters
void UsuarioArtista::setIdUsuario(int id_usu) {
    id_usuario = id_usu;
}

void UsuarioArtista::setIdArtista(int id_art) {
    id_artista = id_art;
}
