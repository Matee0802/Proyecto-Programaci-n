# SpotCloud

SpotCloud es una aplicación de escritorio desarrollada en C++ con Qt. El proyecto funciona como un reproductor de música con una interfaz inspirada en plataformas de streaming: permite visualizar álbumes, buscar canciones, reproducir música y controlar la reproducción desde una barra inferior.

## Funcionalidades

- Visualización de álbumes en la pantalla de inicio.
- Portadas de álbumes cargadas desde rutas locales o URLs externas.
- Reproducción de canciones.
- Controles de reproducir/pausar, anterior, siguiente, aleatorio y repetir.
- Control de volumen.
- Barra de progreso de la canción.
- Búsqueda por canción, artista, álbum o género.
- Reproducción desde la vista de álbum.
- Organización del código con modelos, DAOs y conexión a base de datos.

## Tecnologías Utilizadas

- C++
- Qt Widgets
- Qt Multimedia
- Qt SQL
- Qt Network
- MySQL/MariaDB
- Qt Creator

## Estructura Del Proyecto

```txt
SpotCloud/
├── include/
│   ├── dao/
│   ├── database/
│   └── models/
├── src/
│   ├── dao/
│   ├── database/
│   └── models/
├── recursos/
│   └── fonts/
├── main.cpp
├── ventanaprincipal.cpp
├── ventanaprincipal.h
├── ventanaprincipal.ui
├── recursos.qrc
└── SpotCloud.pro
Organización Del Código
Models
Contiene las clases que representan las entidades principales del sistema:
Usuario
Artista
Album
Cancion
Historial
ColaReproduccion
ColaCanciones
UsuarioArtista
DAO
Contiene las interfaces e implementaciones para acceder a los datos de la base de datos. Esta capa permite separar la lógica de persistencia del resto de la aplicación.
Database
Contiene la clase Conexion, encargada de abrir y manejar la conexión con la base de datos.
Ventana Principal
Los archivos ventanaprincipal.h, ventanaprincipal.cpp y ventanaprincipal.ui contienen la interfaz principal de la aplicación. Desde ahí se cargan los álbumes, se realizan búsquedas y se controla el reproductor.
Base De Datos
El proyecto trabaja con una base de datos relacional. Las tablas principales son:
usuarios
artistas
albumes
canciones
historial
cola_reproduccion
cola_canciones
usuarios_artistas
La relación usada para mostrar canciones con su artista es:
canciones -> albumes -> artistas
Es decir, una canción pertenece a un álbum, y un álbum pertenece a un artista.
Requisitos
Para compilar y ejecutar el proyecto se necesita:
Qt 6
Qt Creator
Compilador compatible con C++17
Módulos de Qt:Widgets
SQL
Multimedia
Network

Servidor MySQL o MariaDB
Base de datos configurada con las tablas del proyecto
Cómo Ejecutar El Proyecto
Abrir Qt Creator.
Seleccionar Open Project.
Abrir el archivo:
SpotCloud.pro
Configurar el kit de compilación, por ejemplo:
Desktop Qt MinGW 64-bit
Verificar que la base de datos esté creada y activa.
Revisar la configuración de conexión en:
src/database/Conexion.cpp
Compilar y ejecutar el proyecto desde Qt Creator.
Recursos
El proyecto usa recursos de Qt mediante:
recursos.qrc
Dentro de los recursos se incluye la fuente:
MaterialSymbolsOutlined.ttf
Esta fuente se utiliza para mostrar íconos en los botones del reproductor.
Interfaz
La aplicación está organizada en una ventana principal con:
Navegación superior.
Página de inicio con álbumes.
Página de búsqueda.
Página de álbum con canciones.
Reproductor inferior fijo.
## Estado Actual

Actualmente SpotCloud permite navegar por álbumes, buscar contenido y reproducir canciones. La interfaz principal cuenta con controles de reproducción, carga de portadas y búsqueda por nombre o género.

## Autor

- Mateo Valentino Lugo

## Nota

Proyecto académico individual desarrollado con fines educativos para la materia Programación.
