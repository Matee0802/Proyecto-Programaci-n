#include "dao/CancionDAOImpl.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QDebug>

// NOTA: la tabla real es "canciones" (plural), columnas titulo, duracion,
// id_album, ruta_archivo_mp3. La version anterior apuntaba a "cancion" y a
// la columna "archivo_url", que no existen en la BD.

void CancionDAOImpl::insertar(Cancion c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO canciones (titulo, id_album, duracion, ruta_archivo_mp3) "
                  "VALUES (:titulo, :id_album, :duracion, :archivo)");
    query.bindValue(":titulo", QString::fromStdString(c.getTitulo()));
    query.bindValue(":id_album", c.getIdAlbum());
    query.bindValue(":duracion", QString::fromStdString(c.getDuracion()));
    query.bindValue(":archivo", QString::fromStdString(c.getRuta()));

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al insertar Cancion:" << error;
    } else {
        error.clear();
    }
}

void CancionDAOImpl::actualizar(Cancion c)
{
    QSqlQuery query;
    query.prepare("UPDATE canciones SET titulo = :titulo, id_album = :id_album, duracion = :duracion, "
                  "ruta_archivo_mp3 = :archivo WHERE id_cancion = :id");
    query.bindValue(":titulo", QString::fromStdString(c.getTitulo()));
    query.bindValue(":id_album", c.getIdAlbum());
    query.bindValue(":duracion", QString::fromStdString(c.getDuracion()));
    query.bindValue(":archivo", QString::fromStdString(c.getRuta()));
    query.bindValue(":id", c.getId());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al actualizar Cancion:" << error;
    } else {
        error.clear();
    }
}

void CancionDAOImpl::eliminar(Cancion c)
{
    QSqlQuery query;
    query.prepare("DELETE FROM canciones WHERE id_cancion = :id");
    query.bindValue(":id", c.getId());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al eliminar Cancion:" << error;
    } else {
        error.clear();
    }
}

QSqlQueryModel *CancionDAOImpl::modeloCanciones(QObject *padre, int idAlbum) const
{
    auto *modelo = new QSqlQueryModel(padre);
    QSqlQuery q;
    QString sql = "SELECT c.id_cancion, c.titulo, c.duracion, COALESCE(ar.nombre, 'Artista desconocido') AS artista, c.ruta_archivo_mp3 "
                  "FROM canciones c LEFT JOIN albumes al ON c.id_album = al.id_album "
                  "LEFT JOIN artistas ar ON al.id_artista = ar.id_artista";

    if (idAlbum > 0) {
        sql += " WHERE c.id_album = ?";
        q.prepare(sql);
        q.addBindValue(idAlbum);
        q.exec();
    } else {
        q.exec(sql);
    }

    modelo->setQuery(std::move(q));
    error = modelo->lastError().text();
    return modelo;
}

QSqlQueryModel *CancionDAOImpl::modeloBusqueda(QObject *padre, const QString &texto) const
{
    auto *modelo = new QSqlQueryModel(padre);
    QSqlQuery q;
    q.prepare("SELECT c.id_cancion, c.titulo AS Cancion, COALESCE(ar.nombre, 'Artista desconocido') AS Artista, "
              "COALESCE(al.titulo, 'Sin album') AS Album, COALESCE(ar.genero, 'Sin genero') AS Genero, c.duracion AS Duracion, c.ruta_archivo_mp3 "
              "FROM canciones c LEFT JOIN albumes al ON c.id_album = al.id_album LEFT JOIN artistas ar ON al.id_artista = ar.id_artista "
              "WHERE c.titulo LIKE ? OR ar.nombre LIKE ? OR ar.genero LIKE ? OR al.titulo LIKE ?");

    const QString patron = '%' + texto.trimmed() + '%';
    for (int i = 0; i < 4; ++i) q.addBindValue(patron);

    q.exec();
    modelo->setQuery(std::move(q));
    error = modelo->lastError().text();
    return modelo;
}

QVector<ElementoAdmin> CancionDAOImpl::buscarPorTitulo(const QString &filtro) const
{
    QSqlQuery q;
    q.prepare("SELECT id_cancion, titulo FROM canciones WHERE titulo LIKE :filtro ORDER BY titulo");
    q.bindValue(":filtro", '%' + filtro.trimmed() + '%');
    q.exec();
    error = q.lastError().text();

    QVector<ElementoAdmin> resultado;
    while (q.next()) {
        resultado.push_back({q.value(0).toInt(), q.value(1).toString()});
    }
    return resultado;
}

QString CancionDAOImpl::ultimoError() const
{
    return error;
}
