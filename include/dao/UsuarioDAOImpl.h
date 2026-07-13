#ifndef USUARIODAOIMPL_H
#define USUARIODAOIMPL_H
#include "UsuarioDAO.h"

class UsuarioDAOImpl : public UsuarioDAO {
public:
    void insertar(Usuario u) override;
    void actualizar(Usuario u) override;
    void eliminar(Usuario u) override;

    UsuarioSesion iniciarSesion(const QString &correo, const QString &password) const override;
    bool registrar(const QString &nombre, const QString &correo,
                    const QString &password, QString *motivo = nullptr) override;
    QString ultimoError() const override;

private:
    mutable QString error;
};
#endif
