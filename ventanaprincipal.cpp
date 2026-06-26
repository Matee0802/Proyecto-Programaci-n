#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "database/Conexion.h"
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    // 1. Instanciamos la clase de conexión para abrir MySQL
    Conexion bd;
    if (bd.conectar())
    {
        qDebug() << "Conexión exitosa con MySQL. Cargando grilla de canciones...";

        // 2. Creamos el modelo de consulta de Qt
        QSqlTableModel *modelo = new QSqlTableModel(this, bd.getDB());
        // (Le pasamos bd.getDB() para que el modelo sepa qué conexión ODBC usar)

        // Ejecutamos el SELECT directo para la vista del usuario
        // 1. Hacemos la consulta limpia sin los "AS"
        // 1. Volvemos al método nativo: le pasamos la tabla completa
        modelo->setTable("canciones");

        // 2. Cargamos los datos reales de la base a la memoria
        modelo->select();

        // 3. Le ponemos los títulos limpios a las primeras tres columnas
        modelo->setHeaderData(0, Qt::Horizontal, "ID");
        modelo->setHeaderData(1, Qt::Horizontal, "Título");
        modelo->setHeaderData(2, Qt::Horizontal, "Duración");

        // 4. Conectamos el modelo a la vista (asegurate de que el nombre "tablaCanciones" coincida con tu diseño)
        ui->tablaCanciones->setModel(modelo);

        // 5. (La Magia) Ocultamos las columnas que no nos interesan
        // Según tu diagrama, la columna 3 es 'id_album' y la 4 es 'ruta_archivo_mp3'
        ui->tablaCanciones->hideColumn(3);
        ui->tablaCanciones->hideColumn(4);

        if (modelo->lastError().isValid())
        {
            qDebug() << "Error en la consulta SQL de la interfaz:" << modelo->lastError().text();
        }
        else
        {
            // 3. Vinculamos el modelo con tu componente visual de la tabla (tableWidget)
            ui->tablaCanciones->setModel(modelo);
        }

        // 4. Cerramos la conexión una vez cargados los datos
        bd.desconectar();
    }
    else
    {
        QMessageBox::critical(this, "Error de Base de Datos", "No se pudo conectar a MySQL para sincronizar el catálogo.");
    }
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_btnProbar_clicked()
{
    Conexion bd;
    if (bd.conectar()) {
        QMessageBox::information(this, "Éxito", "¡Conectado a la base de datos spotcloud perfectamente, pa!");
        bd.desconectar();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo conectar a MySQL. Revisá XAMPP.");
    }
}

void VentanaPrincipal::on_tablaCanciones_doubleClicked(const QModelIndex &index)
{
    // Capturamos la fila seleccionada
    int fila = index.row();

    // El modelo contiene todos los datos de la consulta.
    // Usamos .sibling() para movernos a la columna que queremos de esa misma fila.
    QAbstractItemModel *modelo = ui->tablaCanciones->model();

    // Columna 0 = ID de la canción
    int idCancion = modelo->data(modelo->index(fila, 0)).toInt();

    // Columna 1 = Título de la canción
    QString tituloCancion = modelo->data(modelo->index(fila, 1)).toString();

    // Por ahora, tiramos un mensaje flotante para comprobar que lee perfecto el clic
    QMessageBox::information(this, "Reproduciendo", "Seleccionaste la canción: " + tituloCancion + " (ID: " + QString::number(idCancion) + ")");

    // TODO: Acá es donde más adelante llamaremos al reproductor de audio pasando el id o la url
}