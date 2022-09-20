#include <stddef.h>
#include <string>
#include <iostream>
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