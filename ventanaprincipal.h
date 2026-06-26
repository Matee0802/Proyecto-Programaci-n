#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "database/Conexion.h"
#include <QMediaPlayer>
#include <QAudioOutput>
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
    QMediaPlayer *reproductor;
    QAudioOutput *salidaAudio;
    // --- AGREGÁ ESTO ACÁ ABAJO ---
private slots:
    void on_btnProbar_clicked();

    // Agregá esta línea acá abajo:
    void on_tablaCanciones_doubleClicked(const QModelIndex &index);
    void actualizarProgreso(qint64 duracion); // Actualiza la barra mientras suena
    void cambiarPosicion(int posicion);      // Permite al usuario mover la barra
};

#endif // VENTANAPRINCIPAL_H