#ifndef COLACANCIONESDAO_H
#define COLACANCIONESDAO_H
#include "database/DAO.h"
#include "models/ColaCanciones.h"

//Creamos la clase ColaCancionesDAO que hereda del DAO principal
class ColaCancionesDAO : public DAO<ColaCanciones> {};
#endif