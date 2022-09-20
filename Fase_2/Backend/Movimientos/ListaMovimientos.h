#include <iostream>
#include "PilaMovimientos.h"

using namespace std;

class ListaMovimientos{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        ListaMovimientos(){
            inicio=NULL;
            fin= NULL;
        }
        //metodos
        void agregar();
    private:
        PilaMovimientos* inicio;
        PilaMovimientos* fin;
};