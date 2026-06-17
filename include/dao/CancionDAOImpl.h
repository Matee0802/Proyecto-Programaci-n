#ifndef CANCIONDAOIMPL_H
#define CANCIONDAOIMPL_H
#include "CancionDAO.h"

//Creamos la Clase UsuarioDAOImpl que hereda de UsuarioDAO, que tambien hereda del DAO principal
//para poder interactuar con la BD
class CancionDAOImpl : public CancionDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(Cancion c) override;
    void actualizar(Cancion c) override;
    void eliminar(Cancion c) override;
};
#endif