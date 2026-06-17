#ifndef ARTISTADAO_H
#define ARTISTADAO_H
#include "database/DAO.h"
#include "models/Artista.h"

//Creamos la clase ArtistaDAO que hereda del DAO principal
//
class ArtistaDAO : public DAO<Artista> {};
#endif