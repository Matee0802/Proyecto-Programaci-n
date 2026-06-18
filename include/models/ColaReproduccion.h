#ifndef COLAREPRODUCCION_H
#define COLAREPRODUCCION_H
#include <string>
using namespace std;

//Creamos la clase ColaReproduccion
class ColaReproduccion {
private:
    int id_cola;
    int id_usuario;
public:
    ColaReproduccion(); //metodo constructor inicial por defecto
    ColaReproduccion(int id_usuario); //Metodo constructor para crear una cola

    //Getters para leer los atributos de esa clase
    int getIdCola();
    int getIdUsuario();

    //Setters para cambiar estos atributos.
    void setIdCola(int id);
    void setIdUsuario(int id_usu);
};
#endif