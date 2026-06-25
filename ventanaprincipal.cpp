#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "database/Conexion.h"
#include <QMessageBox>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

// Ahora sí viene tu botón limpio:
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