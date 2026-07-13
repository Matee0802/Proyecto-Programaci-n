/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_Main;
    QFrame *widgetNav;
    QHBoxLayout *horizontalLayout_Nav;
    QLabel *lblLogo;
    QSpacerItem *horizontalSpacer_NavLeft;
    QPushButton *btnInicio;
    QPushButton *btnBuscar;
    QPushButton *btnAdmin;
    QSpacerItem *horizontalSpacer_NavRight;
    QPushButton *btnPerfil;
    QStackedWidget *stackedWidget;
    QWidget *paginaInicio;
    QVBoxLayout *verticalLayout_Inicio;
    QLabel *lblTituloInicio;
    QLabel *lblSubtituloInicio;
    QScrollArea *scrollAlbumes;
    QWidget *contenedorAlbumes;
    QGridLayout *gridAlbumes;
    QWidget *paginaBuscar;
    QVBoxLayout *verticalLayout_Buscar;
    QLabel *lblTituloBuscar;
    QLineEdit *txtBuscar;
    QTableView *tablaBusqueda;
    QWidget *paginaAlbum;
    QVBoxLayout *verticalLayout_Album;
    QLabel *lblTituloAlbum;
    QLabel *lblArtistaAlbum;
    QTableView *tablaCanciones;
    QWidget *paginaAdmin;
    QVBoxLayout *verticalLayout_Admin;
    QLabel *lblTituloAdmin;
    QHBoxLayout *horizontalLayout_AdminCards;
    QFrame *frameEliminarContenido;
    QVBoxLayout *verticalLayout_EliminarContenido;
    QLabel *lblEliminarContenido;
    QComboBox *comboTipoEliminar;
    QLineEdit *txtFiltroEliminar;
    QComboBox *comboElementoEliminar;
    QPushButton *btnEliminarContenido;
    QPushButton *btnPasoArtista;
    QPushButton *btnPasoAlbum;
    QPushButton *btnPasoCancion;
    QPushButton *btnPasoEliminar;
    QFrame *frameNuevoArtista;
    QVBoxLayout *verticalLayout_NuevoArtista;
    QLabel *lblNuevoArtista;
    QLineEdit *txtNombreArtista;
    QTextEdit *txtBioArtista;
    QLineEdit *txtGeneroArtista;
    QSpacerItem *verticalSpacer_Artista;
    QPushButton *btnGuardarArtista;
    QFrame *frameNuevoAlbum;
    QVBoxLayout *verticalLayout_NuevoAlbum;
    QLabel *lblNuevoAlbum;
    QLineEdit *txtTituloAlbum;
    QSpinBox *spinAnioAlbum;
    QComboBox *comboArtistasAlbum;
    QLineEdit *txtPortadaAlbum;
    QHBoxLayout *horizontalLayout_PortadaLocal;
    QPushButton *btnSeleccionarPortadaLocal;
    QSpacerItem *verticalSpacer_Album;
    QPushButton *btnGuardarAlbum;
    QFrame *frameNuevaCancion;
    QVBoxLayout *verticalLayout_NuevaCancion;
    QLabel *lblNuevaCancion;
    QLineEdit *txtTituloCancion;
    QTimeEdit *timeDuracionCancion;
    QComboBox *comboAlbumCancion;
    QLineEdit *txtMp3Cancion;
    QHBoxLayout *horizontalLayout_Mp3Local;
    QPushButton *btnSeleccionarMp3Local;
    QSpacerItem *verticalSpacer_Cancion;
    QPushButton *btnGuardarCancion;
    QStackedWidget *stackedAdmin;
    QWidget *paginaAdminVacia;
    QFrame *frameReproductor;
    QHBoxLayout *horizontalLayout_Reproductor;
    QWidget *widget_Info;
    QVBoxLayout *verticalLayout_Info;
    QLabel *lblNombreCancion;
    QLabel *label_Artista;
    QSpacerItem *horizontalSpacer_1;
    QWidget *widget_Controles;
    QVBoxLayout *verticalLayout_Controles;
    QHBoxLayout *horizontalLayout_Botones;
    QSpacerItem *horizontalSpacer_ControlLeft;
    QPushButton *btnShuffle;
    QPushButton *btnPrev;
    QPushButton *btnPlayPausa;
    QPushButton *btnNext;
    QPushButton *btnRepeat;
    QSpacerItem *horizontalSpacer_ControlRight;
    QSlider *sliderProgreso;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_Volumen;
    QHBoxLayout *horizontalLayout_Volumen;
    QLabel *lblIconoVol;
    QSlider *sliderVolumen;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName("VentanaPrincipal");
        VentanaPrincipal->resize(1623, 1150);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_Main = new QVBoxLayout(centralwidget);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 0);
        widgetNav = new QFrame(centralwidget);
        widgetNav->setObjectName("widgetNav");
        widgetNav->setMinimumSize(QSize(0, 54));
        widgetNav->setMaximumSize(QSize(16777215, 54));
        widgetNav->setStyleSheet(QString::fromUtf8("background-color: #090909; border-bottom: 1px solid #181818;"));
        horizontalLayout_Nav = new QHBoxLayout(widgetNav);
        horizontalLayout_Nav->setSpacing(18);
        horizontalLayout_Nav->setObjectName("horizontalLayout_Nav");
        horizontalLayout_Nav->setContentsMargins(24, -1, 24, -1);
        lblLogo = new QLabel(widgetNav);
        lblLogo->setObjectName("lblLogo");
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        lblLogo->setFont(font);
        lblLogo->setStyleSheet(QString::fromUtf8("color: #FFD700;"));

        horizontalLayout_Nav->addWidget(lblLogo);

        horizontalSpacer_NavLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Nav->addItem(horizontalSpacer_NavLeft);

        btnInicio = new QPushButton(widgetNav);
        btnInicio->setObjectName("btnInicio");
        btnInicio->setStyleSheet(QString::fromUtf8("background: transparent; color: white; border: none; font-weight: bold;"));

        horizontalLayout_Nav->addWidget(btnInicio);

        btnBuscar = new QPushButton(widgetNav);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setStyleSheet(QString::fromUtf8("background: transparent; color: white; border: none; font-weight: bold;"));

        horizontalLayout_Nav->addWidget(btnBuscar);

        btnAdmin = new QPushButton(widgetNav);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setStyleSheet(QString::fromUtf8("background: transparent; color: white; border: none; font-weight: bold;"));

        horizontalLayout_Nav->addWidget(btnAdmin);

        horizontalSpacer_NavRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Nav->addItem(horizontalSpacer_NavRight);

        btnPerfil = new QPushButton(widgetNav);
        btnPerfil->setObjectName("btnPerfil");
        btnPerfil->setMinimumSize(QSize(132, 0));
        btnPerfil->setStyleSheet(QString::fromUtf8("background: transparent; color: #d9d9d9; border: none; font-weight: bold;"));

        horizontalLayout_Nav->addWidget(btnPerfil);


        verticalLayout_Main->addWidget(widgetNav);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #121212; color: white;"));
        paginaInicio = new QWidget();
        paginaInicio->setObjectName("paginaInicio");
        verticalLayout_Inicio = new QVBoxLayout(paginaInicio);
        verticalLayout_Inicio->setSpacing(14);
        verticalLayout_Inicio->setObjectName("verticalLayout_Inicio");
        verticalLayout_Inicio->setContentsMargins(24, 22, 24, 22);
        lblTituloInicio = new QLabel(paginaInicio);
        lblTituloInicio->setObjectName("lblTituloInicio");
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        lblTituloInicio->setFont(font1);
        lblTituloInicio->setStyleSheet(QString::fromUtf8("color: #FFD700;"));

        verticalLayout_Inicio->addWidget(lblTituloInicio);

        lblSubtituloInicio = new QLabel(paginaInicio);
        lblSubtituloInicio->setObjectName("lblSubtituloInicio");
        lblSubtituloInicio->setStyleSheet(QString::fromUtf8("color: #b3b3b3; font-size: 11px;"));

        verticalLayout_Inicio->addWidget(lblSubtituloInicio);

        scrollAlbumes = new QScrollArea(paginaInicio);
        scrollAlbumes->setObjectName("scrollAlbumes");
        scrollAlbumes->setStyleSheet(QString::fromUtf8("background: transparent; border: none;"));
        scrollAlbumes->setWidgetResizable(true);
        contenedorAlbumes = new QWidget();
        contenedorAlbumes->setObjectName("contenedorAlbumes");
        contenedorAlbumes->setGeometry(QRect(0, 0, 38, 16));
        gridAlbumes = new QGridLayout(contenedorAlbumes);
        gridAlbumes->setObjectName("gridAlbumes");
        gridAlbumes->setHorizontalSpacing(18);
        gridAlbumes->setVerticalSpacing(26);
        gridAlbumes->setContentsMargins(0, 0, 0, 0);
        scrollAlbumes->setWidget(contenedorAlbumes);

        verticalLayout_Inicio->addWidget(scrollAlbumes);

        stackedWidget->addWidget(paginaInicio);
        paginaBuscar = new QWidget();
        paginaBuscar->setObjectName("paginaBuscar");
        verticalLayout_Buscar = new QVBoxLayout(paginaBuscar);
        verticalLayout_Buscar->setSpacing(14);
        verticalLayout_Buscar->setObjectName("verticalLayout_Buscar");
        verticalLayout_Buscar->setContentsMargins(24, 22, 24, 22);
        lblTituloBuscar = new QLabel(paginaBuscar);
        lblTituloBuscar->setObjectName("lblTituloBuscar");
        lblTituloBuscar->setFont(font1);
        lblTituloBuscar->setStyleSheet(QString::fromUtf8("color: #FFD700;"));

        verticalLayout_Buscar->addWidget(lblTituloBuscar);

        txtBuscar = new QLineEdit(paginaBuscar);
        txtBuscar->setObjectName("txtBuscar");
        txtBuscar->setMinimumSize(QSize(0, 36));
        txtBuscar->setStyleSheet(QString::fromUtf8("background-color: #181818; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_Buscar->addWidget(txtBuscar);

        tablaBusqueda = new QTableView(paginaBuscar);
        tablaBusqueda->setObjectName("tablaBusqueda");
        tablaBusqueda->setFrameShape(QFrame::Shape::NoFrame);

        verticalLayout_Buscar->addWidget(tablaBusqueda);

        stackedWidget->addWidget(paginaBuscar);
        paginaAlbum = new QWidget();
        paginaAlbum->setObjectName("paginaAlbum");
        verticalLayout_Album = new QVBoxLayout(paginaAlbum);
        verticalLayout_Album->setSpacing(14);
        verticalLayout_Album->setObjectName("verticalLayout_Album");
        verticalLayout_Album->setContentsMargins(24, 22, 24, 22);
        lblTituloAlbum = new QLabel(paginaAlbum);
        lblTituloAlbum->setObjectName("lblTituloAlbum");
        lblTituloAlbum->setFont(font1);
        lblTituloAlbum->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_Album->addWidget(lblTituloAlbum);

        lblArtistaAlbum = new QLabel(paginaAlbum);
        lblArtistaAlbum->setObjectName("lblArtistaAlbum");
        lblArtistaAlbum->setStyleSheet(QString::fromUtf8("color: #b3b3b3;"));

        verticalLayout_Album->addWidget(lblArtistaAlbum);

        tablaCanciones = new QTableView(paginaAlbum);
        tablaCanciones->setObjectName("tablaCanciones");
        tablaCanciones->setFrameShape(QFrame::Shape::NoFrame);

        verticalLayout_Album->addWidget(tablaCanciones);

        stackedWidget->addWidget(paginaAlbum);
        paginaAdmin = new QWidget();
        paginaAdmin->setObjectName("paginaAdmin");
        verticalLayout_Admin = new QVBoxLayout(paginaAdmin);
        verticalLayout_Admin->setSpacing(18);
        verticalLayout_Admin->setObjectName("verticalLayout_Admin");
        verticalLayout_Admin->setContentsMargins(24, 22, 24, 22);
        lblTituloAdmin = new QLabel(paginaAdmin);
        lblTituloAdmin->setObjectName("lblTituloAdmin");
        QFont font2;
        font2.setPointSize(28);
        font2.setBold(true);
        lblTituloAdmin->setFont(font2);
        lblTituloAdmin->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout_Admin->addWidget(lblTituloAdmin);

        horizontalLayout_AdminCards = new QHBoxLayout();
        horizontalLayout_AdminCards->setSpacing(12);
        horizontalLayout_AdminCards->setObjectName("horizontalLayout_AdminCards");
        frameEliminarContenido = new QFrame(paginaAdmin);
        frameEliminarContenido->setObjectName("frameEliminarContenido");
        frameEliminarContenido->setAutoFillBackground(false);
        frameEliminarContenido->setStyleSheet(QString::fromUtf8("background-color: #181818; border: 1px solid #282828; border-radius: 6px;"));
        verticalLayout_EliminarContenido = new QVBoxLayout(frameEliminarContenido);
        verticalLayout_EliminarContenido->setSpacing(10);
        verticalLayout_EliminarContenido->setObjectName("verticalLayout_EliminarContenido");
        verticalLayout_EliminarContenido->setContentsMargins(18, 18, 18, 18);
        lblEliminarContenido = new QLabel(frameEliminarContenido);
        lblEliminarContenido->setObjectName("lblEliminarContenido");
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        lblEliminarContenido->setFont(font3);
        lblEliminarContenido->setStyleSheet(QString::fromUtf8("color: white; border: none;"));

        verticalLayout_EliminarContenido->addWidget(lblEliminarContenido);

        comboTipoEliminar = new QComboBox(frameEliminarContenido);
        comboTipoEliminar->setObjectName("comboTipoEliminar");

        verticalLayout_EliminarContenido->addWidget(comboTipoEliminar);

        txtFiltroEliminar = new QLineEdit(frameEliminarContenido);
        txtFiltroEliminar->setObjectName("txtFiltroEliminar");
        txtFiltroEliminar->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_EliminarContenido->addWidget(txtFiltroEliminar);

        comboElementoEliminar = new QComboBox(frameEliminarContenido);
        comboElementoEliminar->setObjectName("comboElementoEliminar");

        verticalLayout_EliminarContenido->addWidget(comboElementoEliminar);

        btnEliminarContenido = new QPushButton(frameEliminarContenido);
        btnEliminarContenido->setObjectName("btnEliminarContenido");
        btnEliminarContenido->setMinimumSize(QSize(0, 42));
        btnEliminarContenido->setStyleSheet(QString::fromUtf8("background-color: #b00020; color: white; border: none; border-radius: 6px; font-weight: bold;"));

        verticalLayout_EliminarContenido->addWidget(btnEliminarContenido);


        horizontalLayout_AdminCards->addWidget(frameEliminarContenido);

        btnPasoArtista = new QPushButton(paginaAdmin);
        btnPasoArtista->setObjectName("btnPasoArtista");
        btnPasoArtista->setMinimumSize(QSize(185, 86));
        btnPasoArtista->setStyleSheet(QString::fromUtf8("QPushButton { text-align:left; padding:12px; background:#1b1b1b; color:#f5f5f5; border:1px solid #333; border-radius:8px; font-weight:bold; } QPushButton:checked { border:1px solid #ffd700; background:#242424; } QPushButton:hover { background:#242424; }"));
        btnPasoArtista->setCheckable(true);

        horizontalLayout_AdminCards->addWidget(btnPasoArtista);

        btnPasoAlbum = new QPushButton(paginaAdmin);
        btnPasoAlbum->setObjectName("btnPasoAlbum");
        btnPasoAlbum->setMinimumSize(QSize(185, 86));
        btnPasoAlbum->setStyleSheet(QString::fromUtf8("QPushButton { text-align:left; padding:12px; background:#1b1b1b; color:#f5f5f5; border:1px solid #333; border-radius:8px; font-weight:bold; } QPushButton:checked { border:1px solid #ffd700; background:#242424; } QPushButton:hover { background:#242424; }"));
        btnPasoAlbum->setCheckable(true);

        horizontalLayout_AdminCards->addWidget(btnPasoAlbum);

        btnPasoCancion = new QPushButton(paginaAdmin);
        btnPasoCancion->setObjectName("btnPasoCancion");
        btnPasoCancion->setMinimumSize(QSize(185, 86));
        btnPasoCancion->setStyleSheet(QString::fromUtf8("QPushButton { text-align:left; padding:12px; background:#1b1b1b; color:#f5f5f5; border:1px solid #333; border-radius:8px; font-weight:bold; } QPushButton:checked { border:1px solid #ffd700; background:#242424; } QPushButton:hover { background:#242424; }"));
        btnPasoCancion->setCheckable(true);

        horizontalLayout_AdminCards->addWidget(btnPasoCancion);

        btnPasoEliminar = new QPushButton(paginaAdmin);
        btnPasoEliminar->setObjectName("btnPasoEliminar");
        btnPasoEliminar->setMinimumSize(QSize(185, 86));
        btnPasoEliminar->setStyleSheet(QString::fromUtf8("QPushButton { text-align:left; padding:12px; background:#1b1b1b; color:#f5f5f5; border:1px solid #333; border-radius:8px; font-weight:bold; } QPushButton:checked { border:1px solid #ffd700; background:#242424; } QPushButton:hover { background:#242424; }"));
        btnPasoEliminar->setCheckable(true);

        horizontalLayout_AdminCards->addWidget(btnPasoEliminar);

        frameNuevoArtista = new QFrame(paginaAdmin);
        frameNuevoArtista->setObjectName("frameNuevoArtista");
        frameNuevoArtista->setStyleSheet(QString::fromUtf8("background-color: #181818; border: 1px solid #282828; border-radius: 6px;"));
        verticalLayout_NuevoArtista = new QVBoxLayout(frameNuevoArtista);
        verticalLayout_NuevoArtista->setSpacing(10);
        verticalLayout_NuevoArtista->setObjectName("verticalLayout_NuevoArtista");
        verticalLayout_NuevoArtista->setContentsMargins(18, 18, 18, 18);
        lblNuevoArtista = new QLabel(frameNuevoArtista);
        lblNuevoArtista->setObjectName("lblNuevoArtista");
        lblNuevoArtista->setFont(font3);
        lblNuevoArtista->setStyleSheet(QString::fromUtf8("color: white; border: none;"));

        verticalLayout_NuevoArtista->addWidget(lblNuevoArtista);

        txtNombreArtista = new QLineEdit(frameNuevoArtista);
        txtNombreArtista->setObjectName("txtNombreArtista");
        txtNombreArtista->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevoArtista->addWidget(txtNombreArtista);

        txtBioArtista = new QTextEdit(frameNuevoArtista);
        txtBioArtista->setObjectName("txtBioArtista");
        txtBioArtista->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevoArtista->addWidget(txtBioArtista);

        txtGeneroArtista = new QLineEdit(frameNuevoArtista);
        txtGeneroArtista->setObjectName("txtGeneroArtista");
        txtGeneroArtista->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevoArtista->addWidget(txtGeneroArtista);

        verticalSpacer_Artista = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_NuevoArtista->addItem(verticalSpacer_Artista);

        btnGuardarArtista = new QPushButton(frameNuevoArtista);
        btnGuardarArtista->setObjectName("btnGuardarArtista");
        btnGuardarArtista->setMinimumSize(QSize(0, 42));
        btnGuardarArtista->setStyleSheet(QString::fromUtf8("background-color: #FFD700; color: black; border: none; border-radius: 6px; font-weight: bold;"));

        verticalLayout_NuevoArtista->addWidget(btnGuardarArtista);


        horizontalLayout_AdminCards->addWidget(frameNuevoArtista);

        frameNuevoAlbum = new QFrame(paginaAdmin);
        frameNuevoAlbum->setObjectName("frameNuevoAlbum");
        frameNuevoAlbum->setStyleSheet(QString::fromUtf8("background-color: #181818; border: 1px solid #282828; border-radius: 6px;"));
        verticalLayout_NuevoAlbum = new QVBoxLayout(frameNuevoAlbum);
        verticalLayout_NuevoAlbum->setSpacing(10);
        verticalLayout_NuevoAlbum->setObjectName("verticalLayout_NuevoAlbum");
        verticalLayout_NuevoAlbum->setContentsMargins(18, 18, 18, 18);
        lblNuevoAlbum = new QLabel(frameNuevoAlbum);
        lblNuevoAlbum->setObjectName("lblNuevoAlbum");
        lblNuevoAlbum->setFont(font3);
        lblNuevoAlbum->setStyleSheet(QString::fromUtf8("color: white; border: none;"));

        verticalLayout_NuevoAlbum->addWidget(lblNuevoAlbum);

        txtTituloAlbum = new QLineEdit(frameNuevoAlbum);
        txtTituloAlbum->setObjectName("txtTituloAlbum");
        txtTituloAlbum->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevoAlbum->addWidget(txtTituloAlbum);

        spinAnioAlbum = new QSpinBox(frameNuevoAlbum);
        spinAnioAlbum->setObjectName("spinAnioAlbum");
        spinAnioAlbum->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));
        spinAnioAlbum->setMinimum(1900);
        spinAnioAlbum->setMaximum(2100);
        spinAnioAlbum->setValue(2026);

        verticalLayout_NuevoAlbum->addWidget(spinAnioAlbum);

        comboArtistasAlbum = new QComboBox(frameNuevoAlbum);
        comboArtistasAlbum->setObjectName("comboArtistasAlbum");
        comboArtistasAlbum->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevoAlbum->addWidget(comboArtistasAlbum);

        txtPortadaAlbum = new QLineEdit(frameNuevoAlbum);
        txtPortadaAlbum->setObjectName("txtPortadaAlbum");
        txtPortadaAlbum->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevoAlbum->addWidget(txtPortadaAlbum);

        horizontalLayout_PortadaLocal = new QHBoxLayout();
        horizontalLayout_PortadaLocal->setObjectName("horizontalLayout_PortadaLocal");
        btnSeleccionarPortadaLocal = new QPushButton(frameNuevoAlbum);
        btnSeleccionarPortadaLocal->setObjectName("btnSeleccionarPortadaLocal");

        horizontalLayout_PortadaLocal->addWidget(btnSeleccionarPortadaLocal);


        verticalLayout_NuevoAlbum->addLayout(horizontalLayout_PortadaLocal);

        verticalSpacer_Album = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_NuevoAlbum->addItem(verticalSpacer_Album);

        btnGuardarAlbum = new QPushButton(frameNuevoAlbum);
        btnGuardarAlbum->setObjectName("btnGuardarAlbum");
        btnGuardarAlbum->setMinimumSize(QSize(0, 42));
        btnGuardarAlbum->setStyleSheet(QString::fromUtf8("background-color: #FFD700; color: black; border: none; border-radius: 6px; font-weight: bold;"));

        verticalLayout_NuevoAlbum->addWidget(btnGuardarAlbum);


        horizontalLayout_AdminCards->addWidget(frameNuevoAlbum);

        frameNuevaCancion = new QFrame(paginaAdmin);
        frameNuevaCancion->setObjectName("frameNuevaCancion");
        frameNuevaCancion->setStyleSheet(QString::fromUtf8("background-color: #181818; border: 1px solid #282828; border-radius: 6px;"));
        verticalLayout_NuevaCancion = new QVBoxLayout(frameNuevaCancion);
        verticalLayout_NuevaCancion->setSpacing(10);
        verticalLayout_NuevaCancion->setObjectName("verticalLayout_NuevaCancion");
        verticalLayout_NuevaCancion->setContentsMargins(18, 18, 18, 18);
        lblNuevaCancion = new QLabel(frameNuevaCancion);
        lblNuevaCancion->setObjectName("lblNuevaCancion");
        lblNuevaCancion->setFont(font3);
        lblNuevaCancion->setStyleSheet(QString::fromUtf8("color: white; border: none;"));

        verticalLayout_NuevaCancion->addWidget(lblNuevaCancion);

        txtTituloCancion = new QLineEdit(frameNuevaCancion);
        txtTituloCancion->setObjectName("txtTituloCancion");
        txtTituloCancion->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevaCancion->addWidget(txtTituloCancion);

        timeDuracionCancion = new QTimeEdit(frameNuevaCancion);
        timeDuracionCancion->setObjectName("timeDuracionCancion");
        timeDuracionCancion->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevaCancion->addWidget(timeDuracionCancion);

        comboAlbumCancion = new QComboBox(frameNuevaCancion);
        comboAlbumCancion->setObjectName("comboAlbumCancion");
        comboAlbumCancion->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevaCancion->addWidget(comboAlbumCancion);

        txtMp3Cancion = new QLineEdit(frameNuevaCancion);
        txtMp3Cancion->setObjectName("txtMp3Cancion");
        txtMp3Cancion->setStyleSheet(QString::fromUtf8("background-color: #101010; color: white; border: 1px solid #282828; border-radius: 4px; padding: 8px;"));

        verticalLayout_NuevaCancion->addWidget(txtMp3Cancion);

        horizontalLayout_Mp3Local = new QHBoxLayout();
        horizontalLayout_Mp3Local->setObjectName("horizontalLayout_Mp3Local");
        btnSeleccionarMp3Local = new QPushButton(frameNuevaCancion);
        btnSeleccionarMp3Local->setObjectName("btnSeleccionarMp3Local");

        horizontalLayout_Mp3Local->addWidget(btnSeleccionarMp3Local);


        verticalLayout_NuevaCancion->addLayout(horizontalLayout_Mp3Local);

        verticalSpacer_Cancion = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_NuevaCancion->addItem(verticalSpacer_Cancion);

        btnGuardarCancion = new QPushButton(frameNuevaCancion);
        btnGuardarCancion->setObjectName("btnGuardarCancion");
        btnGuardarCancion->setMinimumSize(QSize(0, 42));
        btnGuardarCancion->setStyleSheet(QString::fromUtf8("background-color: #FFD700; color: black; border: none; border-radius: 6px; font-weight: bold;"));

        verticalLayout_NuevaCancion->addWidget(btnGuardarCancion);


        horizontalLayout_AdminCards->addWidget(frameNuevaCancion);


        verticalLayout_Admin->addLayout(horizontalLayout_AdminCards);

        stackedAdmin = new QStackedWidget(paginaAdmin);
        stackedAdmin->setObjectName("stackedAdmin");
        stackedAdmin->setMinimumSize(QSize(0, 270));
        paginaAdminVacia = new QWidget();
        paginaAdminVacia->setObjectName("paginaAdminVacia");
        stackedAdmin->addWidget(paginaAdminVacia);

        verticalLayout_Admin->addWidget(stackedAdmin);

        stackedWidget->addWidget(paginaAdmin);

        verticalLayout_Main->addWidget(stackedWidget);

        frameReproductor = new QFrame(centralwidget);
        frameReproductor->setObjectName("frameReproductor");
        frameReproductor->setStyleSheet(QString::fromUtf8("background-color: #181818; color: white; border-top: 1px solid #282828;"));
        horizontalLayout_Reproductor = new QHBoxLayout(frameReproductor);
        horizontalLayout_Reproductor->setObjectName("horizontalLayout_Reproductor");
        horizontalLayout_Reproductor->setContentsMargins(15, -1, 15, -1);
        widget_Info = new QWidget(frameReproductor);
        widget_Info->setObjectName("widget_Info");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_Info->sizePolicy().hasHeightForWidth());
        widget_Info->setSizePolicy(sizePolicy);
        verticalLayout_Info = new QVBoxLayout(widget_Info);
        verticalLayout_Info->setObjectName("verticalLayout_Info");
        verticalLayout_Info->setContentsMargins(0, 0, 0, 0);
        lblNombreCancion = new QLabel(widget_Info);
        lblNombreCancion->setObjectName("lblNombreCancion");
        QFont font4;
        font4.setBold(true);
        lblNombreCancion->setFont(font4);
        lblNombreCancion->setStyleSheet(QString::fromUtf8("color: white; border: none;"));

        verticalLayout_Info->addWidget(lblNombreCancion);

        label_Artista = new QLabel(widget_Info);
        label_Artista->setObjectName("label_Artista");
        label_Artista->setStyleSheet(QString::fromUtf8("color: #b3b3b3; font-size: 11px; border: none;"));

        verticalLayout_Info->addWidget(label_Artista);


        horizontalLayout_Reproductor->addWidget(widget_Info);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Reproductor->addItem(horizontalSpacer_1);

        widget_Controles = new QWidget(frameReproductor);
        widget_Controles->setObjectName("widget_Controles");
        verticalLayout_Controles = new QVBoxLayout(widget_Controles);
        verticalLayout_Controles->setSpacing(5);
        verticalLayout_Controles->setObjectName("verticalLayout_Controles");
        horizontalLayout_Botones = new QHBoxLayout();
        horizontalLayout_Botones->setSpacing(15);
        horizontalLayout_Botones->setObjectName("horizontalLayout_Botones");
        horizontalSpacer_ControlLeft = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Botones->addItem(horizontalSpacer_ControlLeft);

        btnShuffle = new QPushButton(widget_Controles);
        btnShuffle->setObjectName("btnShuffle");

        horizontalLayout_Botones->addWidget(btnShuffle);

        btnPrev = new QPushButton(widget_Controles);
        btnPrev->setObjectName("btnPrev");

        horizontalLayout_Botones->addWidget(btnPrev);

        btnPlayPausa = new QPushButton(widget_Controles);
        btnPlayPausa->setObjectName("btnPlayPausa");

        horizontalLayout_Botones->addWidget(btnPlayPausa);

        btnNext = new QPushButton(widget_Controles);
        btnNext->setObjectName("btnNext");

        horizontalLayout_Botones->addWidget(btnNext);

        btnRepeat = new QPushButton(widget_Controles);
        btnRepeat->setObjectName("btnRepeat");

        horizontalLayout_Botones->addWidget(btnRepeat);

        horizontalSpacer_ControlRight = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Botones->addItem(horizontalSpacer_ControlRight);


        verticalLayout_Controles->addLayout(horizontalLayout_Botones);

        sliderProgreso = new QSlider(widget_Controles);
        sliderProgreso->setObjectName("sliderProgreso");
        sliderProgreso->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_Controles->addWidget(sliderProgreso);


        horizontalLayout_Reproductor->addWidget(widget_Controles);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Reproductor->addItem(horizontalSpacer_2);

        widget_Volumen = new QWidget(frameReproductor);
        widget_Volumen->setObjectName("widget_Volumen");
        horizontalLayout_Volumen = new QHBoxLayout(widget_Volumen);
        horizontalLayout_Volumen->setSpacing(10);
        horizontalLayout_Volumen->setObjectName("horizontalLayout_Volumen");
        horizontalLayout_Volumen->setContentsMargins(0, 0, 0, 0);
        lblIconoVol = new QLabel(widget_Volumen);
        lblIconoVol->setObjectName("lblIconoVol");
        lblIconoVol->setStyleSheet(QString::fromUtf8("color: #b3b3b3; border: none;"));

        horizontalLayout_Volumen->addWidget(lblIconoVol);

        sliderVolumen = new QSlider(widget_Volumen);
        sliderVolumen->setObjectName("sliderVolumen");
        sliderVolumen->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_Volumen->addWidget(sliderVolumen);


        horizontalLayout_Reproductor->addWidget(widget_Volumen);


        verticalLayout_Main->addWidget(frameReproductor);

        VentanaPrincipal->setCentralWidget(centralwidget);

        retranslateUi(VentanaPrincipal);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QCoreApplication::translate("VentanaPrincipal", "SpotCloud", nullptr));
        lblLogo->setText(QCoreApplication::translate("VentanaPrincipal", "SPOTCLOUD", nullptr));
        btnInicio->setText(QCoreApplication::translate("VentanaPrincipal", "Inicio", nullptr));
        btnBuscar->setText(QCoreApplication::translate("VentanaPrincipal", "Buscar", nullptr));
        btnAdmin->setText(QCoreApplication::translate("VentanaPrincipal", "Cargar", nullptr));
        btnPerfil->setText(QCoreApplication::translate("VentanaPrincipal", "Iniciar sesi\303\263n", nullptr));
        lblTituloInicio->setText(QCoreApplication::translate("VentanaPrincipal", "Buenas noches", nullptr));
        lblSubtituloInicio->setText(QCoreApplication::translate("VentanaPrincipal", "Tu biblioteca", nullptr));
        lblTituloBuscar->setText(QCoreApplication::translate("VentanaPrincipal", "Buscar", nullptr));
        txtBuscar->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Buscar canciones, albumes o artistas", nullptr));
        lblTituloAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "Album", nullptr));
        lblArtistaAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "Artista", nullptr));
        lblTituloAdmin->setText(QCoreApplication::translate("VentanaPrincipal", "Cargar contenido", nullptr));
        lblEliminarContenido->setText(QCoreApplication::translate("VentanaPrincipal", "Eliminar contenido", nullptr));
        txtFiltroEliminar->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Filtrar por nombre", nullptr));
        btnEliminarContenido->setText(QCoreApplication::translate("VentanaPrincipal", "Eliminar", nullptr));
        btnPasoArtista->setText(QCoreApplication::translate("VentanaPrincipal", "1\n"
"Artista o grupo\n"
"Crear artista", nullptr));
        btnPasoAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "2\n"
"\303\201lbum\n"
"Cargar portada", nullptr));
        btnPasoCancion->setText(QCoreApplication::translate("VentanaPrincipal", "3\n"
"Canci\303\263n\n"
"Subir MP3", nullptr));
        btnPasoEliminar->setText(QCoreApplication::translate("VentanaPrincipal", "Eliminar contenido\n"
"\n"
"Borrar contenido", nullptr));
        lblNuevoArtista->setText(QCoreApplication::translate("VentanaPrincipal", "Nuevo artista", nullptr));
        txtNombreArtista->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Nombre", nullptr));
        txtBioArtista->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Biografia corta", nullptr));
        txtGeneroArtista->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Genero", nullptr));
        btnGuardarArtista->setText(QCoreApplication::translate("VentanaPrincipal", "Guardar artista", nullptr));
        lblNuevoAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "Nuevo album", nullptr));
        txtTituloAlbum->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Titulo", nullptr));
        txtPortadaAlbum->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "URL de portada", nullptr));
        btnSeleccionarPortadaLocal->setText(QCoreApplication::translate("VentanaPrincipal", "Elegir portada local", nullptr));
        btnGuardarAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "Guardar album", nullptr));
        lblNuevaCancion->setText(QCoreApplication::translate("VentanaPrincipal", "Nueva cancion", nullptr));
        txtTituloCancion->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Titulo", nullptr));
        timeDuracionCancion->setDisplayFormat(QCoreApplication::translate("VentanaPrincipal", "HH:mm:ss", nullptr));
        txtMp3Cancion->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "URL del MP3", nullptr));
        btnSeleccionarMp3Local->setText(QCoreApplication::translate("VentanaPrincipal", "Elegir MP3 local", nullptr));
        btnGuardarCancion->setText(QCoreApplication::translate("VentanaPrincipal", "Guardar cancion", nullptr));
        lblNombreCancion->setText(QCoreApplication::translate("VentanaPrincipal", "Nombre de la Cancion", nullptr));
        label_Artista->setText(QCoreApplication::translate("VentanaPrincipal", "Artista", nullptr));
        btnShuffle->setStyleSheet(QCoreApplication::translate("VentanaPrincipal", "background: transparent; color: #b3b3b3; border: none;", nullptr));
        btnShuffle->setText(QCoreApplication::translate("VentanaPrincipal", "shuffle", nullptr));
        btnPrev->setStyleSheet(QCoreApplication::translate("VentanaPrincipal", "background: transparent; color: #b3b3b3; border: none;", nullptr));
        btnPrev->setText(QCoreApplication::translate("VentanaPrincipal", "skip_previous", nullptr));
        btnPlayPausa->setStyleSheet(QCoreApplication::translate("VentanaPrincipal", "background: transparent; color: white; border: none; font-size: 36px;", nullptr));
        btnPlayPausa->setText(QCoreApplication::translate("VentanaPrincipal", "play_circle", nullptr));
        btnNext->setStyleSheet(QCoreApplication::translate("VentanaPrincipal", "background: transparent; color: #b3b3b3; border: none;", nullptr));
        btnNext->setText(QCoreApplication::translate("VentanaPrincipal", "skip_next", nullptr));
        btnRepeat->setStyleSheet(QCoreApplication::translate("VentanaPrincipal", "background: transparent; color: #b3b3b3; border: none;", nullptr));
        btnRepeat->setText(QCoreApplication::translate("VentanaPrincipal", "repeat", nullptr));
        lblIconoVol->setText(QCoreApplication::translate("VentanaPrincipal", "volume_up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
