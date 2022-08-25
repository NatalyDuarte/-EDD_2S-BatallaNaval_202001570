#include <stddef.h>
#include <string>
#include <iostream>
#include "Articulo.h"

using namespace std;

class Categoria{
    //atributos y metodos    
    public:
        string dato;
        Categoria* siguiente;
        Articulo* abajo;
        Categoria(string dato){
            this->dato = dato;
            this->siguiente=NULL;
            abajo;
        }
    private:
};