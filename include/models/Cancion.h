#ifndef CANCION_H
#define CANCION_H
#include <string>
using namespace std;

//Creamos la calse Cancion
class Cancion {
private:
    int id_cancion;
    string titulo;
    string duracion;
    int id_album;
    string ruta_archivo_mp3;
public:
    Cancion();//Metodo constructor inicial por defecto
    Cancion(string titulo, string duracion, int id_album, string ruta);//Metodo constructor para crear una cancion

    //Getters para leer los atributos de esa clase
    int getId();
    string getTitulo();
    string getDuracion();
    int getIdAlbum();
    string getRuta();

    //Setters para cambiar estos atributos.
    void setId(int id);
    void setTitulo(string t);
    void setDuracion(string d);
    void setIdAlbum(int id_alb);
    void setRuta(string r);
};
#endif