#ifndef COLAREPRODUCCIONDAOIMPL_H
#define COLAREPRODUCCIONDAOIMPL_H
#include "ColaReproduccionDAO.h"

//Creamos la Clase ColaReproduccionDAOImpl que hereda de ColaReproduccionDAO para poder interactuar con la BD
class ColaReproduccionDAOImpl : public ColaReproduccionDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(ColaReproduccion cr) override;
    void actualizar(ColaReproduccion cr) override;
    void eliminar(ColaReproduccion cr) override;
};
#endif