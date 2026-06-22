#include "dao/UsuarioArtistaDAOImpl.h"
#include "database/Conexion.h"
#include <iostream>

using namespace std;

// Implementacion de los metodos de la clase UsuarioArtistaDAOImpl
void UsuarioArtistaDAOImpl::insertar(UsuarioArtista ua) {
    // El usuario le dio al boton "Seguir" del artista
    cout << "[BD] Nueva relacion: El usuario " << ua.getIdUsuario() 
         << " comenzo a seguir al artista " << ua.getIdArtista() << endl;
}

void UsuarioArtistaDAOImpl::actualizar(UsuarioArtista ua) {
    // Al ser una tabla de rompimiento pura (ID-ID), no se actualiza. Se borra o se inserta.
    cout << "[BD] Alerta: No se permiten actualizaciones directas en la relacion Usuario-Artista." << endl;
}

void UsuarioArtistaDAOImpl::eliminar(UsuarioArtista ua) {
    // El usuario le dio a "Dejar de seguir"
    cout << "[BD] Rompiendo relacion: El usuario " << ua.getIdUsuario() 
         << " dejo de seguir al artista " << ua.getIdArtista() << endl;
}