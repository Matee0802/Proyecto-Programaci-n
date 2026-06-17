#ifndef ARTISTADAOIMPL_H
#define ARTISTADAOIMPL_H
#include "ArtistaDAO.h"

//Creamos la Clase ArtistaDAOImpl que hereda de ArtistaDAO, que tambien hereda del DAO principal
//para poder interactuar con la BD
class ArtistaDAOImpl : public ArtistaDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(Artista a) override;
    void actualizar(Artista a) override;
    void eliminar(Artista a) override;
};
#endif