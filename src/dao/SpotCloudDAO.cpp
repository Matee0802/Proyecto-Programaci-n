#include "dao/SpotCloudDAO.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

SpotCloudDAO::SpotCloudDAO(const QSqlDatabase &base) : db(base) {}

QSqlQueryModel *SpotCloudDAO::modeloCanciones(QObject *padre, int idAlbum) const {
    auto *modelo = new QSqlQueryModel(padre);
    QSqlQuery q(db);
    QString sql = "SELECT c.id_cancion, c.titulo, c.duracion, COALESCE(ar.nombre, 'Artista desconocido') AS artista, c.ruta_archivo_mp3 "
                  "FROM canciones c LEFT JOIN albumes al ON c.id_album = al.id_album "
                  "LEFT JOIN artistas ar ON al.id_artista = ar.id_artista";
    if (idAlbum > 0) { sql += " WHERE c.id_album = ?"; q.prepare(sql); q.addBindValue(idAlbum); q.exec(); }
    else q.exec(sql);
    modelo->setQuery(std::move(q));
    error = modelo->lastError().text();
    return modelo;
}

QSqlQueryModel *SpotCloudDAO::modeloBusqueda(QObject *padre, const QString &texto) const {
    auto *modelo = new QSqlQueryModel(padre);
    QSqlQuery q(db);
    q.prepare("SELECT c.id_cancion, c.titulo AS Cancion, COALESCE(ar.nombre, 'Artista desconocido') AS Artista, "
              "COALESCE(al.titulo, 'Sin album') AS Album, COALESCE(ar.genero, 'Sin genero') AS Genero, c.duracion AS Duracion, c.ruta_archivo_mp3 "
              "FROM canciones c LEFT JOIN albumes al ON c.id_album = al.id_album LEFT JOIN artistas ar ON al.id_artista = ar.id_artista "
              "WHERE c.titulo LIKE ? OR ar.nombre LIKE ? OR ar.genero LIKE ? OR al.titulo LIKE ?");
    const QString patron = '%' + texto.trimmed() + '%';
    for (int i = 0; i < 4; ++i) q.addBindValue(patron);
    q.exec(); modelo->setQuery(std::move(q)); error = modelo->lastError().text(); return modelo;
}

QVector<AlbumResumen> SpotCloudDAO::albumesDisponibles(bool soloLocales) const {
    QSqlQuery q(db); QString sql = "SELECT DISTINCT al.id_album, al.titulo, COALESCE(ar.nombre, 'Artista desconocido'), al.ruta_portada "
        "FROM albumes al LEFT JOIN artistas ar ON al.id_artista = ar.id_artista ";
    if (soloLocales) sql += "LEFT JOIN canciones c ON c.id_album = al.id_album WHERE (al.ruta_portada IS NOT NULL AND al.ruta_portada NOT LIKE 'http%') OR (c.ruta_archivo_mp3 IS NOT NULL AND c.ruta_archivo_mp3 NOT LIKE 'http%') ";
    q.exec(sql + "ORDER BY al.titulo"); error = q.lastError().text(); QVector<AlbumResumen> resultado;
    while (q.next()) resultado.push_back({q.value(0).toInt(), q.value(1).toString(), q.value(2).toString(), q.value(3).toString()});
    return resultado;
}

QVector<ElementoAdmin> SpotCloudDAO::elementos(const QString &tipo, const QString &filtro) const {
    const bool esCancion = tipo == "Cancion", esAlbum = tipo == "Album";
    const QString tabla = esCancion ? "canciones" : esAlbum ? "albumes" : "artistas";
    const QString id = esCancion ? "id_cancion" : esAlbum ? "id_album" : "id_artista";
    const QString nombre = esCancion || esAlbum ? "titulo" : "nombre";
    QSqlQuery q(db); q.prepare(QString("SELECT %1, %2 FROM %3 WHERE %2 LIKE ? ORDER BY %2").arg(id, nombre, tabla));
    q.addBindValue('%' + filtro.trimmed() + '%'); q.exec(); error = q.lastError().text(); QVector<ElementoAdmin> r;
    while (q.next()) {
        r.push_back({q.value(0).toInt(), q.value(1).toString()});
    }
    return r;
}
QVector<ElementoAdmin> SpotCloudDAO::artistas() const { return elementos("Artista", ""); }
QVector<ElementoAdmin> SpotCloudDAO::albumes() const { return elementos("Album", ""); }
bool SpotCloudDAO::ejecutar(const QString &sql, const QVariantList &v) { QSqlQuery q(db); q.prepare(sql); for (const auto &x : v) q.addBindValue(x); bool ok=q.exec(); error=q.lastError().text(); return ok; }
bool SpotCloudDAO::crearArtista(const QString &n,const QString &b,const QString &g) { return ejecutar("INSERT INTO artistas (nombre, biografia_corta, genero) VALUES (?, ?, ?)",{n,b,g}); }
bool SpotCloudDAO::crearAlbum(const QString &t,int a,int id,const QString &p) { return ejecutar("INSERT INTO albumes (titulo, anio, id_artista, ruta_portada) VALUES (?, ?, ?, ?)",{t,a,id,p}); }
bool SpotCloudDAO::crearCancion(const QString &t,const QString &d,int id,const QString &a) { return ejecutar("INSERT INTO canciones (titulo, duracion, id_album, ruta_archivo_mp3) VALUES (?, ?, ?, ?)",{t,d,id,a}); }
bool SpotCloudDAO::eliminar(const QString &tipo, int id, QString *motivo) {
    const bool album=tipo=="Album", artista=tipo=="Artista"; QSqlQuery verifica(db);
    if (album) { verifica.prepare("SELECT COUNT(*) FROM canciones WHERE id_album = ?"); verifica.addBindValue(id); }
    if (artista) { verifica.prepare("SELECT COUNT(*) FROM albumes WHERE id_artista = ?"); verifica.addBindValue(id); }
    if (album || artista) { if (!verifica.exec() || !verifica.next()) { error=verifica.lastError().text(); if(motivo)*motivo=error; return false; } if(verifica.value(0).toInt()>0) { if(motivo)*motivo=album?"El álbum tiene canciones cargadas.":"El artista tiene álbumes cargados."; return false; } }
    const QString tabla=tipo=="Cancion"?"canciones":album?"albumes":"artistas"; const QString campo=tipo=="Cancion"?"id_cancion":album?"id_album":"id_artista";
    bool ok=ejecutar(QString("DELETE FROM %1 WHERE %2 = ?").arg(tabla,campo),{id}); if(!ok && motivo)*motivo=error; return ok;
}
UsuarioSesion SpotCloudDAO::iniciarSesion(const QString &correo,const QString &password) const {
    QSqlQuery q(db); q.prepare("SELECT id_usuario, nombre, correo FROM usuarios WHERE correo = ? AND password = ?"); q.addBindValue(correo.trimmed()); q.addBindValue(password); if(!q.exec()||!q.next()){error=q.lastError().text();return {}; } return {q.value(0).toInt(),q.value(1).toString(),q.value(2).toString()};
}
bool SpotCloudDAO::registrar(const QString &nombre,const QString &correo,const QString &password,QString *motivo) {
    QSqlQuery q(db);q.prepare("SELECT 1 FROM usuarios WHERE correo = ?");q.addBindValue(correo.trimmed()); if(q.exec()&&q.next()){if(motivo)*motivo="Ya existe una cuenta con ese correo.";return false;} bool ok=ejecutar("INSERT INTO usuarios (nombre, correo, password) VALUES (?, ?, ?)",{nombre.trimmed(),correo.trimmed(),password});if(!ok&&motivo)*motivo=error;return ok;
}
QString SpotCloudDAO::ultimoError() const { return error; }
