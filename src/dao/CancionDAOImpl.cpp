#include "dao/CancionDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void CancionDAOImpl::insertar(Cancion c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO cancion (titulo, id_album, duracion, archivo_url) VALUES (:titulo, :id_album, :duracion, :archivo)");
    query.bindValue(":titulo", QString::fromStdString(c.getTitulo()));
    query.bindValue(":id_album", c.getIdAlbum());
    query.bindValue(":duracion",  QString::fromStdString(c.getDuracion()));
    query.bindValue(":archivo", QString::fromStdString(c.getRuta()));

    if (!query.exec())
    {
        qDebug() << "Error al insertar Cancion:" << query.lastError().text();
    }
}

void CancionDAOImpl::actualizar(Cancion c)
{
    QSqlQuery query;
    query.prepare("UPDATE cancion SET titulo = :titulo, id_album = :id_album, duracion = :duracion, archivo_url = :archivo WHERE id_cancion = :id");
    query.bindValue(":titulo", QString::fromStdString(c.getTitulo()));
    query.bindValue(":id_album", c.getIdAlbum());
    query.bindValue(":duracion",  QString::fromStdString(c.getDuracion()));
    query.bindValue(":archivo", QString::fromStdString(c.getRuta()));
    query.bindValue(":id", c.getId());

    if (!query.exec())
    {
        qDebug() << "Error al actualizar Cancion:" << query.lastError().text();
    }
}

void CancionDAOImpl::eliminar(Cancion c)
{
    QSqlQuery query;
    query.prepare("DELETE FROM cancion WHERE id_cancion = :id");
    query.bindValue(":id", c.getId());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar Cancion:" << query.lastError().text();
    }
}