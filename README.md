# SpotCloud

SpotCloud es una aplicación de escritorio desarrollada en C++ con Qt. El proyecto funciona como un reproductor de música con una interfaz inspirada en plataformas de streaming: permite visualizar álbumes, buscar canciones, reproducir música y controlar la reproducción desde una barra inferior.

## Descargas

- [Descargar SpotCloud (Ejecutable .exe)](AQUÍ_VA_TU_LINK_DEL_RAR)
- [Descargar Script de Base de Datos (.sql)](AQUÍ_VA_TU_LINK_DE_LA_BASE_DE_DATOS)

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
- Qt 6
- MySQL/Base de datos

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

`Models/`: Clases que representan las entidades principales (Usuario, Artista, Album, Cancion, Historial, Colas de reproducción).

`DAO/`: Interfaces e implementaciones para el acceso a datos. Separa la persistencia de la lógica de negocio.

`Database/`: Clase Conexion, encargada de gestionar la conexión con el servidor MySQL/MariaDB.

`Ventana Principal/`: Interfaz de usuario (ventanaprincipal.h, .cpp, .ui). Gestiona la navegación, búsqueda y el control del reproductor.

## Estructura de Base de Datos

El proyecto utiliza una base de datos relacional con las siguientes tablas:
**usuarios, artistas, albumes, canciones, historial, cola_reproduccion, cola_canciones y usuarios_artistas.**

La jerarquía para la relación entre el contenido es:
canciones → albumes → artistas
(Una canción pertenece a un álbum, y un álbum pertenece a un artista).

## Requisitos del Sistema

* **Sistema Operativo**: Windows 7 en adelante.
* **Servidor**: XAMPP (MySQL) activo para la base de datos.
* **Conexión**: Asegúrate de que los datos de conexión en el servidor coincidan con la configuración local de la aplicación.

## Cómo Ejecutar

1. **Base de Datos**: Inicia XAMPP, activa MySQL y carga el archivo `.sql` provisto en una base de datos local.
2. **Ejecución**: Ejecuta el archivo **SpotCloud.exe** directamente.

*(Nota: Si eres desarrollador y deseas modificar el código, necesitarás tener instalado Qt Creator y los módulos de Qt 6 correspondientes).*

## Interfaz y Recursos

La aplicación incluye:

* Navegación superior y vista de álbumes/búsqueda.
* Reproductor inferior fijo con controles multimedia.
* Íconos personalizados mediante la fuente MaterialSymbolsOutlined.ttf cargada desde recursos.qrc.

## Estado Actual

Actualmente SpotCloud permite navegar por álbumes, buscar contenido y reproducir canciones. La interfaz principal cuenta con controles de reproducción, carga de portadas y búsqueda por nombre o género.

## Autor

* **Mateo Valentino Lugo**

## Nota

Proyecto académico individual desarrollado con fines educativos para la materia **Programación**.
