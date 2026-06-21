#ifndef COLACANCIONESDAOIMPL_H
#define COLACANCIONESDAOIMPL_H
#include "ColaCancionesDAO.h"

//Creamos la Clase ColaCancionesDAOImpl que hereda de ColaCancionesDAO para poder interactuar con la BD
class ColaCancionesDAOImpl : public ColaCancionesDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(ColaCanciones cc) override;
    void actualizar(ColaCanciones cc) override;
    void eliminar(ColaCanciones cc) override;
};
#endif