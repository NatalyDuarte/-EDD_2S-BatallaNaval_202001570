#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

class MovList{
    //atributos y metodos    
    public:
        string dato;
        MovList* siguiente;
        
        MovList(string dato){
            this->dato = dato;
            this->siguiente=NULL;
        }
    private:

};