#ifndef CANCIONDAO_H
#define CANCIONDAO_H
#include "database/DAO.h"
#include "models/Cancion.h"
#include "dao/DTOs.h"
#include <QString>
#include <QVector>

class QObject;
class QSqlQueryModel;

// Ademas del CRUD, CancionDAO expone consultas "de vista": arman un
// QSqlQueryModel listo para conectar a una QTableView, con los JOIN a
// albumes/artistas ya resueltos. Esto es lo que antes hacia SpotCloudDAO
// con modeloCanciones()/modeloBusqueda(); tiene sentido que vivan aca porque
// son consultas centradas en la tabla canciones.
class CancionDAO : public DAO<Cancion> {
public:
    virtual ~CancionDAO() = default;

    // Canciones de un album (idAlbum > 0) o de todo el catalogo (idAlbum == 0).
    virtual QSqlQueryModel *modeloCanciones(QObject *padre, int idAlbum = 0) const = 0;

    // Busqueda libre por cancion, artista, album o genero.
    virtual QSqlQueryModel *modeloBusqueda(QObject *padre, const QString &texto) const = 0;

    // Busqueda por titulo, usada por el combo de "Eliminar contenido".
    virtual QVector<ElementoAdmin> buscarPorTitulo(const QString &filtro) const = 0;

    virtual QString ultimoError() const = 0;
};
#endif
