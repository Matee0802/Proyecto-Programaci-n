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
    // Agregá esta línea acá abajo:
    void on_tablaCanciones_doubleClicked(const QModelIndex &index);
    void cambiarPosicion(int posicion);    // Permite al usuario mover la barra
    void actualizarDuracionMaxima(qint64 duracion);
    void actualizarEstadoReproduccion(QMediaPlayer::PlaybackState estado); // Para detectar cambios
    void on_btnPausar_clicked();
};

#endif // VENTANAPRINCIPAL_H