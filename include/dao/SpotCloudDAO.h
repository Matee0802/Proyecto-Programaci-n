#ifndef SPOTCLOUDDAO_H
#define SPOTCLOUDDAO_H

#include <QSqlDatabase>
#include <QString>
#include <QVector>
#include <QVariant>

class QObject;
class QSqlQueryModel;

// DTOs: datos listos para mostrar, sin dependencias con widgets de Qt.
struct AlbumResumen { int id; QString titulo; QString artista; QString portada; };
struct ElementoAdmin { int id; QString nombre; };
struct UsuarioSesion { int id = 0; QString nombre; QString correo; bool valido() const { return id > 0; } };

// Único punto de acceso SQL que usa la aplicación de escritorio.
// La ventana no debe preparar ni ejecutar consultas SQL.
class SpotCloudDAO {
public:
    explicit SpotCloudDAO(const QSqlDatabase &base);
    QSqlQueryModel *modeloCanciones(QObject *padre, int idAlbum = 0) const;
    QSqlQueryModel *modeloBusqueda(QObject *padre, const QString &texto) const;
    QVector<AlbumResumen> albumesDisponibles(bool soloLocales) const;
    QVector<ElementoAdmin> artistas() const;
    QVector<ElementoAdmin> albumes() const;
    QVector<ElementoAdmin> elementos(const QString &tipo, const QString &filtro) const;
    bool crearArtista(const QString &nombre, const QString &bio, const QString &genero);
    bool crearAlbum(const QString &titulo, int anio, int idArtista, const QString &portada);
    bool crearCancion(const QString &titulo, const QString &duracion, int idAlbum, const QString &archivo);
    bool eliminar(const QString &tipo, int id, QString *motivo = nullptr);
    UsuarioSesion iniciarSesion(const QString &correo, const QString &password) const;
    bool registrar(const QString &nombre, const QString &correo, const QString &password, QString *motivo = nullptr);
    QString ultimoError() const;

private:
    QSqlDatabase db;
    mutable QString error;
    bool ejecutar(const QString &sql, const QVariantList &valores = {});
};

#endif
