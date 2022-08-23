#include <iostream>
#include "Categoria.h"

using namespace std;

class ListaCategoria{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        Categoria* inicio;
        Categoria* fin;
        Categoria* cabecera;
        ListaCategoria(){
            cabecera = NULL;
            //inicio=NULL;
            //fin= NULL;
        }
        //metodos
        //metodo de insertar
        void agregarCate(string dato);
        //metodo de mostrar categoria
        void mostrarCate();
        //metodo obtener categoria
        string getCate(string dato);
    private:
        //Articulo* inicio; 
        //Articulo* fin;
};