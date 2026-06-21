#ifndef HISTORIALDAO_H
#define HISTORIALDAO_H
#include "database/DAO.h"
#include "models/Historial.h"

//Creamos la clase HistorialDAO que hereda del DAO principal
class HistorialDAO : public DAO<Historial> {};
#endif