#include <iostream>
#include "Movimientos.h"

using namespace std;

class PilaMovimientos{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        PilaMovimientos(){
            primero=NULL;
            ultimo=NULL;
        }
        //metodos
        void insertar(int coordeX, int coordeY);
        void mostrar();
    private:
        Movimientos* primero;
        Movimientos* ultimo;
};