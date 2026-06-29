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
```
## Organización del Proyecto

El código sigue una arquitectura modular para facilitar el mantenimiento y la escalabilidad:

```Models/```: Clases que representan las entidades principales (Usuario, Artista, Album, Cancion, Historial, Colas de reproducción).

```DAO/```: Interfaces e implementaciones para el acceso a datos. Separa la persistencia de la lógica de negocio.

```Database/```: Clase Conexion, encargada de gestionar la conexión con el servidor MySQL/MariaDB.

```Ventana Principal/```: Interfaz de usuario (ventanaprincipal.h, .cpp, .ui). Gestiona la navegación, búsqueda y el control del reproductor.

## Estructura de Base de Datos
El proyecto utiliza una base de datos relacional con las siguientes tablas:
**usuarios, artistas, albumes, canciones, historial, cola_reproduccion, cola_canciones y usuarios_artistas.**

La jerarquía para la relación entre el contenido es:
canciones → albumes → artistas
(Una canción pertenece a un álbum, y un álbum pertenece a un artista).

## Requisitos Técnicos
**Framework**: Qt 6

**IDE**: Qt Creator

**Compilador**: Compatible con C++17

**Módulos de Qt**: Widgets, SQL, Multimedia, Network

**Base de Datos**: MySQL o MariaDB

## Cómo Ejecutar
**Abrir Proyecto**: Inicia Qt Creator y abre el archivo SpotCloud.pro.

**Configurar Kit**: Selecciona un kit compatible (ej. Desktop Qt MinGW 64-bit).

**Base de Datos**: Verifica que tu servidor esté activo y la base de datos configurada.

**Conexión**: Ajusta tus credenciales de base de datos en src/database/Conexion.cpp.

**Compilar**: Selecciona Build y ejecuta el proyecto.

## Interfaz y Recursos
La aplicación incluye:

- Navegación superior y vista de álbumes/búsqueda.

- Reproductor inferior fijo con controles multimedia.

- Íconos personalizados mediante la fuente MaterialSymbolsOutlined.ttf cargada desde recursos.qrc.

## Estado Actual

Actualmente SpotCloud permite navegar por álbumes, buscar contenido y reproducir canciones. La interfaz principal cuenta con controles de reproducción, carga de portadas y búsqueda por nombre o género.

## Autor

- **Mateo Valentino Lugo**

## Nota

Proyecto académico individual desarrollado con fines educativos para la materia **Programación**.
