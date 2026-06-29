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
#include <QNetworkRequest>
#include <QSqlQuery>
#include <QHeaderView>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    networkManager = new QNetworkAccessManager(this);

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

    ui->tablaBusqueda->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaBusqueda->verticalHeader()->setVisible(false);
    ui->tablaBusqueda->setShowGrid(false);
    ui->tablaBusqueda->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablaBusqueda->setStyleSheet(
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

    ui->scrollAlbumes->setStyleSheet("QScrollArea { background: transparent; border: none; }");
    ui->contenedorAlbumes->setStyleSheet("background: transparent;");
    ui->gridAlbumes->setHorizontalSpacing(28);
    ui->gridAlbumes->setVerticalSpacing(30);
    ui->gridAlbumes->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    ui->sliderProgreso->setTracking(true);
    ui->frameReproductor->setMaximumHeight(0);

    reproductor = new QMediaPlayer(this);
    salidaAudio = new QAudioOutput(this);
    reproductor->setAudioOutput(salidaAudio);

    ui->sliderVolumen->setRange(0, 100);
    ui->sliderVolumen->setValue(50);
    salidaAudio->setVolume(0.5);
    ui->lblIconoVol->setText("volume_up");

    connect(reproductor, &QMediaPlayer::positionChanged, this, [this](qint64 posicion) {
        ui->sliderProgreso->setMaximum(reproductor->duration());
        ui->sliderProgreso->setValue(posicion);
    });

    connect(ui->sliderProgreso, &QSlider::sliderMoved, this, &VentanaPrincipal::cambiarPosicion);

    modelo = new QSqlQueryModel(this);
    modeloBusqueda = new QSqlQueryModel(this);
    ui->tablaBusqueda->setModel(modeloBusqueda);

    if (bd.conectar()) {
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

        modelo->setHeaderData(1, Qt::Horizontal, "Titulo");
        modelo->setHeaderData(2, Qt::Horizontal, "Duracion");

        ui->tablaCanciones->setModel(modelo);
        ui->tablaCanciones->hideColumn(0);
        ui->tablaCanciones->hideColumn(3);
        ui->tablaCanciones->hideColumn(4);

        cargarAlbumesInicio();
    }

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
        if (reproductor->playbackState() == QMediaPlayer::PlayingState) {
            reproductor->pause();
        } else {
            reproductor->play();
        }
    });

    connect(reproductor, &QMediaPlayer::playbackStateChanged,
            this, &VentanaPrincipal::actualizarEstadoReproduccion);

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

    connect(ui->btnBuscar, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaBuscar);
        ui->txtBuscar->setFocus();
    });

    connect(ui->txtBuscar, &QLineEdit::textChanged,
            this, &VentanaPrincipal::buscarContenido);
}

void VentanaPrincipal::on_tablaCanciones_doubleClicked(const QModelIndex &index)
{
    cargarYReproducir(index.row());

    if (ui->frameReproductor->maximumHeight() == 0) {
        QPropertyAnimation *animacion = new QPropertyAnimation(ui->frameReproductor, "maximumHeight");
        animacion->setDuration(350);
        animacion->setStartValue(0);
        animacion->setEndValue(80);
        animacion->start(QPropertyAnimation::DeleteWhenStopped);
    }
}

void VentanaPrincipal::cambiarPosicion(int posicion)
{
    if (ui->sliderProgreso->isSliderDown()) {
        reproductor->setPosition(posicion);
    }
}

void VentanaPrincipal::actualizarEstadoReproduccion(QMediaPlayer::PlaybackState estado)
{
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

void VentanaPrincipal::on_btnPrev_clicked()
{
    QAbstractItemModel *modeloTabla = ui->tablaCanciones->model();
    if (!modeloTabla || modeloTabla->rowCount() == 0) return;

    int anteriorFila = (filaActual <= 0) ? modeloTabla->rowCount() - 1 : filaActual - 1;
    cargarYReproducir(anteriorFila);
}

void VentanaPrincipal::cargarYReproducir(int fila)
{
    QAbstractItemModel *modeloTabla = ui->tablaCanciones->model();
    if (!modeloTabla || fila < 0 || fila >= modeloTabla->rowCount()) return;

    if (fila == filaActual && reproductor->playbackState() == QMediaPlayer::PlayingState) return;

    filaActual = fila;

    QString urlMusica = modeloTabla->data(modeloTabla->index(fila, 4)).toString();
    QString nombreCancion = modeloTabla->data(modeloTabla->index(fila, 1)).toString();
    QString artista = modeloTabla->data(modeloTabla->index(fila, 3)).toString();

    reproductor->stop();
    reproductor->setSource(QUrl(urlMusica));

    ui->lblNombreCancion->setText(nombreCancion);
    ui->label_Artista->setText(artista);

    reproductor->play();
    ui->frameReproductor->setVisible(true);

    ui->tablaCanciones->blockSignals(true);
    ui->tablaCanciones->setCurrentIndex(modeloTabla->index(fila, 1));
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

void VentanaPrincipal::cargarAlbumesInicio()
{
    QLayoutItem *item;

    while ((item = ui->gridAlbumes->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }

    QSqlQuery query(bd.getDB());

    query.prepare(
        "SELECT "
        "al.id_album, "
        "al.titulo, "
        "COALESCE(ar.nombre, 'Artista desconocido'), "
        "al.ruta_portada "
        "FROM albumes al "
        "LEFT JOIN artistas ar ON al.id_artista = ar.id_artista"
        );

    if (!query.exec()) {
        qDebug() << "Error cargando albumes:" << query.lastError().text();
        return;
    }

    int fila = 0;
    int columna = 0;
    const int columnasPorFila = 6;

    while (query.next()) {
        int idAlbum = query.value(0).toInt();
        QString titulo = query.value(1).toString();
        QString artista = query.value(2).toString();
        QString rutaPortada = query.value(3).toString();

        QWidget *card = crearCardAlbum(idAlbum, titulo, artista, rutaPortada);
        ui->gridAlbumes->addWidget(card, fila, columna, Qt::AlignLeft | Qt::AlignTop);

        columna++;

        if (columna >= columnasPorFila) {
            columna = 0;
            fila++;
        }
    }

    ui->gridAlbumes->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

QWidget *VentanaPrincipal::crearCardAlbum(int idAlbum, const QString &titulo, const QString &artista, const QString &rutaPortada)
{
    QWidget *card = new QWidget(this);
    card->setFixedSize(190, 252);
    card->setCursor(Qt::PointingHandCursor);
    card->setStyleSheet(
        "QWidget { background-color: transparent; border-radius: 6px; }"
        "QWidget:hover { background-color: #181818; }"
        );

    QVBoxLayout *layout = new QVBoxLayout(card);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(8);

    QPushButton *btnPortada = new QPushButton(card);
    btnPortada->setFixedSize(170, 170);
    btnPortada->setCursor(Qt::PointingHandCursor);
    btnPortada->setText("");
    btnPortada->setStyleSheet(
        "QPushButton { background-color: #282828; border: none; border-radius: 4px; color: #b3b3b3; }"
        "QPushButton:hover { background-color: #333333; }"
        );

    auto aplicarPortada = [btnPortada](const QPixmap &portada) {
        if (!portada.isNull()) {
            btnPortada->setText("");
            btnPortada->setIcon(QIcon(portada.scaled(
                170,
                170,
                Qt::KeepAspectRatioByExpanding,
                Qt::SmoothTransformation
                )));
            btnPortada->setIconSize(QSize(170, 170));
        } else {
            btnPortada->setText("album");
        }
    };

    if (rutaPortada.startsWith("http")) {
        QNetworkReply *reply = networkManager->get(QNetworkRequest(QUrl(rutaPortada)));

        connect(reply, &QNetworkReply::finished, this, [reply, aplicarPortada]() {
            QByteArray data = reply->readAll();

            QPixmap portada;
            portada.loadFromData(data);

            aplicarPortada(portada);
            reply->deleteLater();
        });
    } else {
        aplicarPortada(QPixmap(rutaPortada));
    }

    QLabel *lblTitulo = new QLabel(titulo, card);
    lblTitulo->setStyleSheet("color: white; font-weight: bold; border: none; background: transparent;");
    lblTitulo->setWordWrap(true);
    lblTitulo->setFixedHeight(30);

    QLabel *lblArtista = new QLabel(artista, card);
    lblArtista->setStyleSheet("color: #b3b3b3; font-size: 11px; border: none; background: transparent;");
    lblArtista->setWordWrap(true);
    lblArtista->setFixedHeight(10);

    layout->addWidget(btnPortada);
    layout->addWidget(lblTitulo);
    layout->addWidget(lblArtista);
    layout->addStretch();

    connect(btnPortada, &QPushButton::clicked, this, [this, idAlbum]() {
        abrirAlbum(idAlbum);
    });

    return card;
}

void VentanaPrincipal::abrirAlbum(int idAlbum)
{
    modelo->setQuery(
        QString(
            "SELECT "
            "c.id_cancion, "
            "c.titulo, "
            "c.duracion, "
            "COALESCE(ar.nombre, 'Artista desconocido') AS artista, "
            "c.ruta_archivo_mp3 "
            "FROM canciones c "
            "LEFT JOIN albumes al ON c.id_album = al.id_album "
            "LEFT JOIN artistas ar ON al.id_artista = ar.id_artista "
            "WHERE c.id_album = %1"
            ).arg(idAlbum),
        bd.getDB()
        );

    if (modelo->lastError().isValid()) {
        qDebug() << "Error abriendo album:" << modelo->lastError().text();
        return;
    }

    ui->tablaCanciones->setModel(modelo);
    ui->tablaCanciones->hideColumn(0);
    ui->tablaCanciones->hideColumn(3);
    ui->tablaCanciones->hideColumn(4);

    ui->stackedWidget->setCurrentWidget(ui->paginaAlbum);
}

void VentanaPrincipal::buscarContenido(const QString &texto)
{
    QString filtro = texto.trimmed();

    if (filtro.isEmpty()) {
        modeloBusqueda->clear();
        return;
    }

    QString busqueda = "%" + filtro + "%";

    QSqlQuery query(bd.getDB());

    query.prepare(
        "SELECT "
        "c.id_cancion, "
        "c.titulo AS Cancion, "
        "COALESCE(ar.nombre, 'Artista desconocido') AS Artista, "
        "COALESCE(al.titulo, 'Sin album') AS Album, "
        "COALESCE(ar.genero, 'Sin genero') AS Genero, "
        "c.duracion AS Duracion, "
        "c.ruta_archivo_mp3 "
        "FROM canciones c "
        "LEFT JOIN albumes al ON c.id_album = al.id_album "
        "LEFT JOIN artistas ar ON al.id_artista = ar.id_artista "
        "WHERE c.titulo LIKE ? "
        "OR ar.nombre LIKE ? "
        "OR ar.genero LIKE ? "
        "OR al.titulo LIKE ?"
        );

    query.addBindValue(busqueda);
    query.addBindValue(busqueda);
    query.addBindValue(busqueda);
    query.addBindValue(busqueda);

    if (!query.exec()) {
        qDebug() << "Error buscando:" << query.lastError().text();
        return;
    }

    modeloBusqueda->setQuery(std::move(query));

    ui->tablaBusqueda->hideColumn(0);
    ui->tablaBusqueda->hideColumn(6);
    ui->tablaBusqueda->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaBusqueda->verticalHeader()->setVisible(false);
    ui->tablaBusqueda->setShowGrid(false);
}

void VentanaPrincipal::on_tablaBusqueda_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid() || !modeloBusqueda) return;

    int fila = index.row();

    QString nombreCancion = modeloBusqueda->data(modeloBusqueda->index(fila, 1)).toString();
    QString artista = modeloBusqueda->data(modeloBusqueda->index(fila, 2)).toString();
    QString urlMusica = modeloBusqueda->data(modeloBusqueda->index(fila, 6)).toString();

    if (urlMusica.isEmpty()) return;

    reproductor->stop();
    reproductor->setSource(QUrl(urlMusica));

    ui->lblNombreCancion->setText(nombreCancion);
    ui->label_Artista->setText(artista);

    reproductor->play();
    ui->frameReproductor->setVisible(true);

    if (ui->frameReproductor->maximumHeight() == 0) {
        QPropertyAnimation *animacion = new QPropertyAnimation(ui->frameReproductor, "maximumHeight");
        animacion->setDuration(350);
        animacion->setStartValue(0);
        animacion->setEndValue(80);
        animacion->start(QPropertyAnimation::DeleteWhenStopped);
    }
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}