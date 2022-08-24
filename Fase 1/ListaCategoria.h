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
        //metodo agregar articulo 
        void agregarArti(int id, string categoria,int precio,string nom,string src);
        //metodo mostrar Articulo
        void mostrarArti();
        //metodo obtener precio articulo 
        int getPrecio(int id);
    private:
        //Articulo* inicio; 
        //Articulo* fin;
};