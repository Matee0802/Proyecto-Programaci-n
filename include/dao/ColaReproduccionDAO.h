#ifndef COLAREPRODUCCIONDAO_H
#define COLAREPRODUCCIONDAO_H
#include "database/DAO.h"
#include "models/ColaReproduccion.h"

//Creamos la clase ColaReproduccionDAO que hereda del DAO principal
class ColaReproduccionDAO : public DAO<ColaReproduccion> {};
#endif