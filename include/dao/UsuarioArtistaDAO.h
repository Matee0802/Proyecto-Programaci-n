#ifndef USUARIOARTISTADAO_H
#define USUARIOARTISTADAO_H
#include "database/DAO.h"
#include "models/UsuarioArtista.h"

//Creamos la clase UsuarioArtistaDAO que hereda del DAO principal
class UsuarioArtistaDAO : public DAO<UsuarioArtista> {};
#endif