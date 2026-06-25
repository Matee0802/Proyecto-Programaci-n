#include "dao/HistorialDAOImpl.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void HistorialDAOImpl::insertar(Historial h)
{
    QSqlQuery query;
    query.prepare("INSERT INTO historial (id_usuario, id_cancion, fecha_reproduccion) VALUES (:id_usuario, :id_cancion, NOW())");
    query.bindValue(":id_usuario", h.getIdUsuario());
    query.bindValue(":id_cancion", h.getIdCancion());

    if (!query.exec())
    {
        qDebug() << "Error al insertar en Historial:" << query.lastError().text();
    }
}

void HistorialDAOImpl::actualizar(Historial h)
{
    // El historial no se suele actualizar, pero se pone para cumplir la interfaz del DAO
    Q_UNUSED(h);
}

void HistorialDAOImpl::eliminar(Historial h)
{
    QSqlQuery query;
    query.prepare("DELETE FROM historial WHERE id_historial = :id_historial");
    query.bindValue(":id_historial", h.getIdHistorial());

    if (!query.exec())
    {
        qDebug() << "Error al eliminar de Historial:" << query.lastError().text();
    }
}