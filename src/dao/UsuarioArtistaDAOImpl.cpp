#include "dao/UsuarioArtistaDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void UsuarioArtistaDAOImpl::insertar(UsuarioArtista ua)
{
    QSqlQuery query;
    query.prepare("INSERT INTO usuario_artista (id_usuario, id_artista) VALUES (:id_usuario, :id_artista)");
    query.bindValue(":id_usuario", ua.getIdUsuario());
    query.bindValue(":id_artista", ua.getIdArtista());

    if (!query.exec())
    {
        qDebug() << "Error al insertar UsuarioArtista:" << query.lastError().text();
    }
}

void UsuarioArtistaDAOImpl::actualizar(UsuarioArtista ua)
{
    // Al ser tabla de rompimiento pura sin campos extra, queda vacío para cumplir la interfaz
    Q_UNUSED(ua);
}

void UsuarioArtistaDAOImpl::eliminar(UsuarioArtista ua)
{
    QSqlQuery query;
    query.prepare("DELETE FROM usuario_artista WHERE id_usuario = :id_usuario AND id_artista = :id_artista");
    query.bindValue(":id_usuario", ua.getIdUsuario());
    query.bindValue(":id_artista", ua.getIdArtista());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar UsuarioArtista:" << query.lastError().text();
    }
}