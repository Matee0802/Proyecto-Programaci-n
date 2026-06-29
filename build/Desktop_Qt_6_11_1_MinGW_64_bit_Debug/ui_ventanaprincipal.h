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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
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
    QSpacerItem *horizontalSpacer_NavRight;
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
        VentanaPrincipal->resize(1000, 600);
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
        btnBuscar->setStyleSheet(QString::fromUtf8("background: transparent; color: #b3b3b3; border: none;"));

        horizontalLayout_Nav->addWidget(btnBuscar);

        horizontalSpacer_NavRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Nav->addItem(horizontalSpacer_NavRight);


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
        contenedorAlbumes->setGeometry(QRect(0, 0, 930, 320));
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
        QFont font2;
        font2.setBold(true);
        lblNombreCancion->setFont(font2);
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

        verticalLayout_Main->setStretch(1, 1);
        VentanaPrincipal->setCentralWidget(centralwidget);

        retranslateUi(VentanaPrincipal);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QCoreApplication::translate("VentanaPrincipal", "SpotCloud", nullptr));
        lblLogo->setText(QCoreApplication::translate("VentanaPrincipal", "SPOTCLOUD", nullptr));
        btnInicio->setText(QCoreApplication::translate("VentanaPrincipal", "Inicio", nullptr));
        btnBuscar->setText(QCoreApplication::translate("VentanaPrincipal", "Buscar", nullptr));
        lblTituloInicio->setText(QCoreApplication::translate("VentanaPrincipal", "Buenas noches", nullptr));
        lblSubtituloInicio->setText(QCoreApplication::translate("VentanaPrincipal", "Tu biblioteca", nullptr));
        lblTituloBuscar->setText(QCoreApplication::translate("VentanaPrincipal", "Buscar", nullptr));
        txtBuscar->setPlaceholderText(QCoreApplication::translate("VentanaPrincipal", "Buscar canciones, albumes o artistas", nullptr));
        lblTituloAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "Album", nullptr));
        lblArtistaAlbum->setText(QCoreApplication::translate("VentanaPrincipal", "Artista", nullptr));
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
