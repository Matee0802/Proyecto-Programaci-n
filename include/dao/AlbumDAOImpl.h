#ifndef ALBUMDAOIMPL_H
#define ALBUMDAOIMPL_H
#include "AlbumDAO.h"

//Creamos la Clase AlbumDAOImpl que hereda de AlbumDAO, que tambien hereda del DAO principal
//para poder interactuar con la BD
class AlbumDAOImpl : public AlbumDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(Album m) override;
    void actualizar(Album m) override;
    void eliminar(Album m) override;
};
#endif