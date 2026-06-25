#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

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

    // --- AGREGÁ ESTO ACÁ ABAJO ---
private slots:
    void on_btnProbar_clicked();
};

#endif // VENTANAPRINCIPAL_H