#include <iostream>
#include "PilaMovimientos.h"
#include "MovList.h"

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
        void agregar(string nom);
    private:
        MovList* inicio;
        MovList* fin;
};