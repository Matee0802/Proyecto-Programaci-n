#include <QApplication>
#include <QFile>
#include "ventanaprincipal.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Definimos el estilo oscuro con acentos amarillos
    QString estilo = R"(
        QMainWindow { background-color: #121212; }
        QTableView {
        background-color: #121212;
        border: none; /* Adiós borde de tabla */
        gridline-color: transparent; /* Adiós líneas divisorias */
        }

        /* Encabezado elegante */
        QHeaderView::section {
        background-color: #121212;
        color: #FFD700; /* Tu amarillo */
        border: none;
        font-weight: bold;
        padding: 10px;
        }

     /* Selección amarilla */
        QTableView::item:selected {
        background-color: #FFD700;
        color: #000000;
        }
        QPushButton {
            background-color: #FFD700;
            color: black;
            font-weight: bold;
            border-radius: 10px;
            padding: 5px;
        }
        QLabel { color: white; }
     #frameReproductor {
            background-color: #1e1e1e;
            border-top: 2px solid #FFD700;
            border-top-left-radius: 15px;
            border-top-right-radius: 15px;
             }
     #lblNombreCancion {
        color: #FFD700;
        font-size: 16px;
        font-weight: bold;
        margin-left: 20px;
         }
    )";

    a.setStyleSheet(estilo);

    VentanaPrincipal w;
    w.show();
    return a.exec();
}