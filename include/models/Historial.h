#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <string>
using namespace std;

//Creamos la clase Historial
class Historial {
private:
    int id_historial;
    int id_usuario;
    int id_cancion;
    string fecha_reproduccion;
public:
    Historial(); //metodo constructor inicial por defecto
    Historial(int id_usuario, int id_cancion, string fecha_reproduccion); //Metodo constructor para crear un historial

    //Getters para leer los atributos de esa clase
    int getIdHistorial();
    int getIdUsuario();
    int getIdCancion();
    string getFechaReproduccion();

    //Setters para cambiar estos atributos.
    void setIdHistorial(int id);
    void setIdUsuario(int id_usu);
    void setIdCancion(int id_can);
    void setFechaReproduccion(string f);
};
#endif