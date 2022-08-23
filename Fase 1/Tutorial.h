#include <stddef.h>
#include <string>
#include <iostream>
using namespace std;
class Tutorial{
    //atributos y metodos
    public:
        int ancho, alto;
        Tutorial* siguiente;
        Tutorial* anterior;
        //constructor
        Tutorial(){
            ancho = 0;
            alto = 0;
            siguiente = NULL;
            
        }

    private:
};