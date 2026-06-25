#include <QApplication>
#include "ventanaprincipal.h"

int main(int argc, char *argv[])
{
    // QApplication se encarga de gestionar los eventos de la ventana, clics, etc.
    QApplication a(argc, argv);

    // Instanciamos tu ventana principal
    VentanaPrincipal w;

    // La mostramos en pantalla
    w.show();

    // Dejamos el programa corriendo en bucle hasta que se cierre la ventana
    return a.exec();
}