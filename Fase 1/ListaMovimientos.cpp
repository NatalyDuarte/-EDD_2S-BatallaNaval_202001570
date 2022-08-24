#include <iostream>
#include <string>
#include <sstream>
#include "ListaMovimientos.h"
#include "MovList.h"

using namespace std;
void ListaMovimientos::agregar(string nom){
    MovList* nuevo= new MovList(nom);
    if(inicio == NULL){
        inicio = nuevo;
        fin = nuevo;

}