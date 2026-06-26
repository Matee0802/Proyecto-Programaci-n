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
    // 1. Pintar el fondo de toda la ventana de oscuro
    this->setStyleSheet("QMainWindow { background-color: #121212; }");

    // 2. Obligar a las columnas a estirarse y ocupar todo el ancho
    ui->tablaCanciones->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 3. Ocultar los números de fila de la izquierda (1, 2, 3, 4...)
    ui->tablaCanciones->verticalHeader()->setVisible(false);

    // 4. Quitar las líneas divisorias (grilla)
    ui->tablaCanciones->setShowGrid(false);

    // 5. Aplicar el diseño "SpotCloud" a la tabla
    ui->tablaCanciones->setStyleSheet(
        "QTableView { background-color: #121212; color: #b3b3b3; border: none; }"
        "QHeaderView::section { background-color: #181818; color: #FFD700; font-weight: bold; border: none; padding: 5px; }"
        "QTableView::item:selected { background-color: #FFD700; color: black; }"
        );
        ui->sliderProgreso->setStyleSheet(
        "QSlider::groove:horizontal { border: none; height: 4px; background: #333; margin: 2px 0; border-radius: 2px; }"
        "QSlider::handle:horizontal { background: #FFD700; width: 12px; height: 12px; border-radius: 6px; margin: -4px 0; }"
        "QSlider::sub-page:horizontal { background: #FFD700; border-radius: 2px; }"
        );
        ui->frameReproductor->setMaximumHeight(0);

    // Inicializar audio
    reproductor = new QMediaPlayer(this);
    salidaAudio = new QAudioOutput(this);

    reproductor->setAudioOutput(salidaAudio);
    salidaAudio->setVolume(0.5);

    // En tu constructor, junto a las otras configuraciones de la tabla:
    ui->tablaCanciones->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 1. Cuando el reproductor avanza, actualiza el slider
    connect(reproductor, &QMediaPlayer::positionChanged, this, [this](qint64 posicion){
        ui->sliderProgreso->setMaximum(reproductor->duration());
        ui->sliderProgreso->setValue(posicion);
    });

    // 2. Cuando el usuario mueve el slider, el reproductor salta a ese tiempo
    connect(ui->sliderProgreso, &QSlider::sliderMoved, this, [this](int posicion){
        reproductor->setPosition(posicion);
    });
    // Esto hace que el slider sea más "suave" al moverlo
    ui->sliderProgreso->setTracking(true);



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
    // 1. Obtener el nombre de la canción
    QAbstractItemModel *modelo = ui->tablaCanciones->model();
    QString nombreCancion = modelo->data(modelo->index(index.row(), 1)).toString();
    ui->lblNombreCancion->setText(nombreCancion);

    // 2. Definir la ruta (USAMOS LA RUTA FIJA PARA PROBAR SI SUENA)
    // Cuando esto funcione, después lo cambiamos a la ruta automática.
    QString ruta = "C:/Users/olive/Desktop/Mateo/Proyecto Programacion/Proyecto-Programaci-n/musica/pray_for_plagues.mp3";

    qDebug() << "Intentando reproducir:" << ruta;

    // 3. Configurar y reproducir
    reproductor->setSource(QUrl::fromLocalFile(ruta));
    reproductor->play();

    // 4. Animación de apertura
    if (ui->frameReproductor->maximumHeight() == 0) {
        ui->frameReproductor->setVisible(true);
        QPropertyAnimation *animacion = new QPropertyAnimation(ui->frameReproductor, "maximumHeight");
        animacion->setDuration(350);
        animacion->setStartValue(0);
        animacion->setEndValue(80);
        animacion->setEasingCurve(QEasingCurve::OutCubic);
        animacion->start(QPropertyAnimation::DeleteWhenStopped);
    }
}

void VentanaPrincipal::actualizarProgreso(qint64 posicion)
{
    // El slider debe tener el rango de la duración total de la canción
    ui->sliderProgreso->setMaximum(reproductor->duration());
    ui->sliderProgreso->setValue(posicion);

    // Opcional: mostrar tiempo en labels (ej: lblTiempoActual y lblTiempoTotal)
    // ui->lblTiempoActual->setText(formatearTiempo(posicion));
}

void VentanaPrincipal::cambiarPosicion(int posicion)
{
    reproductor->setPosition(posicion);
}