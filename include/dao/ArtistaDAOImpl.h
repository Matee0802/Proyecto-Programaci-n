#ifndef ARTISTADAOIMPL_H
#define ARTISTADAOIMPL_H
#include "ArtistaDAO.h"

class ArtistaDAOImpl : public ArtistaDAO {
public:
    void insertar(Artista art) override;
    void actualizar(Artista art) override;
    void eliminar(Artista art) override;

    QVector<ElementoAdmin> listarParaCombo() const override;
    QVector<ElementoAdmin> buscarPorNombre(const QString &filtro) const override;
    QString ultimoError() const override;

private:
    mutable QString error;
};
#endif
