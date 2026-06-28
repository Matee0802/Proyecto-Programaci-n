#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "../../include/database/conexion.h"
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QPropertyAnimation>
#include <QFontDatabase>
#include <QRandomGenerator>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    // --- CARGA DE FUENTE MATERIAL ICONS ---
    int fontId = QFontDatabase::addApplicationFont(":/recursos/fonts/MaterialSymbolsOutlined.ttf");

    if (fontId != -1) {
        QStringList familias = QFontDatabase::applicationFontFamilies(fontId);
        QFont materialIcons(familias.at(0));
        materialIcons.setPointSize(20);

        ui->btnShuffle->setFont(materialIcons);
        ui->btnPrev->setFont(materialIcons);
        ui->btnPlayPausa->setFont(materialIcons);
        ui->btnNext->setFont(materialIcons);
        ui->btnRepeat->setFont(materialIcons);
        ui->lblIconoVol->setFont(materialIcons);
    } else {
        qDebug() << "Error: No se pudo cargar la fuente.";
    }

    ui->widget_Controles->layout()->setContentsMargins(0, 0, 0, 5);
    ui->widget_Controles->layout()->setSpacing(0);

    // --- CONFIGURACIÓN VISUAL ---
    this->setStyleSheet("QMainWindow { background-color: #121212; }");
    ui->tablaCanciones->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaCanciones->verticalHeader()->setVisible(false);
    ui->tablaCanciones->setShowGrid(false);
    ui->tablaCanciones->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
    ui->sliderVolumen->setStyleSheet(
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
    ui->sliderVolumen->setRange(0, 100);
    ui->sliderVolumen->setValue(50);
    salidaAudio->setVolume(0.5);
    ui->lblIconoVol->setText("volume_up");

    // --- CONEXIONES ---
    connect(reproductor, &QMediaPlayer::positionChanged, this, [this](qint64 posicion){
        ui->sliderProgreso->setMaximum(reproductor->duration());
        ui->sliderProgreso->setValue(posicion);
    });

    connect(ui->sliderProgreso, &QSlider::sliderMoved, this, &VentanaPrincipal::cambiarPosicion);

    if (bd.conectar()) {
        modelo = new QSqlQueryModel(this);

        modelo->setQuery(
            "SELECT "
            "c.id_cancion, "
            "c.titulo, "
            "c.duracion, "
            "COALESCE(ar.nombre, 'Artista desconocido') AS artista, "
            "c.ruta_archivo_mp3 "
            "FROM canciones c "
            "LEFT JOIN albumes al ON c.id_album = al.id_album "
            "LEFT JOIN artistas ar ON al.id_artista = ar.id_artista",
            bd.getDB()
            );

        if (modelo->lastError().isValid()) {
            qDebug() << "Error en consulta:" << modelo->lastError().text();
            QMessageBox::critical(this, "Error", modelo->lastError().text());
        }

        modelo->setHeaderData(0, Qt::Horizontal, "ID");
        modelo->setHeaderData(1, Qt::Horizontal, "Título");
        modelo->setHeaderData(2, Qt::Horizontal, "Duración");

        ui->tablaCanciones->setModel(modelo);

        ui->tablaCanciones->hideColumn(3);
        ui->tablaCanciones->hideColumn(4);
    }
    modelo->setHeaderData(0, Qt::Horizontal, "ID");
    modelo->setHeaderData(1, Qt::Horizontal, "Título");
    modelo->setHeaderData(2, Qt::Horizontal, "Duración");

    ui->tablaCanciones->setModel(modelo);

    ui->tablaCanciones->hideColumn(3);
    ui->tablaCanciones->hideColumn(4);

    connect(ui->sliderVolumen, &QSlider::valueChanged, this, [this](int val) {
        salidaAudio->setVolume(static_cast<float>(val) / 100.0f);

        if (val == 0) {
            ui->lblIconoVol->setText("volume_off");
        } else if (val < 50) {
            ui->lblIconoVol->setText("volume_down");
        } else {
            ui->lblIconoVol->setText("volume_up");
        }
    });

    connect(ui->btnPlayPausa, &QPushButton::clicked, this, [this]() {
        if (reproductor->playbackState() == QMediaPlayer::PlayingState) reproductor->pause();
        else reproductor->play();
    });

    connect(reproductor, &QMediaPlayer::playbackStateChanged, this, &VentanaPrincipal::actualizarEstadoReproduccion);

    connect(reproductor, &QMediaPlayer::mediaStatusChanged, this,
            [this](QMediaPlayer::MediaStatus estado) {
                if (estado == QMediaPlayer::EndOfMedia) {
                    manejarFinCancion();
                }
            });
    ui->stackedWidget->setCurrentWidget(ui->paginaInicio);

    connect(ui->btnInicio, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaInicio);
    });

    connect(ui->btnExplorar, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaExplorar);
    });

    connect(ui->btnBuscar, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaBuscar);
    });
}

// --- TUS FUNCIONES EXISTENTES ---
void VentanaPrincipal::on_tablaCanciones_doubleClicked(const QModelIndex &index)
{
    cargarYReproducir(index.row()); // Solo pasamos la fila

    // Mantenemos tu animación intacta
    if (ui->frameReproductor->maximumHeight() == 0) {
        QPropertyAnimation *animacion = new QPropertyAnimation(ui->frameReproductor, "maximumHeight");
        animacion->setDuration(350);
        animacion->setStartValue(0);
        animacion->setEndValue(80);
        animacion->start(QPropertyAnimation::DeleteWhenStopped);
    }
}

void VentanaPrincipal::cambiarPosicion(int posicion) {
    if (ui->sliderProgreso->isSliderDown()) reproductor->setPosition(posicion);
}



void VentanaPrincipal::actualizarEstadoReproduccion(QMediaPlayer::PlaybackState estado) {
    ui->btnPlayPausa->setText(estado == QMediaPlayer::PlayingState ? "pause" : "play_arrow");
}


void VentanaPrincipal::actualizarDuracionMaxima(qint64 duracion)
{
    ui->sliderProgreso->setRange(0, static_cast<int>(duracion));
}

void VentanaPrincipal::on_btnNext_clicked()
{
    if (!modelo || modelo->rowCount() == 0) return;

    int siguienteFila;

    if (modoAleatorio && modelo->rowCount() > 1) {
        do {
            siguienteFila = QRandomGenerator::global()->bounded(modelo->rowCount());
        } while (siguienteFila == filaActual);
    } else {
        siguienteFila = (filaActual + 1) % modelo->rowCount();
    }

    cargarYReproducir(siguienteFila);
}

void VentanaPrincipal::on_btnPrev_clicked() {
    QAbstractItemModel *modelo = ui->tablaCanciones->model();
    if (!modelo || modelo->rowCount() == 0) return;

    int anteriorFila = (filaActual <= 0) ? modelo->rowCount() - 1 : filaActual - 1;
    cargarYReproducir(anteriorFila);
}

void VentanaPrincipal::cargarYReproducir(int fila) {
    // 1. Validaciones básicas
    QAbstractItemModel *modelo = ui->tablaCanciones->model();
    if (!modelo || fila < 0 || fila >= modelo->rowCount()) return;

    // 2. Si es la misma fila, no hacemos nada
    if (fila == filaActual && reproductor->playbackState() == QMediaPlayer::PlayingState) return;

    filaActual = fila;

    // 3. Obtenemos datos
    QString urlMusica = modelo->data(modelo->index(fila, 4)).toString();
    QString nombreCancion = modelo->data(modelo->index(fila, 1)).toString();
    QString artista = modelo->data(modelo->index(fila, 3)).toString();

    reproductor->stop();
    reproductor->setSource(QUrl(urlMusica));

    ui->lblNombreCancion->setText(nombreCancion);
    ui->label_Artista->setText(artista);

    reproductor->play();
    ui->frameReproductor->setVisible(true);

    // 6. Actualizamos la selección de la tabla una sola vez
    ui->tablaCanciones->blockSignals(true);
    ui->tablaCanciones->setCurrentIndex(modelo->index(fila, 0));
    ui->tablaCanciones->blockSignals(false);
}

void VentanaPrincipal::on_btnShuffle_clicked()
{
    modoAleatorio = !modoAleatorio;

    if (modoAleatorio) {
        ui->btnShuffle->setStyleSheet("background: transparent; color: #FFD700; border: none;");
    } else {
        ui->btnShuffle->setStyleSheet("background: transparent; color: #b3b3b3; border: none;");
    }
}
void VentanaPrincipal::on_btnRepeat_clicked()
{
    modoRepeticion++;

    if (modoRepeticion > 2) {
        modoRepeticion = 0;
    }

    if (modoRepeticion == 0) {
        ui->btnRepeat->setText("repeat");
        ui->btnRepeat->setStyleSheet("background: transparent; color: #b3b3b3; border: none;");
    } else if (modoRepeticion == 1) {
        ui->btnRepeat->setText("repeat");
        ui->btnRepeat->setStyleSheet("background: transparent; color: #FFD700; border: none;");
    } else {
        ui->btnRepeat->setText("repeat_one");
        ui->btnRepeat->setStyleSheet("background: transparent; color: #FFD700; border: none;");
    }
}

void VentanaPrincipal::manejarFinCancion()
{
    if (!modelo || modelo->rowCount() == 0) return;

    if (modoRepeticion == 2) {
        cargarYReproducir(filaActual);
        return;
    }

    if (filaActual == modelo->rowCount() - 1 && modoRepeticion == 0 && !modoAleatorio) {
        reproductor->stop();
        ui->btnPlayPausa->setText("play_arrow");
        return;
    }

    on_btnNext_clicked();
}

VentanaPrincipal::~VentanaPrincipal() { delete ui; }