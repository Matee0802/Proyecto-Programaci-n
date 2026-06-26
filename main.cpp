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
            background-color: #181818;
            color: white;
            alternate-background-color: #282828;
            border: none;
        }
        QHeaderView::section {
            background-color: #282828;
            color: #FFD700; /* Ese amarillo icónico de tu presentación */
            padding: 5px;
            border: none;
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