#ifndef HISTORIALDAOIMPL_H
#define HISTORIALDAOIMPL_H
#include "HistorialDAO.h"

//Creamos la Clase HistorialDAOImpl que hereda de HistorialDAO para poder interactuar con la BD
class HistorialDAOImpl : public HistorialDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(Historial h) override;
    void actualizar(Historial h) override;
    void eliminar(Historial h) override;
};
#endif