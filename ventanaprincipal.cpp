#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "../../include/database/conexion.h"
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QPropertyAnimation>
#include <QFontDatabase>


VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    // --- CONFIGURACIÓN VISUAL ---
    this->setStyleSheet("QMainWindow { background-color: #121212; }");
    ui->tablaCanciones->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaCanciones->verticalHeader()->setVisible(false);
    ui->tablaCanciones->setShowGrid(false);
    ui->tablaCanciones->setEditTriggers(QAbstractItemView::NoEditTriggers); // Bloquear edición

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

    ui->sliderProgreso->setTracking(true);
    ui->frameReproductor->setMaximumHeight(0);

    // --- INICIALIZACIÓN DE AUDIO ---
    reproductor = new QMediaPlayer(this);
    salidaAudio = new QAudioOutput(this);
    reproductor->setAudioOutput(salidaAudio);
    salidaAudio->setVolume(0.5);

    // --- CONEXIONES DEL REPRODUCTOR ---
    connect(reproductor, &QMediaPlayer::positionChanged, this, [this](qint64 posicion){
        ui->sliderProgreso->setMaximum(reproductor->duration());
        ui->sliderProgreso->setValue(posicion);
    });

    connect(ui->sliderProgreso, &QSlider::sliderMoved, this, [this](int posicion){
        reproductor->setPosition(posicion);
    });

    // --- CONEXIÓN A BASE DE DATOS ---
    if (bd.conectar()) {
        QSqlTableModel *modelo = new QSqlTableModel(this, bd.getDB());
        modelo->setTable("canciones");
        modelo->select();

        modelo->setHeaderData(0, Qt::Horizontal, "ID");
        modelo->setHeaderData(1, Qt::Horizontal, "Título");
        modelo->setHeaderData(2, Qt::Horizontal, "Duración");

        ui->tablaCanciones->setModel(modelo);
        ui->tablaCanciones->hideColumn(3); // Columnas extra ocultas
        ui->tablaCanciones->hideColumn(4);
    } else {
        QMessageBox::critical(this, "Error", "No se pudo conectar a MySQL.");
    }
    // 1. Conectamos el movimiento normal (arrastrar)
    connect(ui->sliderProgreso, &QSlider::sliderMoved, this, &VentanaPrincipal::cambiarPosicion);

    // 2. Conectamos el clic directo en la barra
    connect(ui->sliderProgreso, &QSlider::actionTriggered, this, [this](int action) {
        if (action == QAbstractSlider::SliderMove) {
            reproductor->setPosition(ui->sliderProgreso->value());
        }
    });
    // Esto hace que el slider no se quede con el foco del teclado (evita que las flechas lo muevan accidentalmente)
    // La ruta ahora incluye la carpeta que definimos en el qrc
    int fontId = QFontDatabase::addApplicationFont(":/recursos/fonts/MaterialSymbolsOutlined.ttf");

    if (fontId != -1) {
        QStringList familias = QFontDatabase::applicationFontFamilies(fontId);
        QFont materialIcons(familias.at(0));
        materialIcons.setPointSize(24);
        ui->btnPlayPausa->setFont(materialIcons);
    }
    // 1. Conexión de clic
    connect(ui->btnPlayPausa, &QPushButton::clicked, this, [this]() {
        if (reproductor->playbackState() == QMediaPlayer::PlayingState) {
            reproductor->pause();
        } else {
            reproductor->play();
        }
    });

    // 2. Conexión para que el ícono cambie solo cuando la música cambia
    connect(reproductor, &QMediaPlayer::playbackStateChanged, this, &VentanaPrincipal::actualizarEstadoReproduccion);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_tablaCanciones_doubleClicked(const QModelIndex &index)
{
    // 1. Obtener datos de la fila
    QAbstractItemModel *modelo = ui->tablaCanciones->model();
    QString nombreCancion = modelo->data(modelo->index(index.row(), 1)).toString();

    // 2. Obtener URL de la columna 4 (asegurate que sea la columna de tu link)
    QString urlMusica = modelo->data(modelo->index(index.row(), 4)).toString();

    ui->lblNombreCancion->setText(nombreCancion);

    // 3. Reproducir desde la nube
    reproductor->setSource(QUrl(urlMusica));
    reproductor->play();

    // 4. Animación
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

void VentanaPrincipal::actualizarDuracionMaxima(qint64 duracion)
{
    ui->sliderProgreso->setRange(0, static_cast<int>(duracion));
}

void VentanaPrincipal::cambiarPosicion(int posicion)
{
    // Solo saltamos si el usuario realmente está interactuando
    if (ui->sliderProgreso->isSliderDown()) {
        reproductor->setPosition(posicion);
    }
}
void VentanaPrincipal::actualizarEstadoReproduccion(QMediaPlayer::PlaybackState estado)
{
    if (estado == QMediaPlayer::PlayingState) {
        ui->btnPlayPausa->setText("pause"); // Google lo cambia solo
    } else {
        ui->btnPlayPausa->setText("play_arrow");
    }
}

void VentanaPrincipal::on_btnPausar_clicked()
{
    if (!reproductor->source().isEmpty()) {
        if (reproductor->playbackState() == QMediaPlayer::PlayingState) {
            reproductor->pause();
        } else {
            reproductor->play();
        }
    }
}