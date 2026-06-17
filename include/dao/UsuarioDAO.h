#ifndef USUARIODAO_H
#define USUARIODAO_H
#include "database/DAO.h"
#include "models/Usuario.h"

//Creamos la clase UsuarioDAO que hereda del DAO principal
//
class UsuarioDAO : public DAO<Usuario> {};
#endif