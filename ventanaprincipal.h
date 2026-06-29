#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "database/Conexion.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QSqlQueryModel>
#include <QLabel>
#include <QPixmap>
#include <QIcon>

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
    QSqlQueryModel *modelo; // El modelo para acceder a la BD
    int filaActual = 0;
    bool estaCargando = false;

    bool modoAleatorio = false;
    int modoRepeticion = 0;
    // 0 = sin repetir
    // 1 = repetir lista
    // 2 = repetir una canción
    void cargarCancion(int fila);
    void reproducirSiguiente();
    void reproducirAnterior();
    void manejarFinCancion();
    QNetworkAccessManager *networkManager;
    QSqlQueryModel *modeloBusqueda;
    void cargarAlbumesInicio();
    QWidget *crearCardAlbum(int idAlbum, const QString &titulo, const QString &artista, const QString &rutaPortada);
    void abrirAlbum(int idAlbum);
    void buscarContenido(const QString &texto);
private slots:
    // Agregá esta línea acá abajo:
    void cambiarPosicion(int posicion);
    void on_tablaCanciones_doubleClicked(const QModelIndex &index);
    void actualizarEstadoReproduccion(QMediaPlayer::PlaybackState estado); // Para detectar cambios
    void actualizarDuracionMaxima(qint64 duracion);
    void on_btnNext_clicked();
    void on_btnPrev_clicked();
    void cargarYReproducir(int fila);
    void on_btnShuffle_clicked();
    void on_btnRepeat_clicked();
    void on_tablaBusqueda_doubleClicked(const QModelIndex &index);
};

#endif // VENTANAPRINCIPAL_H