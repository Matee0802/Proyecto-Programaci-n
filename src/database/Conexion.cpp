#include "../../include/database/Conexion.h"
#include <iostream>
using namespace std;

Conexion::Conexion(string spotcloud){
    this->spotcloud = spotcloud;
    db = nullptr;
}

bool Conexion::conectar(){
    int resultado =
    sqlite3_open(spotcloud.c_str(),&db);
    if(resultado != SQLITE_OK){
        cout<<"Error al conectar BD"<<endl;
        return false;
    }
    //cout<<"Conexion exitosa"<<endl;
    return true;
}

sqlite3* Conexion::getDB(){
    return db;
}

void Conexion::cerrar(){
    if(db != nullptr){
        sqlite3_close(db);
        db = nullptr;
        //cout<<"Conexion cerrada"<<endl;
    }
}