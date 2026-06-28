QT += core gui widgets sql multimedia

TARGET = SpotCloud
TEMPLATE = app

CONFIG += c++11

# Incluimos tus carpetas del proyecto
INCLUDEPATH += include


# --- CONFIGURACIÓN DE MYSQL ---
INCLUDEPATH += C:/mysql-connector-c-6.1.11-winx64/include
LIBS += -LC:/mysql-connector-c-6.1.11-winx64/lib -lmysql

# Agregamos tus cabeceras
HEADERS += include/database/Conexion.h \
           include/database/DAO.h \
           include/models/Album.h \
           include/models/Artista.h \
           include/models/Cancion.h \
           include/models/ColaCanciones.h \
           include/models/ColaReproduccion.h \
           include/models/Historial.h \
           include/models/Usuario.h \
           include/models/UsuarioArtista.h \
           include/dao/AlbumDAO.h \
           include/dao/AlbumDAOImpl.h \
           include/dao/ArtistaDAO.h \
           include/dao/ArtistaDAOImpl.h \
           include/dao/CancionDAO.h \
           include/dao/CancionDAOImpl.h \
           include/dao/ColaCancionesDAO.h \
           include/dao/ColaCancionesDAOImpl.h \
           include/dao/ColaReproduccionDAO.h \
           include/dao/ColaReproduccionDAOImpl.h \
           include/dao/HistorialDAO.h \
           include/dao/HistorialDAOImpl.h \
           include/dao/UsuarioArtistaDAO.h \
           include/dao/UsuarioArtistaDAOImpl.h \
           include/dao/UsuarioDAO.h \
           include/dao/UsuarioDAOImpl.h \
           ventanaprincipal.h

# Agregamos tus fuentes
SOURCES += main.cpp \
           src/dao/AlbumDAOImpl.cpp \
           src/dao/ArtistaDAOImpl.cpp \
           src/dao/CancionDAOImpl.cpp \
           src/dao/UsuarioDAOImpl.cpp \
           src/database/Conexion.cpp \
           src/dao/ColaCancionesDAOImpl.cpp \
           src/dao/ColaReproduccionDAOImpl.cpp \
           src/dao/HistorialDAOImpl.cpp \
           src/dao/UsuarioArtistaDAOImpl.cpp \
           src/models/Album.cpp \
           src/models/Artista.cpp \
           src/models/Cancion.cpp \
           src/models/ColaCanciones.cpp \
           src/models/ColaReproduccion.cpp \
           src/models/Historial.cpp \
           src/models/Usuario.cpp \
           src/models/UsuarioArtista.cpp \
           ventanaprincipal.cpp

FORMS += ventanaprincipal.ui

RESOURCES += recursos.qrc