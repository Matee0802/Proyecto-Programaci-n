#include "dao/UsuarioDAOImpl.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

// NOTA: la tabla real es "usuarios" (plural), columnas nombre, correo, password.
// La version anterior apuntaba a "usuario", a columnas "username"/"email"/"contraseña"
// que no existen, y ademas tenia un bug de binding: preparaba ":pass" pero
// bindeaba ":contrasenia", asi que la insercion siempre fallaba.

void UsuarioDAOImpl::insertar(Usuario u)
{
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (nombre, correo, password) "
                  "VALUES (:nombre, :correo, :password)");
    query.bindValue(":nombre", QString::fromStdString(u.getNombreS()));
    query.bindValue(":correo", QString::fromStdString(u.getCorreo()));
    query.bindValue(":password", QString::fromStdString(u.getPassword()));

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al insertar Usuario:" << error;
    } else {
        error.clear();
    }
}

void UsuarioDAOImpl::actualizar(Usuario u)
{
    QSqlQuery query;
    query.prepare("UPDATE usuarios SET nombre = :nombre, correo = :correo, password = :password "
                  "WHERE id_usuario = :id");
    query.bindValue(":nombre", QString::fromStdString(u.getNombreS()));
    query.bindValue(":correo", QString::fromStdString(u.getCorreo()));
    query.bindValue(":password", QString::fromStdString(u.getPassword()));
    query.bindValue(":id", u.getId());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al actualizar Usuario:" << error;
    } else {
        error.clear();
    }
}

void UsuarioDAOImpl::eliminar(Usuario u)
{
    QSqlQuery query;
    query.prepare("DELETE FROM usuarios WHERE id_usuario = :id");
    query.bindValue(":id", u.getId());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al eliminar Usuario:" << error;
    } else {
        error.clear();
    }
}

UsuarioSesion UsuarioDAOImpl::iniciarSesion(const QString &correo, const QString &password) const
{
    QSqlQuery q;
    q.prepare("SELECT id_usuario, nombre, correo FROM usuarios WHERE correo = :correo AND password = :password");
    q.bindValue(":correo", correo.trimmed());
    q.bindValue(":password", password);

    if (!q.exec() || !q.next()) {
        error = q.lastError().text();
        return {};
    }

    return {q.value(0).toInt(), q.value(1).toString(), q.value(2).toString()};
}

bool UsuarioDAOImpl::registrar(const QString &nombre, const QString &correo,
                                const QString &password, QString *motivo)
{
    QSqlQuery verifica;
    verifica.prepare("SELECT 1 FROM usuarios WHERE correo = :correo");
    verifica.bindValue(":correo", correo.trimmed());

    if (verifica.exec() && verifica.next()) {
        if (motivo) *motivo = "Ya existe una cuenta con ese correo.";
        return false;
    }

    Usuario u(nombre.trimmed().toStdString(), correo.trimmed().toStdString(), password.toStdString());
    insertar(u);

    const bool ok = error.isEmpty();
    if (!ok && motivo) *motivo = error;
    return ok;
}

QString UsuarioDAOImpl::ultimoError() const
{
    return error;
}
