#ifndef USUARIOARTISTADAOIMPL_H
#define USUARIOARTISTADAOIMPL_H
#include "UsuarioArtistaDAO.h"

//Creamos la Clase UsuarioArtistaDAOImpl que hereda de UsuarioArtistaDAO para poder interactuar con la BD
class UsuarioArtistaDAOImpl : public UsuarioArtistaDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(UsuarioArtista ua) override;
    void actualizar(UsuarioArtista ua) override;
    void eliminar(UsuarioArtista ua) override;
};
#endif