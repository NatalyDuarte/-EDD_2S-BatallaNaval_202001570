#include <stddef.h>
#include <string>
#include <iostream>
#include "ListaArticulo.h"

using namespace std;

class Categoria{
    //atributos y metodos    
    public:
        string dato;
        Categoria* siguiente;
        Categoria* abajo;
        ListaArticulo lista_cate;
        Categoria(string dato){
            this->dato = dato;
            this->siguiente=NULL;
            this->abajo=NULL;
            lista_cate;
        }
    private:

};