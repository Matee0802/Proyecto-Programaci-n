#include "dao/AlbumDAOImpl.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

// NOTA: la tabla real en la base de datos es "albumes" (plural), con las
// columnas titulo, anio, id_artista, ruta_portada. Antes esta clase apuntaba
// a una tabla "album" con otros nombres de columna que no existen en la BD.

void AlbumDAOImpl::insertar(Album a)
{
    QSqlQuery query;
    query.prepare("INSERT INTO albumes (titulo, anio, id_artista, ruta_portada) "
                  "VALUES (:titulo, :anio, :id_artista, :portada)");
    query.bindValue(":titulo", QString::fromStdString(a.getTitulo()));
    query.bindValue(":anio", a.getAnio());
    query.bindValue(":id_artista", a.getIdArtista());
    query.bindValue(":portada", QString::fromStdString(a.getRutaPortada()));

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al insertar Album:" << error;
    } else {
        error.clear();
    }
}

void AlbumDAOImpl::actualizar(Album a)
{
    QSqlQuery query;
    query.prepare("UPDATE albumes SET titulo = :titulo, anio = :anio, id_artista = :id_artista, "
                  "ruta_portada = :portada WHERE id_album = :id");
    query.bindValue(":titulo", QString::fromStdString(a.getTitulo()));
    query.bindValue(":anio", a.getAnio());
    query.bindValue(":id_artista", a.getIdArtista());
    query.bindValue(":portada", QString::fromStdString(a.getRutaPortada()));
    query.bindValue(":id", a.getIdAlbum());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al actualizar Album:" << error;
    } else {
        error.clear();
    }
}

void AlbumDAOImpl::eliminar(Album a)
{
    // Regla de negocio: no se puede borrar un album que todavia tiene canciones cargadas.
    QSqlQuery verifica;
    verifica.prepare("SELECT COUNT(*) FROM canciones WHERE id_album = :id");
    verifica.bindValue(":id", a.getIdAlbum());

    if (!verifica.exec() || !verifica.next()) {
        error = verifica.lastError().text();
        return;
    }
    if (verifica.value(0).toInt() > 0) {
        error = "El álbum tiene canciones cargadas.";
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM albumes WHERE id_album = :id");
    query.bindValue(":id", a.getIdAlbum());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al eliminar Album:" << error;
    } else {
        error.clear();
    }
}

QVector<AlbumResumen> AlbumDAOImpl::listarDisponibles(bool soloLocales) const
{
    QSqlQuery q;
    QString sql = "SELECT DISTINCT al.id_album, al.titulo, COALESCE(ar.nombre, 'Artista desconocido'), al.ruta_portada "
                  "FROM albumes al LEFT JOIN artistas ar ON al.id_artista = ar.id_artista ";

    if (soloLocales) {
        sql += "LEFT JOIN canciones c ON c.id_album = al.id_album "
               "WHERE (al.ruta_portada IS NOT NULL AND al.ruta_portada NOT LIKE 'http%') "
               "OR (c.ruta_archivo_mp3 IS NOT NULL AND c.ruta_archivo_mp3 NOT LIKE 'http%') ";
    }

    q.exec(sql + "ORDER BY al.titulo");
    error = q.lastError().text();

    QVector<AlbumResumen> resultado;
    while (q.next()) {
        resultado.push_back({q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(), q.value(3).toString()});
    }
    return resultado;
}

QVector<ElementoAdmin> AlbumDAOImpl::listarParaCombo() const
{
    return buscarPorTitulo("");
}

QVector<ElementoAdmin> AlbumDAOImpl::buscarPorTitulo(const QString &filtro) const
{
    QSqlQuery q;
    q.prepare("SELECT id_album, titulo FROM albumes WHERE titulo LIKE :filtro ORDER BY titulo");
    q.bindValue(":filtro", '%' + filtro.trimmed() + '%');
    q.exec();
    error = q.lastError().text();

    QVector<ElementoAdmin> resultado;
    while (q.next()) {
        resultado.push_back({q.value(0).toInt(), q.value(1).toString()});
    }
    return resultado;
}

QString AlbumDAOImpl::ultimoError() const
{
    return error;
}
