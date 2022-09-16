#include <stddef.h>
#include <string>
#include <iostream>
#include "Tutorial.h"
using namespace std;
class ColaTutorial{
    public:
    ColaTutorial(){
        adelante=NULL;
        atras=NULL;
    } 
    //metodos
    void insertar(int x, int y,string indi);
    //void buscar();
    //void modificar();
    void eliminar();
    void mostrar();
    //graficar
    void graficar();
    private:
    Tutorial* adelante;
    Tutorial* atras;
};
