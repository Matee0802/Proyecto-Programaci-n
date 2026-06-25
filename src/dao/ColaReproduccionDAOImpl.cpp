#include "dao/ColaReproduccionDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void ColaReproduccionDAOImpl::insertar(ColaReproduccion cr)
{
    QSqlQuery query;
    query.prepare("INSERT INTO cola_reproduccion (id_usuario) VALUES (:id_usuario)");
    query.bindValue(":id_usuario", cr.getIdUsuario());

    if (!query.exec())
    {
        qDebug() << "Error al insertar ColaReproduccion:" << query.lastError().text();
    }
}

void ColaReproduccionDAOImpl::actualizar(ColaReproduccion cr)
{
    QSqlQuery query;
    query.prepare("UPDATE cola_reproduccion SET id_usuario = :id_usuario WHERE id_cola = :id_cola");
    query.bindValue(":id_usuario", cr.getIdUsuario());
    query.bindValue(":id_cola", cr.getIdCola());

    if (!query.exec())
    {
        qDebug() << "Error al actualizar ColaReproduccion:" << query.lastError().text();
    }
}

void ColaReproduccionDAOImpl::eliminar(ColaReproduccion cr)
{
    QSqlQuery query;
    query.prepare("DELETE FROM cola_reproduccion WHERE id_cola = :id_cola");
    query.bindValue(":id_cola", cr.getIdCola());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar ColaReproduccion:" << query.lastError().text();
    }
}