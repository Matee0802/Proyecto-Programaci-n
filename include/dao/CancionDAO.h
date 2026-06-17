#ifndef CANCIONDAO_H
#define CANCIONDAO_H
#include "database/DAO.h"
#include "models/Cancion.h"

//Creamos la clase CancionDAO que hereda del DAO principal
//
class CancionDAO : public DAO<Cancion> {};
#endif