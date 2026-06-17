#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

//Creamos la clase Usuario
class Usuario {
private:
    int id_usuario;
    string nombre;
    string correo;
    string password;
public:
    Usuario();//metodo constructor inicial por defecto
    Usuario(string nombre, string correo, string password);//Metodo constructor para crear usuario
    
    //Getters para leer los atributos de esa clase
    int getId();
    string getNombre();
    string getCorreo();
    string getPassword();


    //Setters para cambiar estos atributos.
    void setId(int id);
    void setNombre(string n);
    void setCorreo(string c);
    void setPassword(string p);
};
#endif