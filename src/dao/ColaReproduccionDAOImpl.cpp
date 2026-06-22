#include "dao/ColaReproduccionDAOImpl.h"
#include "database/Conexion.h"
#include <iostream>

using namespace std;

// Implementacion de los metodos de la clase ColaReproduccionDAOImpl
void ColaReproduccionDAOImpl::insertar(ColaReproduccion cr) {
    // Crea la fila principal asignada al usuario
    cout << "Creando nueva cola de reproduccion para el usuario ID: " << cr.getIdUsuario() << endl;
}

void ColaReproduccionDAOImpl::actualizar(ColaReproduccion cr) {
    // Por si se reasigna o cambia la configuracion de la cola
    cout << "Actualizando cola de reproduccion ID: " << cr.getIdCola() << endl;
}

void ColaReproduccionDAOImpl::eliminar(ColaReproduccion cr) {
    // Si se limpia o elimina la sesion de la cola activa
    cout << "[BD] Eliminando por completo la cola de reproduccion ID: " << cr.getIdCola() << endl;
}