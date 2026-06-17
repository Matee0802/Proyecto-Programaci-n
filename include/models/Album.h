#ifndef ALBUM_H
#define ALBUM_H
#include <string>
using namespace std;

//Creamos la clase Album
class Album {
private:
    int id_album;
    string titulo;
    int anio;
    int id_artista;
    string ruta_portada;
    int id_usuario;
public:
    Album();//metodo constructor inicial por defecto
    Album(string titulo, int anio, int id_artista, string ruta_portada, int id_usuario);//Metodo constructor para crear un artista

    //Getters para leer los atributos de esa clase
    int getIdAlbum();
    string getTitulo();
    int getAnio();
    int getIdArtista();
    string getRutaPortada();
    int getIdUsuario();

    //Setters para cambiar estos atributos.
    void setIdAlbum(int id);
    void setTitulo(string t);
    void setAnio(int a);
    void setIdArtista(int id_art);
    void setRutaPortada(string r);
    void setIdUsuario(int id_usu);
};
#endif