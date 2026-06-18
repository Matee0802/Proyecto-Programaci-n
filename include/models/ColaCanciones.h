#ifndef COLACANCIONES_H
#define COLACANCIONES_H
#include <string>
using namespace std;

//Creamos la clase ColaCanciones
class ColaCanciones {
private:
    int id_cola;
    int id_cancion;
    int orden;
    bool reproducida;
public:
    ColaCanciones(); //metodo constructor inicial por defecto
    ColaCanciones(int id_cola, int id_cancion, int orden, bool reproducida); //Metodo constructor para asociar cancion a la cola

    //Getters para leer los atributos de esa clase
    int getIdCola();
    int getIdCancion();
    int getOrden();
    bool getReproducida();

    //Setters para cambiar estos atributos.
    void setIdCola(int id);
    void setIdCancion(int id_can);
    void setOrden(int o);
    void setReproducida(bool r);
};
#endif