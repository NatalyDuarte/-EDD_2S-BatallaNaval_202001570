#include <iostream>
#include "Articulo.h"

using namespace std;

class ListaArticulo{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        ListaArticulo(){
            inicio=NULL;
            fin= NULL;
        }
    private:
        Articulo* inicio; 
        Articulo* fin;
};