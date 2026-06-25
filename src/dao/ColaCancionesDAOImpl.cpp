#include "dao/ColaCancionesDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void ColaCancionesDAOImpl::insertar(ColaCanciones cc)
{
    QSqlQuery query;
    query.prepare("INSERT INTO cola_canciones (id_cola, id_cancion, orden, reproducida) VALUES (:id_cola, :id_cancion, :orden, :reproducida)");
    query.bindValue(":id_cola", cc.getIdCola());
    query.bindValue(":id_cancion", cc.getIdCancion());
    query.bindValue(":orden", cc.getOrden());
    query.bindValue(":reproducida", cc.getReproducida());

    if (!query.exec())
    {
        qDebug() << "Error al insertar ColaCanciones:" << query.lastError().text();
    }
}

void ColaCancionesDAOImpl::actualizar(ColaCanciones cc)
{
    QSqlQuery query;
    query.prepare("UPDATE cola_canciones SET orden = :orden, reproducida = :reproducida WHERE id_cola = :id_cola AND id_cancion = :id_cancion");
    query.bindValue(":orden", cc.getOrden());
    query.bindValue(":reproducida", cc.getReproducida());
    query.bindValue(":id_cola", cc.getIdCola());
    query.bindValue(":id_cancion", cc.getIdCancion());

    if (!query.exec())
    {
        qDebug() << "Error al actualizar ColaCanciones:" << query.lastError().text();
    }
}

void ColaCancionesDAOImpl::eliminar(ColaCanciones cc)
{
    QSqlQuery query;
    query.prepare("DELETE FROM cola_canciones WHERE id_cola = :id_cola AND id_cancion = :id_cancion");
    query.bindValue(":id_cola", cc.getIdCola());
    query.bindValue(":id_cancion", cc.getIdCancion());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar ColaCanciones:" << query.lastError().text();
    }
}