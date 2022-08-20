#include <iostream>
#include "Usuario.h"

using namespace std;

class ListaUsuario{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        ListaUsuario(){
            inicio=NULL;
            fin= NULL;
        }
        //metodos
        //metodo de insertar
        void agregarlista(string nick, string pass,int mon, int edad);
        //metodo de mostrar
        void mostrarlista();
        //metodo verificar usuario
        string verificar(string nick, string pass);
        
    private:
        Usuario* inicio;
        Usuario* fin;
};

