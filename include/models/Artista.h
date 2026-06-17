#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
using namespace std;

//Creamos la clase Artista
class Artista {
private:
    int id_artista;
    string nombre;
    string biografia_corta;
    string genero;
public:
    Artista();//metodo constructor inicial por defecto
    Artista(string nombre, string biografia, string genero);//Metodo constructor para crear un artista

    //Getters para leer los atributos de esa clase
    int getId();
    string getNombre();
    string getBio();
    string getGenero();

    //Setters para cambiar estos atributos.
    void setId(int id);
    void setNombre(string n);
    void setBio(string b);
    void setGenero(string g);
};
#endif