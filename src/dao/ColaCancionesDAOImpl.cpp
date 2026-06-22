#include "dao/ColaCancionesDAOImpl.h"
#include "database/Conexion.h"
#include <iostream>

using namespace std;

// Implementacion de los metodos de la clase ColaCancionesDAOImpl
void ColaCancionesDAOImpl::insertar(ColaCanciones cc) {
    // Agrega una cancion a la fila de espera de una cola especifica
    cout << "[BD] Agregando cancion ID " << cc.getIdCancion() 
         << " a la cola ID " << cc.getIdCola() 
         << " en la posicion " << cc.getOrden() << endl;
}

void ColaCancionesDAOImpl::actualizar(ColaCanciones cc) {
    // Este es clave: cambia el estado 'reproducida' (true/false) al pasar de cancion
    cout << "[BD] Modificando estado en cola: Cancion ID " << cc.getIdCancion() 
         << " -> Reproducida: " << (cc.getReproducida() ? "SI" : "NO") << endl;
}

void ColaCancionesDAOImpl::eliminar(ColaCanciones cc) {
    // Si el usuario remueve una cancion manual de la lista de espera
    cout << "[BD] Removiendo cancion ID " << cc.getIdCancion() 
         << " de la cola ID " << cc.getIdCola() << endl;
}