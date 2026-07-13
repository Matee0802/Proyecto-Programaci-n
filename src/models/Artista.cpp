#include "models/Artista.h"

Artista::Artista()
    : id_artista(0), nombre(""), biografia_corta(""), genero("") {}

Artista::Artista(string nombre, string biografia, string genero)
    : id_artista(0), nombre(nombre), biografia_corta(biografia), genero(genero) {}

// Getters
int Artista::getId() {
    return id_artista;
}

string Artista::getNombre() {
    return nombre;
}

string Artista::getBio() {
    return biografia_corta;
}

string Artista::getGenero() {
    return genero;
}

// Setters
void Artista::setId(int id) {
    id_artista = id;
}

void Artista::setNombre(string n) {
    nombre = n;
}

void Artista::setBio(string b) {
    biografia_corta = b;
}

void Artista::setGenero(string g) {
    genero = g;
}
