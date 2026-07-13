#include "dao/ArtistaDAOImpl.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

// NOTA: la tabla real es "artistas" (plural), columnas nombre, biografia_corta, genero.
// La version anterior apuntaba a "artista" y ademas tenia un bug: preparaba el
// placeholder ":foto" pero despues bindeaba ":genero", que no existe en el SQL,
// asi que el genero nunca se guardaba y la insercion fallaba.

void ArtistaDAOImpl::insertar(Artista art)
{
    QSqlQuery query;
    query.prepare("INSERT INTO artistas (nombre, biografia_corta, genero) "
                  "VALUES (:nombre, :biografia, :genero)");
    query.bindValue(":nombre", QString::fromStdString(art.getNombre()));
    query.bindValue(":biografia", QString::fromStdString(art.getBio()));
    query.bindValue(":genero", QString::fromStdString(art.getGenero()));

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al insertar Artista:" << error;
    } else {
        error.clear();
    }
}

void ArtistaDAOImpl::actualizar(Artista art)
{
    QSqlQuery query;
    query.prepare("UPDATE artistas SET nombre = :nombre, biografia_corta = :biografia, "
                  "genero = :genero WHERE id_artista = :id");
    query.bindValue(":nombre", QString::fromStdString(art.getNombre()));
    query.bindValue(":biografia", QString::fromStdString(art.getBio()));
    query.bindValue(":genero", QString::fromStdString(art.getGenero()));
    query.bindValue(":id", art.getId());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al actualizar Artista:" << error;
    } else {
        error.clear();
    }
}

void ArtistaDAOImpl::eliminar(Artista art)
{
    // Regla de negocio: no se puede borrar un artista que todavia tiene albumes cargados.
    QSqlQuery verifica;
    verifica.prepare("SELECT COUNT(*) FROM albumes WHERE id_artista = :id");
    verifica.bindValue(":id", art.getId());

    if (!verifica.exec() || !verifica.next()) {
        error = verifica.lastError().text();
        return;
    }
    if (verifica.value(0).toInt() > 0) {
        error = "El artista tiene álbumes cargados.";
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM artistas WHERE id_artista = :id");
    query.bindValue(":id", art.getId());

    if (!query.exec()) {
        error = query.lastError().text();
        qDebug() << "Error al eliminar Artista:" << error;
    } else {
        error.clear();
    }
}

QVector<ElementoAdmin> ArtistaDAOImpl::listarParaCombo() const
{
    return buscarPorNombre("");
}

QVector<ElementoAdmin> ArtistaDAOImpl::buscarPorNombre(const QString &filtro) const
{
    QSqlQuery q;
    q.prepare("SELECT id_artista, nombre FROM artistas WHERE nombre LIKE :filtro ORDER BY nombre");
    q.bindValue(":filtro", '%' + filtro.trimmed() + '%');
    q.exec();
    error = q.lastError().text();

    QVector<ElementoAdmin> resultado;
    while (q.next()) {
        resultado.push_back({q.value(0).toInt(), q.value(1).toString()});
    }
    return resultado;
}

QString ArtistaDAOImpl::ultimoError() const
{
    return error;
}
