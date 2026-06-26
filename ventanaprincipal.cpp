#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "../../include/database/conexion.h"
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QPropertyAnimation>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    // Intentamos conectar usando el miembro de la clase 'bd'
    if (bd.conectar()) {
        qDebug() << "Conexión exitosa. Cargando grilla de canciones...";

        // Creamos el modelo usando la conexión abierta de 'bd'
        QSqlTableModel *modelo = new QSqlTableModel(this, bd.getDB());

        modelo->setTable("canciones");
        modelo->select(); // Cargamos los datos

        // Configuramos los encabezados
        modelo->setHeaderData(0, Qt::Horizontal, "ID");
        modelo->setHeaderData(1, Qt::Horizontal, "Título");
        modelo->setHeaderData(2, Qt::Horizontal, "Duración");

        // Asignamos el modelo a la tabla
        ui->tablaCanciones->setModel(modelo);

        // Ocultamos columnas extras
        ui->tablaCanciones->hideColumn(3);
        ui->tablaCanciones->hideColumn(4);

        if (modelo->lastError().isValid()) {
            qDebug() << "Error SQL:" << modelo->lastError().text();
        }
    } else {
        QMessageBox::critical(this, "Error", "No se pudo conectar a MySQL. Revisá la configuración.");
    }
}

VentanaPrincipal::~VentanaPrincipal()
{
    // Al cerrar la ventana, se destruye el objeto 'bd' y se desconecta automáticamente
    delete ui;
}

void VentanaPrincipal::on_btnProbar_clicked()
{
    if (bd.conectar()) {
        QMessageBox::information(this, "Éxito", "¡Conectado a SpotCloud perfectamente!");
    } else {
        QMessageBox::critical(this, "Error", "No se pudo conectar a MySQL.");
    }
}

void VentanaPrincipal::on_tablaCanciones_doubleClicked(const QModelIndex &index)
{
    // 1. Datos
    int fila = index.row();
    QAbstractItemModel *modelo = ui->tablaCanciones->model();
    QString titulo = modelo->data(modelo->index(fila, 1)).toString();

    // 2. Actualizar texto
    ui->lblNombreCancion->setText("Reproduciendo: " + titulo);

    // 3. Preparar el Frame para la animación
    // Si no es visible, lo posicionamos fuera de la vista (debajo) para que "suba"
    if (!ui->frameReproductor->isVisible()) {
        ui->frameReproductor->setGeometry(0, this->height(), this->width(), 100);
        ui->frameReproductor->setVisible(true);
    }

    // 4. Crear la animación
    QPropertyAnimation *animacion = new QPropertyAnimation(ui->frameReproductor, "geometry");
    animacion->setDuration(400); // 400ms para que sea suave
    animacion->setStartValue(ui->frameReproductor->geometry());
    // Posición final: parte inferior de la ventana
    animacion->setEndValue(QRect(0, this->height() - 100, this->width(), 100));
    animacion->setEasingCurve(QEasingCurve::OutCubic); // Curva estética

    animacion->start(QAbstractAnimation::DeleteWhenStopped);
}