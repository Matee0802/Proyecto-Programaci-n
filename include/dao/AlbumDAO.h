#ifndef ALBUMDAO_H
#define ALBUMDAO_H
#include "database/DAO.h"
#include "models/Album.h"
#include "dao/DTOs.h"
#include <QString>
#include <QVector>

// Creamos la clase AlbumDAO que hereda del DAO principal.
// Ademas del CRUD generico (insertar/actualizar/eliminar), un album necesita
// consultas propias para alimentar la interfaz (grilla de inicio, combos, buscador).
class AlbumDAO : public DAO<Album> {
public:
    virtual ~AlbumDAO() = default;

    // Albumes para mostrar como tarjetas en el inicio. Si soloLocales es true,
    // filtra los que tienen portada o canciones guardadas localmente (sin http).
    virtual QVector<AlbumResumen> listarDisponibles(bool soloLocales) const = 0;

    // Lista simple (id, titulo) para llenar el combo "Album" al cargar una cancion.
    virtual QVector<ElementoAdmin> listarParaCombo() const = 0;

    // Busqueda por titulo, usada por el combo de "Eliminar contenido".
    virtual QVector<ElementoAdmin> buscarPorTitulo(const QString &filtro) const = 0;

    // Texto del ultimo error de SQL, para mostrarlo en la interfaz.
    virtual QString ultimoError() const = 0;
};
#endif
