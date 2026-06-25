## Proyecto: SpotCloud

## Descripción
SpotCloud es una plataforma de software de escritorio de alta fidelidad dedicada a la organización, gestión y reproducción local de archivos de audio. El sistema provee un entorno robusto e independiente que permite a los usuarios navegar por colecciones musicales estructuradas a través de clasificaciones dinámicas por álbumes, artistas y pistas individuales. Al estar diseñado como un sistema nativo local, el software garantiza la privacidad y seguridad total de la información, procesando los datos y los archivos multimedia directamente sobre el almacenamiento del equipo y eliminando la dependencia de conexiones de red externas o servidores de terceros.

El backend del ecosistema se apoya en una arquitectura modular bajo el paradigma de programación orientada a objetos (POO), integrada con el patrón de diseño DAO (Data Access Object). Esto proporciona un desacoplamiento estricto entre los componentes visuales de la interfaz gráfica desarrollada en Qt y las transacciones de persistencia de datos estructuradas en un motor relacional MySQL.

---

## Información Institucional
- **Estudiante:** Mateo Valentino Lugo
- **Institución:** Escuela Secundaria Técnica N°1 de Vicente López Eduardo Ader
- **Curso:** 6° 3°
- **Asignatura:** Laboratorio de Programación
- **Profesores:** Gaston Galeazzi y Andrea Insaurralde

---

## Características Principales y Modos de Operación

### Panel de Usuario General
- Exploración fluida e intuitiva del catálogo musical indexado por artistas y álbumes.
- Sistema de cola de reproducción activa con visualización y secuenciación de pistas en tiempo real.
- Entorno de reproducción de audio nativo optimizado para un uso eficiente de los recursos del hardware.

### Módulo de Administración de Catálogo
- Acceso restringido y protegido mediante un sistema de autenticación centralizado con validación de credenciales criptográficas.
- Herramientas avanzadas para la gestión del catálogo, habilitando operaciones CRUD (alta, baja, modificación y consulta) sobre los registros de canciones, álbumes y artistas.

---

## Requisitos del Entorno de Desarrollo

Para la compilación, despliegue y desarrollo del proyecto se requiere:
- Qt Creator (compatible con Qt 6.11.1 o superior)
- Compilador MinGW de 64 bits
- Servidor MySQL activo con el módulo QMYSQL correctamente configurado y enlazado

---

## Estructura del Código Fuente

La distribución del código fuente se organiza bajo la siguiente estructura modular:
- `include/`: Declaración de interfaces de persistencia (DAOs) y archivos de cabecera (.h) correspondientes a las entidades de negocio.
- `src/models/`: Implementación de los objetos de datos y lógica de dominio (Usuario, Cancion, Album, Artista, Historial, ColaReproduccion, ColaCanciones, UsuarioArtista).
- `src/dao/`: Capa de persistencia encargada de ejecutar las consultas, inserciones y mapeos relacionales mediante la API QSqlQuery de Qt.
- `src/database/`: Componente centralizado para la inicialización, conexión y mantenimiento de los parámetros de comunicación con el motor MySQL.

---

## Configuración Inicial y Ciclo de Construcción

### 1. Inicialización de la Base de Datos
Antes de ejecutar la aplicación, inicie su servidor local de MySQL y monte el esquema relacional correspondiente para generar las tablas del sistema (usuarios, canciones, álbumes, artistas, historiales, colas de reproducción y relaciones de seguimiento).

### 2. Proceso de Compilación en Qt Creator
Para asegurar la correcta vinculación de los módulos por parte del enlazador y evitar conflictos de registros, ejecute estrictamente la siguiente secuencia de comandos dentro del entorno de desarrollo:

1. Abra el archivo de configuración global del proyecto `SpotCloud.pro`.
2. Guarde todos los cambios vigentes en el código utilizando la combinación de teclas `Ctrl + Shift + S`.
3. Haga clic derecho sobre la raíz del proyecto en la barra lateral izquierda y seleccionen la opción **Clean** (Limpiar) para remover binarios antiguos.
4. Haga clic derecho nuevamente sobre el proyecto y seleccione **Run qmake** para actualizar las directivas de construcción del compilador.
5. Inicie la construcción del ejecutable final haciendo clic en el ícono del **Martillo** situado en la esquina inferior izquierda.

---

## Despliegue y Generación del archivo .exe Autónomo

Para ejecutar SpotCloud directamente desde un archivo `.exe` en cualquier computadora con Windows sin necesidad de abrir Qt Creator, el binario debe ser empaquetado junto con sus dependencias y librerías dinámicas utilizando la herramienta integrada `windeployqt`.

### Pasos para Generar el Entorno Distribuible:

1. Compile el proyecto en modo **Release** dentro de Qt Creator (cambiando el selector de construcción del Martillo de Debug a Release).
2. Localice el archivo binario generado `SpotCloud.exe` dentro de la carpeta de construcción externa (ej. `build/.../release/`).
3. Cree una nueva carpeta en su disco duro independiente con el nombre del producto (ej. `C:/SpotCloud_App/`) y copie el archivo `SpotCloud.exe` dentro de ella.
4. Abra la consola de comandos de Qt (la terminal del compilador correspondiente, ej. `Qt 6.11.1 (MinGW 64-bit)`) desde el menú de inicio de Windows.
5. Navegue en la terminal hasta el directorio creado:
   ```powershell
   cd C:\SpotCloud_App
   
