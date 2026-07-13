#ifndef ARTISTADAO_H
#define ARTISTADAO_H
#include "database/DAO.h"
#include "models/Artista.h"
#include "dao/DTOs.h"
#include <QString>
#include <QVector>

class ArtistaDAO : public DAO<Artista> {
public:
    virtual ~ArtistaDAO() = default;

    // Lista simple (id, nombre) para el combo "Artista" al cargar un album.
    virtual QVector<ElementoAdmin> listarParaCombo() const = 0;

    // Busqueda por nombre, usada por el combo de "Eliminar contenido".
    virtual QVector<ElementoAdmin> buscarPorNombre(const QString &filtro) const = 0;

    virtual QString ultimoError() const = 0;
};
#endif
