#include "dao/HistorialDAOImpl.h"
#include "include/database/Conexion.h"
#include <iostream>

using namespace std;

// Implementacion de los metodos de la clase HistorialDAOImpl

void HistorialDAOImpl::insertar(Historial h) {
    // Aqui se abre la conexion y se ejecuta el INSERT INTO historial
    cout << "Registrando reproduccion en el historial: Usuario " << h.getIdUsuario() 
         << " escucho la cancion " << h.getIdCancion() << endl;
}

void HistorialDAOImpl::eliminar(Historial h) {
    // Por si el usuario decide borrar un elemento de su historial
    cout << "Eliminando del historial el registro ID: " << h.getIdHistorial() << endl;
}