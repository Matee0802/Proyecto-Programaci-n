#ifndef DAO_DTOS_H
#define DAO_DTOS_H
#include <QString>

// DTOs: datos ya listos para mostrar en la interfaz, sin dependencias de widgets de Qt.
// Los usan varios DAOs (Album, Artista, Cancion, Usuario) para no repetir estas
// estructuras ni forzar a la ventana a conocer las tablas de la base de datos.

// Resumen de un album para mostrar como "card" en el inicio.
struct AlbumResumen {
    int id;
    QString titulo;
    QString artista;
    QString portada;
};

// Elemento generico (id + nombre) para llenar combos: artistas, albumes o canciones.
struct ElementoAdmin {
    int id;
    QString nombre;
};

// Datos minimos de un usuario ya logueado.
struct UsuarioSesion {
    int id = 0;
    QString nombre;
    QString correo;
    bool valido() const { return id > 0; }
};

#endif // DAO_DTOS_H
