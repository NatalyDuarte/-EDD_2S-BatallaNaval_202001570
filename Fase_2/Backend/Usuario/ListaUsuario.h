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
        void agregarlista(int id, string nick, string pass,int mon, int edad);
        //metodo para obtener id
        int obtener();
        //metodo de mostrar
        void mostrarlista();
        //metodo verificar usuario
        string verificar(string nick, string pass);
        //metodo editar informacion
        void editar(string res, string nick,string pass,int mon, int edad);
        //metodo eliminar cuenta
        void eliminar(string res);
        //metodo de encriptar
        string encriptar(string pass);
        //metodo obtener monedas
        int obtemonedas(string res,string pass);
        //metodo obtener edad
        int obtedad(string res,string pass);
        //metodo agregar pila movimientos
        void agregarmovipila();
        //metodo ordenar 
        void ordeascen();
        void ordedescen();
        //graficar
        void graficadoble();
    private:
        Usuario* inicio;
        Usuario* fin;
};

