#ifndef ALBUMDAOIMPL_H
#define ALBUMDAOIMPL_H
#include "AlbumDAO.h"

// Creamos la Clase AlbumDAOImpl que hereda de AlbumDAO, que tambien hereda del DAO principal
// para poder interactuar con la BD
class AlbumDAOImpl : public AlbumDAO {
public:
    //Le damos las acciones que debe de realizar con la BD
    void insertar(Album a) override;
    void actualizar(Album a) override;
    void eliminar(Album a) override;

    QVector<AlbumResumen> listarDisponibles(bool soloLocales) const override;
    QVector<ElementoAdmin> listarParaCombo() const override;
    QVector<ElementoAdmin> buscarPorTitulo(const QString &filtro) const override;
    QString ultimoError() const override;

private:
    // mutable: las consultas de lectura son const pero igual necesitan guardar
    // el ultimo error para que la ventana lo pueda leer despues con ultimoError().
    mutable QString error;
};
#endif
