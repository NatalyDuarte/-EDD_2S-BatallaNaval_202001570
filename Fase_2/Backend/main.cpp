//importando librerias
#include <iostream>
#include <fstream>
#include <string> 
#include "Usuarios/ListaUsuarios.h"

using namespace::std;

ListaUsuarios listausu;


int main(int argc, char** argv){
    listausu.agregarlista(1,"Nataly","nataly123",0,22);
    listausu.agregarlista(0,"EDD","edd123",0,50);
    listausu.agregarlista(0,"Juanpa","juanpa123",0,21);
    listausu.verificar("EDD","edd123");

    listausu.mostrarlista();
    return 0;
}