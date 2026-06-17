#ifndef USUARIODAOIMPL_H
#define USUARIODAOIMPL_H
#include "UsuarioDAO.h"

//Creamos la Clase UsuarioDAOImpl que hereda de UsuarioDAO, que tambien hereda del DAO principal
//para poder interactuar con la BD
class UsuarioDAOImpl : public UsuarioDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(Usuario u) override;
    void actualizar(Usuario u) override;
    void eliminar(Usuario u) override;
};
#endif