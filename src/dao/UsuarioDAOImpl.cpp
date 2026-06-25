#include "dao/UsuarioDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void UsuarioDAOImpl::insertar(Usuario u)
{
    QSqlQuery query;
    query.prepare("INSERT INTO usuario (username, email, contraseña) VALUES (:username, :email, :pass)");
    query.bindValue(":username", QString::fromStdString(u.getNombreS()));
    query.bindValue(":email", QString::fromStdString(u.getCorreo()));
    query.bindValue(":contrasenia", QString::fromStdString(u.getPassword()));

    if (!query.exec())
    {
        qDebug() << "Error al insertar Usuario:" << query.lastError().text();
    }
}

void UsuarioDAOImpl::actualizar(Usuario u)
{
    QSqlQuery query;
    query.prepare("UPDATE usuario SET username = :username, email = :email, contraseña = :pass WHERE id_usuario = :id");
    query.bindValue(":username", QString::fromStdString(u.getNombreS()));
    query.bindValue(":email", QString::fromStdString(u.getCorreo()));
    query.bindValue(":contrasenia", QString::fromStdString(u.getPassword()));
    query.bindValue(":id", u.getId());

    if (!query.exec())
    {
        qDebug() << "Error al actualizar Usuario:" << query.lastError().text();
    }
}

void UsuarioDAOImpl::eliminar(Usuario u)
{
    QSqlQuery query;
    query.prepare("DELETE FROM usuario WHERE id_usuario = :id");
    query.bindValue(":id", u.getId());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar Usuario:" << query.lastError().text();
    }
}