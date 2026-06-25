#include "dao/AlbumDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void AlbumDAOImpl::insertar(Album a)
{
    QSqlQuery query;
    query.prepare("INSERT INTO album (titulo, id_artista, anio_lanzamiento, portada_url) VALUES (:titulo, :id_artista, :anio, :portada)");
    query.bindValue(":titulo", QString::fromStdString(a.getTitulo()));
    query.bindValue(":id_artista", a.getIdArtista());
    query.bindValue(":anio", a.getAnio());
    query.bindValue(":portada", QString::fromStdString(a.getRutaPortada()));

    if (!query.exec())
    {
        qDebug() << "Error al insertar Album:" << query.lastError().text();
    }
}

void AlbumDAOImpl::actualizar(Album a)
{
    QSqlQuery query;
    query.prepare("UPDATE album SET titulo = :titulo, id_artista = :id_artista, anio_lanzamiento = :anio, portada_url = :portada WHERE id_album = :id");
    query.bindValue(":titulo", QString::fromStdString(a.getTitulo()));
    query.bindValue(":id_artista", a.getIdArtista());
    query.bindValue(":anio", a.getAnio());
    query.bindValue(":portada", QString::fromStdString(a.getRutaPortada()));
    query.bindValue(":id", a.getIdAlbum());

    if (!query.exec())
    {
        qDebug() << "Error al actualizar Album:" << query.lastError().text();
    }
}

void AlbumDAOImpl::eliminar(Album a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM album WHERE id_album = :id");
    query.bindValue(":id", a.getIdAlbum());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar Album:" << query.lastError().text();
    }
}