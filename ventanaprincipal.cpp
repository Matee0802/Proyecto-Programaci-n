#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "dao/SpotCloudDAO.h"
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
#include <QDateTime>
#include <QMimeDatabase>
#include <QFileInfo>
#include <QFileDialog>
#include <QNetworkInterface>
#include <QResizeEvent>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QTabBar>
#include <QTableWidget>
#include <QMenu>

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
        dao = new SpotCloudDAO(bd.getDB());
        delete modelo;
        modelo = dao->modeloCanciones(this);

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
    // abrir paginainicio
    connect(ui->btnInicio, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaInicio);
    });
    // abrir paginabuscar
    connect(ui->btnBuscar, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaBuscar);
        ui->txtBuscar->setFocus();
    });
    // abrir paginacargar
    connect(ui->btnAdmin, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->paginaAdmin);
        cargarCombosAdmin();
    });

    // AGREGAR: botones del panel Admin
    connect(ui->btnGuardarArtista, &QPushButton::clicked, this, &VentanaPrincipal::guardarArtista);
    connect(ui->btnGuardarAlbum, &QPushButton::clicked, this, &VentanaPrincipal::guardarAlbum);
    connect(ui->btnGuardarCancion, &QPushButton::clicked, this, &VentanaPrincipal::guardarCancion);

    // seleccionar archivos locales ---
    connect(ui->btnSeleccionarMp3Local, &QPushButton::clicked, this, &VentanaPrincipal::seleccionarMp3Local);
    connect(ui->btnSeleccionarPortadaLocal, &QPushButton::clicked, this, &VentanaPrincipal::seleccionarPortadaLocal);

    //  eliminar contenido ---
    connect(ui->comboTipoEliminar, &QComboBox::currentTextChanged, this, &VentanaPrincipal::cargarElementosEliminar);
    connect(ui->txtFiltroEliminar, &QLineEdit::textChanged, this, &VentanaPrincipal::cargarElementosEliminar);
    connect(ui->btnEliminarContenido, &QPushButton::clicked, this, &VentanaPrincipal::eliminarContenido);
    cargarComboEliminar();
    connect(ui->txtBuscar, &QLineEdit::textChanged,
            this, &VentanaPrincipal::buscarContenido);

    // La administración se muestra de a un paso para reducir la sobrecarga visual.
    configurarPasoAdmin();
    auto *btnFila = new QPushButton("Fila", this);
    btnFila->setToolTip("Ver fila de reproducción");
    ui->horizontalLayout_Volumen->insertWidget(0, btnFila);
    connect(btnFila, &QPushButton::clicked, this, &VentanaPrincipal::mostrarFila);
    btnPerfil = ui->btnPerfil;
    btnPerfil->setCursor(Qt::PointingHandCursor);
    btnPerfil->setStyleSheet("QPushButton { background:transparent; color:#d9d9d9; border:none; padding:7px 10px; } QPushButton:hover { color:#ffd700; }");
    connect(btnPerfil, &QPushButton::clicked, this, [this] { if (idUsuarioActual == 0) requiereSesion(); });
    connect(btnPerfil, &QPushButton::clicked, this, [this] {
        if (idUsuarioActual == 0) return;
        QMenu menu(this);
        QAction *salir = menu.addAction("Cerrar sesión");
        if (menu.exec(btnPerfil->mapToGlobal(QPoint(0, btnPerfil->height()))) == salir) {
            idUsuarioActual = 0;
            btnPerfil->setText("Iniciar sesión");
        }
    });

    auto *agregarAlbum = new QPushButton("+  Agregar canción seleccionada a la fila", ui->paginaAlbum);
    agregarAlbum->setStyleSheet("QPushButton { background:#242424; color:#ffd700; border:1px solid #4a4a4a; border-radius:6px; padding:8px; } QPushButton:hover { border-color:#ffd700; }");
    ui->verticalLayout_Album->insertWidget(2, agregarAlbum, 0, Qt::AlignLeft);
    connect(agregarAlbum, &QPushButton::clicked, this, [this] { agregarFila(ui->tablaCanciones->currentIndex().row()); });
    auto *agregarBusqueda = new QPushButton("+  Agregar canción seleccionada a la fila", ui->paginaBuscar);
    agregarBusqueda->setStyleSheet(agregarAlbum->styleSheet());
    ui->verticalLayout_Buscar->insertWidget(2, agregarBusqueda, 0, Qt::AlignLeft);
    connect(agregarBusqueda, &QPushButton::clicked, this, [this] { if (!modeloBusqueda) return; const int fila = ui->tablaBusqueda->currentIndex().row(); if (fila < 0) return; const int id = modeloBusqueda->data(modeloBusqueda->index(fila, 0)).toInt(); if (id > 0 && !colaReproduccion.contains(id)) colaReproduccion.append(id); });
}

void VentanaPrincipal::on_tablaCanciones_doubleClicked(const QModelIndex &index)
{
    if (!requiereSesion()) return;
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

    const int idActual = modelo->data(modelo->index(filaActual, 0)).toInt();
    const int posicionEnFila = colaReproduccion.indexOf(idActual);
    if (posicionEnFila >= 0 && posicionEnFila + 1 < colaReproduccion.size()) {
        const int idSiguiente = colaReproduccion.at(posicionEnFila + 1);
        for (int fila = 0; fila < modelo->rowCount(); ++fila) {
            if (modelo->data(modelo->index(fila, 0)).toInt() == idSiguiente) { cargarYReproducir(fila); return; }
        }
    }
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
    if (!requiereSesion()) return;
    QAbstractItemModel *modeloTabla = ui->tablaCanciones->model();
    if (!modeloTabla || fila < 0 || fila >= modeloTabla->rowCount()) return;

    if (fila == filaActual && reproductor->playbackState() == QMediaPlayer::PlayingState) return;

    filaActual = fila;
    agregarFila(fila);

    QString urlMusica = modeloTabla->data(modeloTabla->index(fila, 4)).toString();
    QString nombreCancion = modeloTabla->data(modeloTabla->index(fila, 1)).toString();
    QString artista = modeloTabla->data(modeloTabla->index(fila, 3)).toString();

    reproductor->stop();
    reproductor->setSource(crearUrlAudio(urlMusica));

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

    if (!dao) return;
    const QVector<AlbumResumen> albumes = dao->albumesDisponibles(!hayConexionRed());

    int fila = 0;
    int columna = 0;

    for (const AlbumResumen &album : albumes) {
        int idAlbum = album.id;
        QString titulo = album.titulo;
        QString artista = album.artista;
        QString rutaPortada = album.portada;

        QWidget *card = crearCardAlbum(idAlbum, titulo, artista, rutaPortada);
        ui->gridAlbumes->addWidget(card, fila, columna, Qt::AlignLeft | Qt::AlignTop);

        columna++;

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
    if (!dao) return;
    delete modelo;
    modelo = dao->modeloCanciones(this, idAlbum);

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

    if (!dao) return;
    delete modeloBusqueda;
    modeloBusqueda = dao->modeloBusqueda(this, filtro);
    ui->tablaBusqueda->setModel(modeloBusqueda);

    ui->tablaBusqueda->hideColumn(0);
    ui->tablaBusqueda->hideColumn(6);
    ui->tablaBusqueda->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaBusqueda->verticalHeader()->setVisible(false);
    ui->tablaBusqueda->setShowGrid(false);
}

void VentanaPrincipal::on_tablaBusqueda_doubleClicked(const QModelIndex &index)
{
    if (!requiereSesion()) return;
    if (!index.isValid() || !modeloBusqueda) return;

    int fila = index.row();

    QString nombreCancion = modeloBusqueda->data(modeloBusqueda->index(fila, 1)).toString();
    QString artista = modeloBusqueda->data(modeloBusqueda->index(fila, 2)).toString();
    QString urlMusica = modeloBusqueda->data(modeloBusqueda->index(fila, 6)).toString();

    if (urlMusica.isEmpty()) return;

    reproductor->stop();
    reproductor->setSource(crearUrlAudio(urlMusica));

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

// Recarga artistas y albumes en los combos del admin
void VentanaPrincipal::cargarCombosAdmin()
{
    ui->comboArtistasAlbum->clear();
    ui->comboAlbumCancion->clear();

    if (!dao) return;
    for (const ElementoAdmin &artista : dao->artistas()) ui->comboArtistasAlbum->addItem(artista.nombre, artista.id);
    for (const ElementoAdmin &album : dao->albumes()) ui->comboAlbumCancion->addItem(album.nombre, album.id);
}
// Guardar nuevo artista
void VentanaPrincipal::guardarArtista()
{
    QString nombre = ui->txtNombreArtista->text().trimmed();
    QString bio = ui->txtBioArtista->toPlainText().trimmed();
    QString genero = ui->txtGeneroArtista->text().trimmed();

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre del artista es obligatorio.");
        return;
    }

    if (!dao || !dao->crearArtista(nombre, bio, genero)) {
        QMessageBox::critical(this, "Error", dao ? dao->ultimoError() : "No hay conexión a la base de datos.");
        return;
    }

    QMessageBox::information(this, "Listo", "Artista guardado correctamente.");

    ui->txtNombreArtista->clear();
    ui->txtBioArtista->clear();
    ui->txtGeneroArtista->clear();

    cargarCombosAdmin();
}
// Guardar nuevo album
void VentanaPrincipal::guardarAlbum()
{
    QString titulo = ui->txtTituloAlbum->text().trimmed();
    int anio = ui->spinAnioAlbum->value();
    int idArtista = ui->comboArtistasAlbum->currentData().toInt();
    QString portada = ui->txtPortadaAlbum->text().trimmed();

    if (titulo.isEmpty()) {
        QMessageBox::warning(this, "Error", "El titulo del album es obligatorio.");
        return;
    }

    if (!dao || !dao->crearAlbum(titulo, anio, idArtista, portada)) {
        QMessageBox::critical(this, "Error", dao ? dao->ultimoError() : "No hay conexión a la base de datos.");
        return;
    }

    QMessageBox::information(this, "Listo", "Album guardado correctamente.");

    ui->txtTituloAlbum->clear();
    ui->txtPortadaAlbum->clear();

    cargarCombosAdmin();
    cargarAlbumesInicio();
}

// Guardar nueva cancion
void VentanaPrincipal::guardarCancion()
{
    QString titulo = ui->txtTituloCancion->text().trimmed();
    QString duracion = ui->timeDuracionCancion->time().toString("HH:mm:ss");
    int idAlbum = ui->comboAlbumCancion->currentData().toInt();
    QString mp3 = ui->txtMp3Cancion->text().trimmed();

    if (titulo.isEmpty() || mp3.isEmpty()) {
        QMessageBox::warning(this, "Error", "El titulo y la URL del MP3 son obligatorios.");
        return;
    }

    if (!dao || !dao->crearCancion(titulo, duracion, idAlbum, mp3)) {
        QMessageBox::critical(this, "Error", dao ? dao->ultimoError() : "No hay conexión a la base de datos.");
        return;
    }

    QMessageBox::information(this, "Listo", "Cancion guardada correctamente.");

    ui->txtTituloCancion->clear();
    ui->txtMp3Cancion->clear();

    abrirAlbum(idAlbum);
}

//  permite reproducir URLs de Supabase y archivos locales ---
QUrl VentanaPrincipal::crearUrlAudio(const QString &ruta)
{
    if (ruta.startsWith("http")) {
        return QUrl(ruta);
    }

    return QUrl::fromLocalFile(ruta);
}

//  elegir MP3 local desde la PC ---
void VentanaPrincipal::seleccionarMp3Local()
{
    QString archivo = QFileDialog::getOpenFileName(
        this,
        "Seleccionar cancion",
        "",
        "Audio (*.mp3 *.wav *.ogg)"
        );

    if (!archivo.isEmpty()) {
        ui->txtMp3Cancion->setText(archivo);
    }
}

//  elegir portada local desde la PC ---
void VentanaPrincipal::seleccionarPortadaLocal()
{
    QString archivo = QFileDialog::getOpenFileName(
        this,
        "Seleccionar portada",
        "",
        "Imagenes (*.png *.jpg *.jpeg *.webp)"
        );

    if (!archivo.isEmpty()) {
        ui->txtPortadaAlbum->setText(archivo);
    }
}

// --- opciones de eliminacion ---
void VentanaPrincipal::cargarComboEliminar()
{
    ui->comboTipoEliminar->clear();
    ui->comboTipoEliminar->addItem("Cancion");
    ui->comboTipoEliminar->addItem("Album");
    ui->comboTipoEliminar->addItem("Artista");
    cargarElementosEliminar();
}

void VentanaPrincipal::cargarElementosEliminar()
{
    ui->comboElementoEliminar->clear();

    QString tipo = ui->comboTipoEliminar->currentText();
    QString filtro = ui->txtFiltroEliminar->text().trimmed();
    if (!dao) return;
    for (const ElementoAdmin &elemento : dao->elementos(tipo, filtro)) ui->comboElementoEliminar->addItem(elemento.nombre, elemento.id);
}
void VentanaPrincipal::eliminarContenido()
{
    QString tipo = ui->comboTipoEliminar->currentText();
    int id = ui->comboElementoEliminar->currentData().toInt();

    if (id <= 0) return;

    QMessageBox::StandardButton respuesta = QMessageBox::question(
        this,
        "Confirmar",
        "Seguro que queres eliminar este contenido?"
        );

    if (respuesta != QMessageBox::Yes) return;

    QString motivo;
    if (!dao || !dao->eliminar(tipo, id, &motivo)) {
        QMessageBox::warning(this, "No se puede eliminar", motivo.isEmpty() && dao ? dao->ultimoError() : motivo);
        return;
    }

    QMessageBox::information(this, "Listo", "Contenido eliminado correctamente.");

    cargarElementosEliminar();
    cargarCombosAdmin();
    cargarAlbumesInicio();
}

bool VentanaPrincipal::requiereSesion()
{
    if (idUsuarioActual > 0) return true;
    if (!dao) { QMessageBox::warning(this, "Sin conexión", "No se pudo conectar a la base de datos."); return false; }
    if (panelSesion) { panelSesion->raise(); panelSesion->show(); return false; }

    panelSesion = new QFrame(ui->centralwidget);
    panelSesion->setObjectName("panelSesion");
    panelSesion->setGeometry(qMax(20, ui->centralwidget->width() - 400), 78, 370, 405);
    panelSesion->setStyleSheet("#panelSesion { background:#111; border:1px solid #343434; border-radius:10px; } QLabel { color:#f5f5f5; } QLineEdit { background:#191919; color:white; border:1px solid #363636; border-radius:6px; padding:10px; } QLineEdit:focus { border-color:#ffd700; } QPushButton { border-radius:6px; padding:10px; font-weight:bold; } ");
    auto *layout = new QVBoxLayout(panelSesion); layout->setContentsMargins(26, 22, 26, 22); layout->setSpacing(12);
    auto *marca = new QLabel("●  SPOTCLOUD", panelSesion); marca->setStyleSheet("color:#ffd700; font-size:16px; font-weight:bold;");
    auto *titulo = new QLabel("Iniciar sesión", panelSesion); titulo->setStyleSheet("font-size:22px; font-weight:bold;");
    auto *descripcion = new QLabel("Iniciá sesión para reproducir y usar tu fila.", panelSesion); descripcion->setWordWrap(true); descripcion->setStyleSheet("color:#a9a9a9;");
    auto *nombre = new QLineEdit(panelSesion); nombre->setPlaceholderText("Tu nombre"); nombre->hide();
    auto *correo = new QLineEdit(panelSesion); correo->setPlaceholderText("Correo electrónico");
    auto *clave = new QLineEdit(panelSesion); clave->setPlaceholderText("Contraseña"); clave->setEchoMode(QLineEdit::Password);
    auto *entrar = new QPushButton("Iniciar sesión", panelSesion); entrar->setStyleSheet("background:#ffd700; color:#111;");
    auto *registro = new QPushButton("Crear una cuenta", panelSesion); registro->setStyleSheet("background:transparent; color:#ffd700; border:1px solid #ffd700;");
    auto *volver = new QPushButton("← Volver a iniciar sesión", panelSesion); volver->setStyleSheet("background:transparent; color:#ffd700; border:none;"); volver->hide();
    auto *cerrar = new QPushButton("×", panelSesion); cerrar->setFixedSize(30, 30); cerrar->setStyleSheet("background:transparent; color:#aaa; border:none; font-size:20px;");
    auto *cabecera = new QHBoxLayout; cabecera->addWidget(marca); cabecera->addStretch(); cabecera->addWidget(cerrar);
    layout->addLayout(cabecera); layout->addWidget(titulo); layout->addWidget(descripcion); layout->addWidget(nombre); layout->addWidget(correo); layout->addWidget(clave); layout->addWidget(entrar); layout->addWidget(registro); layout->addWidget(volver); layout->addStretch();
    connect(cerrar, &QPushButton::clicked, panelSesion, &QWidget::hide);
    const QMetaObject::Connection loginConexion = connect(entrar, &QPushButton::clicked, this, [this, correo, clave]() { const UsuarioSesion sesion = dao->iniciarSesion(correo->text(), clave->text()); if (!sesion.valido()) { QMessageBox::warning(this, "Datos incorrectos", "Revisá el correo y la contraseña."); return; } idUsuarioActual = sesion.id; if (btnPerfil) { btnPerfil->setText("●  " + sesion.nombre); btnPerfil->setStyleSheet("QPushButton { background:transparent; color:#d9d9d9; border:none; padding:7px 10px; } QPushButton:hover { color:#ffd700; }"); } panelSesion->hide(); });
    connect(registro, &QPushButton::clicked, this, [this, titulo, descripcion, nombre, correo, clave, entrar, registro, volver, loginConexion]() { disconnect(loginConexion); titulo->setText("Crear cuenta"); descripcion->setText("Completá tus datos para crear tu cuenta."); nombre->show(); registro->hide(); volver->show(); entrar->setText("Crear cuenta"); connect(entrar, &QPushButton::clicked, this, [this, nombre, correo, clave]() { QString motivo; if (nombre->text().trimmed().isEmpty()) { QMessageBox::warning(this, "Falta información", "Ingresá tu nombre."); return; } if (dao->registrar(nombre->text(), correo->text(), clave->text(), &motivo)) { QMessageBox::information(this, "Cuenta creada", "Tu cuenta fue creada. Volvé a iniciar sesión."); } else QMessageBox::warning(this, "No se pudo crear", motivo); }); });
    connect(volver, &QPushButton::clicked, this, [this] { panelSesion->hide(); panelSesion->deleteLater(); panelSesion = nullptr; requiereSesion(); });
    panelSesion->show(); panelSesion->raise();
    return false;
}

void VentanaPrincipal::mostrarFila()
{
    if (panelFila) { panelFila->raise(); panelFila->show(); return; }
    panelFila = new QFrame(ui->centralwidget);
    panelFila->setObjectName("panelFila");
    panelFila->setGeometry(qMax(20, ui->centralwidget->width() - 440), 135, 410, 440);
    panelFila->setStyleSheet("#panelFila { background:#111; border:1px solid #343434; border-radius:10px; } QLabel { color:#f5f5f5; } QPushButton { border-radius:6px; padding:8px; font-weight:bold; }");
    auto *layout = new QVBoxLayout(panelFila); layout->setContentsMargins(22, 20, 22, 20); layout->setSpacing(10);
    auto *superior = new QHBoxLayout;
    auto *titulos = new QVBoxLayout; auto *marca = new QLabel("TU MÚSICA", panelFila); marca->setStyleSheet("color:#ffd700; font-weight:bold; font-size:12px;"); auto *titulo = new QLabel("Fila de reproducción", panelFila); titulo->setStyleSheet("font-size:20px; font-weight:bold;"); titulos->addWidget(marca); titulos->addWidget(titulo);
    auto *cerrar = new QPushButton("×", panelFila); cerrar->setFixedSize(30, 30); cerrar->setStyleSheet("background:transparent; color:#aaa; border:none; font-size:20px;"); superior->addLayout(titulos); superior->addStretch(); superior->addWidget(cerrar); layout->addLayout(superior);
    auto *lista = new QWidget(panelFila); auto *listaLayout = new QVBoxLayout(lista); listaLayout->setContentsMargins(0,0,0,0); listaLayout->setSpacing(8);
    int orden = 1;
    for (int id : colaReproduccion) {
        for (int fila = 0; modelo && fila < modelo->rowCount(); ++fila) if (modelo->data(modelo->index(fila, 0)).toInt() == id) {
            auto *item = new QFrame(lista); item->setStyleSheet("background:#1b1b1b; border:1px solid #303030; border-radius:7px;"); auto *filaItem = new QHBoxLayout(item); auto *numero = new QLabel(QString::number(orden++), item); numero->setStyleSheet("color:#aaa;"); auto *nombre = new QLabel(modelo->data(modelo->index(fila,1)).toString(), item); nombre->setStyleSheet("font-weight:bold;"); filaItem->addWidget(numero); filaItem->addSpacing(10); filaItem->addWidget(nombre); filaItem->addStretch(); listaLayout->addWidget(item); break;
        }
    }
    if (orden == 1) { auto *vacia = new QLabel("Todavía no agregaste canciones a la fila.", lista); vacia->setStyleSheet("color:#aaa;"); listaLayout->addWidget(vacia); }
    auto *vaciar = new QPushButton("Vaciar fila", panelFila); vaciar->setStyleSheet("background:#242424; color:#f5f5f5; border:1px solid #343434;"); layout->addWidget(lista); layout->addStretch(); layout->addWidget(vaciar); connect(cerrar, &QPushButton::clicked, panelFila, &QWidget::hide); connect(vaciar, &QPushButton::clicked, this, [this] { colaReproduccion.clear(); panelFila->hide(); panelFila->deleteLater(); panelFila = nullptr; }); panelFila->show(); panelFila->raise();
}

void VentanaPrincipal::agregarFila(int fila)
{
    if (!modelo || fila < 0 || fila >= modelo->rowCount()) return;
    const int idCancion = modelo->data(modelo->index(fila, 0)).toInt();
    if (idCancion > 0 && !colaReproduccion.contains(idCancion)) colaReproduccion.append(idCancion);
}

void VentanaPrincipal::configurarPasoAdmin()
{
    const QVector<QPushButton *> botones = {ui->btnPasoArtista, ui->btnPasoAlbum, ui->btnPasoCancion, ui->btnPasoEliminar};
    // Cada formulario se reubica en una página del QStackedWidget creado en el .ui.
    // Así las tarjetas no comparten espacio con los formularios.
    ui->stackedAdmin->removeWidget(ui->paginaAdminVacia);
    ui->paginaAdminVacia->deleteLater();
    ui->frameNuevoArtista->setMaximumWidth(560);
    ui->frameNuevoAlbum->setMaximumWidth(560);
    ui->frameNuevaCancion->setMaximumWidth(560);
    ui->frameEliminarContenido->setMinimumWidth(560);
    ui->frameEliminarContenido->setMaximumWidth(560);
    ui->frameEliminarContenido->setFixedHeight(245);
    const QVector<QFrame *> formularios = {ui->frameNuevoArtista, ui->frameNuevoAlbum, ui->frameNuevaCancion, ui->frameEliminarContenido};
    for (QFrame *formulario : formularios) {
        auto *pagina = new QWidget(ui->stackedAdmin);
        auto *centrar = new QHBoxLayout(pagina);
        centrar->setContentsMargins(0, 0, 0, 0);
        centrar->addStretch();
        centrar->addWidget(formulario, 0, Qt::AlignTop);
        centrar->addStretch();
        ui->stackedAdmin->addWidget(pagina);
    }
    auto mostrarPaso = [this, botones](int paso) {
        for (int i = 0; i < botones.size(); ++i) botones.at(i)->setChecked(i == paso);
        ui->stackedAdmin->setCurrentIndex(paso);
    };
    for (int i = 0; i < botones.size(); ++i) connect(botones.at(i), &QPushButton::clicked, this, [mostrarPaso, i] { mostrarPaso(i); });
    mostrarPaso(0);
}


bool VentanaPrincipal::hayConexionRed() const
{
    const QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    for (const QNetworkInterface &interfaz : interfaces) {
        const QNetworkInterface::InterfaceFlags flags = interfaz.flags();
        const bool activa = flags.testFlag(QNetworkInterface::IsUp) && flags.testFlag(QNetworkInterface::IsRunning);
        const bool loopback = flags.testFlag(QNetworkInterface::IsLoopBack);

        if (activa && !loopback) {
            return true;
        }
    }

    return false;
}


VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}
