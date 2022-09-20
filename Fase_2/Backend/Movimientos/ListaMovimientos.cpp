#include <iostream>
#include <string>
#include <sstream>
#include "ListaMovimientos.h"

using namespace std;
void ListaMovimientos::agregar(){
    PilaMovimientos* nuevo= new PilaMovimientos();
    if(inicio == NULL){
        inicio = nuevo;
        fin = nuevo;
    }
}
