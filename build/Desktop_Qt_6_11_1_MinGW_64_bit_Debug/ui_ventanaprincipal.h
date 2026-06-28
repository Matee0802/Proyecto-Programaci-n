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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaCanciones;
    QFrame *frameReproductor;
    QSlider *sliderProgreso;
    QHBoxLayout *horizontalLayout;
    QLabel *lblNombreCancion;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPlayPausa;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName("VentanaPrincipal");
        VentanaPrincipal->resize(1011, 631);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaCanciones = new QTableView(centralwidget);
        tablaCanciones->setObjectName("tablaCanciones");
        tablaCanciones->setFrameShape(QFrame::Shape::NoFrame);

        verticalLayout->addWidget(tablaCanciones);

        frameReproductor = new QFrame(centralwidget);
        frameReproductor->setObjectName("frameReproductor");
        frameReproductor->setMaximumSize(QSize(16777215, 80));
        frameReproductor->setVisible(false);
        frameReproductor->setStyleSheet(QString::fromUtf8("background-color: #181818;"));
        sliderProgreso = new QSlider(frameReproductor);
        sliderProgreso->setObjectName("sliderProgreso");
        sliderProgreso->setGeometry(QRect(300, 20, 400, 20));
        sliderProgreso->setOrientation(Qt::Orientation::Horizontal);
        horizontalLayout = new QHBoxLayout(frameReproductor);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        lblNombreCancion = new QLabel(frameReproductor);
        lblNombreCancion->setObjectName("lblNombreCancion");
        lblNombreCancion->setStyleSheet(QString::fromUtf8("color: white; font-weight: bold; font-size: 14px;"));

        horizontalLayout->addWidget(lblNombreCancion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPlayPausa = new QPushButton(frameReproductor);
        btnPlayPausa->setObjectName("btnPlayPausa");
        btnPlayPausa->setMinimumSize(QSize(100, 35));
        btnPlayPausa->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPlayPausa->setStyleSheet(QString::fromUtf8("background-color: #FFD700; color: black; font-weight: bold; border-radius: 17px;"));

        horizontalLayout->addWidget(btnPlayPausa);


        verticalLayout->addWidget(frameReproductor);

        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1011, 21));
        VentanaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaPrincipal);
        statusbar->setObjectName("statusbar");
        VentanaPrincipal->setStatusBar(statusbar);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QCoreApplication::translate("VentanaPrincipal", "SpotCloud - Cat\303\241logo de M\303\272sica", nullptr));
        lblNombreCancion->setText(QCoreApplication::translate("VentanaPrincipal", "No hay canci\303\263n seleccionada", nullptr));
        btnPlayPausa->setText(QCoreApplication::translate("VentanaPrincipal", "Pausar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
