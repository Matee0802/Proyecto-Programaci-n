#ifndef ALBUMDAO_H
#define ALBUMDAO_H
#include "database/DAO.h"
#include "models/Album.h"

//Creamos la clase AlbumDAO que hereda del DAO principal
//
class AlbumDAO : public DAO<Album> {};
#endif