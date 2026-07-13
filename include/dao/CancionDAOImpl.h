#ifndef CANCIONDAOIMPL_H
#define CANCIONDAOIMPL_H
#include "CancionDAO.h"

class CancionDAOImpl : public CancionDAO {
public:
    void insertar(Cancion c) override;
    void actualizar(Cancion c) override;
    void eliminar(Cancion c) override;

    QSqlQueryModel *modeloCanciones(QObject *padre, int idAlbum = 0) const override;
    QSqlQueryModel *modeloBusqueda(QObject *padre, const QString &texto) const override;
    QVector<ElementoAdmin> buscarPorTitulo(const QString &filtro) const override;
    QString ultimoError() const override;

private:
    mutable QString error;
};
#endif
