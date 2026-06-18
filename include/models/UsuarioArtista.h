#ifndef USUARIOARTISTA_H
#define USUARIOARTISTA_H
#include <string>
using namespace std;

//Creamos la clase UsuarioArtista
class UsuarioArtista {
private:
    int id_usuario;
    int id_artista;
public:
    UsuarioArtista(); //metodo constructor inicial por defecto
    UsuarioArtista(int id_usuario, int id_artista); //Metodo constructor para crear la relacion

    //Getters para leer los atributos de esa clase
    int getIdUsuario();
    int getIdArtista();

    //Setters para cambiar estos atributos.
    void setIdUsuario(int id_usu);
    void setIdArtista(int id_art);
};
#endif