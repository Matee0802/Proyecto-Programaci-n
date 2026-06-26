#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "database/Conexion.h"
namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = nullptr);
    ~VentanaPrincipal();

private:
    Ui::VentanaPrincipal *ui;
    Conexion bd;

    // --- AGREGÁ ESTO ACÁ ABAJO ---
private slots:
    void on_btnProbar_clicked();

    // Agregá esta línea acá abajo:
    void on_tablaCanciones_doubleClicked(const QModelIndex &index);
};

#endif // VENTANAPRINCIPAL_H