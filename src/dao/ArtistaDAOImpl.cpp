#include "dao/ArtistaDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void ArtistaDAOImpl::insertar(Artista art)
{
    QSqlQuery query;
    query.prepare("INSERT INTO artista (nombre, biografia, imagen_url) VALUES (:nombre, :biografia, :foto)");
    query.bindValue(":nombre", QString::fromStdString(art.getNombre()));
    query.bindValue(":biografia", QString::fromStdString(art.getBio()));
    query.bindValue(":genero", QString::fromStdString(art.getGenero()));

    if (!query.exec())
    {
        qDebug() << "Error al insertar Artista:" << query.lastError().text();
    }
}

void ArtistaDAOImpl::actualizar(Artista art)
{
    QSqlQuery query;
    query.prepare("UPDATE artista SET nombre = :nombre, biografia = :biografia, imagen_url = :foto WHERE id_artista = :id");
    query.bindValue(":nombre", QString::fromStdString(art.getNombre()));
    query.bindValue(":biografia", QString::fromStdString(art.getBio()));
    query.bindValue(":genero", QString::fromStdString(art.getGenero()));
    query.bindValue(":id", art.getId());

    if (!query.exec())
    {
        qDebug() << "Error al actualizar Artista:" << query.lastError().text();
    }
}

void ArtistaDAOImpl::eliminar(Artista art)
{
    QSqlQuery query;
    query.prepare("DELETE FROM artista WHERE id_artista = :id");
    query.bindValue(":id", art.getId());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar Artista:" << query.lastError().text();
    }
}