#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

class Articulo{
    //atributos y metodos
    private: 
        
    public:
        string nombre, src; 
        int id, precio;
        Articulo* abajo;
        Articulo(int id, int precio,string nombre, string src){
            this->id= id;
            this->precio= precio;
            this->nombre= nombre;
            this->src= src;
            this->abajo=NULL;
        }

};