#include <stddef.h>
#include <string>
#include <iostream>
using namespace std;
class Tutorial{
    //atributos y metodos
    public:
        int ancho, alto;
        string indi;
        Tutorial* siguiente;
        //constructor
        Tutorial(int ancho, int alto,string indi){
            this->alto = alto;
            this->ancho = ancho;
            this->indi = indi;
            this->siguiente = NULL; 
        }
    private:
};
