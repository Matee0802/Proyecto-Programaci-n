#ifndef USUARIODAO_H
#define USUARIODAO_H
#include "database/DAO.h"
#include "models/Usuario.h"
#include "dao/DTOs.h"
#include <QString>

class UsuarioDAO : public DAO<Usuario> {
public:
    virtual ~UsuarioDAO() = default;

    // Valida correo/contraseña. Si no matchea ninguna fila, devuelve una
    // UsuarioSesion invalida (valido() == false).
    virtual UsuarioSesion iniciarSesion(const QString &correo, const QString &password) const = 0;

    // Crea una cuenta nueva. Si el correo ya existe, devuelve false y llena motivo.
    virtual bool registrar(const QString &nombre, const QString &correo,
                            const QString &password, QString *motivo = nullptr) = 0;

    virtual QString ultimoError() const = 0;
};
#endif
