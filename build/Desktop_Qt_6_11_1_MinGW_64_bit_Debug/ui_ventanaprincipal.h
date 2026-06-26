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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralwidget;
    QTableView *tablaCanciones;
    QFrame *frameReproductor;
    QLabel *lblNombreCancion;
    QPushButton *btnPausar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName("VentanaPrincipal");
        VentanaPrincipal->resize(800, 600);
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName("centralwidget");
        tablaCanciones = new QTableView(centralwidget);
        tablaCanciones->setObjectName("tablaCanciones");
        tablaCanciones->setGeometry(QRect(-10, 0, 821, 601));
        frameReproductor = new QFrame(centralwidget);
        frameReproductor->setObjectName("frameReproductor");
        frameReproductor->setGeometry(QRect(0, 600, 800, 100));
        frameReproductor->setVisible(false);
        lblNombreCancion = new QLabel(frameReproductor);
        lblNombreCancion->setObjectName("lblNombreCancion");
        lblNombreCancion->setGeometry(QRect(20, 35, 500, 30));
        btnPausar = new QPushButton(frameReproductor);
        btnPausar->setObjectName("btnPausar");
        btnPausar->setGeometry(QRect(650, 35, 100, 30));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(320, 190, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        VentanaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaPrincipal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        btnPausar->setText(QCoreApplication::translate("VentanaPrincipal", "Pausar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
