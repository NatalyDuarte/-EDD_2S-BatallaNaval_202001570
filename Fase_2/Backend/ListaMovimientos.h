#include <stddef.h>
#include <string>
#include <iostream>
#include <sstream>
#include "PilaMovimientos.h"
using namespace std;
class Movimientos{
    //atributos y metodos
    private: 
        
    public:
        int coordeX, coordeY;
        Movimientos* siguiente;
        Movimientos* anterior;
        Movimientos(int coordeX, int coordeY){
            this->coordeX= coordeX;
            this->coordeY= coordeY;
            this->siguiente=NULL;
            this->anterior=NULL;
        }

};
class ListaMovimientos{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        ListaMovimientos(){
            inicio=NULL;
            fin= NULL;
        }
        //metodos
        void agregar(){
            PilaMovimientos* nuevo= new PilaMovimientos();
            if(inicio == NULL){
                inicio = nuevo;
                fin = nuevo;
            }
        }
    private:
        PilaMovimientos* inicio;
        PilaMovimientos* fin;
};