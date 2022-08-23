#include <iostream>
#include <string>
#include <sstream>
#include "ListaCategoria.h"

using namespace std;

void ListaCategoria::agregarCate(string dato){
    Categoria* temporal = new Categoria(dato);
    temporal->siguiente = cabecera;
    cabecera = temporal;
}

void ListaCategoria::mostrarCate(){
    Categoria* aux = cabecera;
    if(cabecera!=NULL){
        while (aux!=NULL)
            {
                cout<<"[categoria:"<< aux->dato<<"] "<<endl;
                aux=aux->siguiente;
            }
    }else{
        cout<<"La lista de categorias esta vacia \n";
    }     
}

string ListaCategoria::getCate(string dato){
    Categoria* aux = cabecera;
    while (aux!=NULL){
        if(aux->dato == dato){
            return aux->dato;
        }
        aux = aux->siguiente;
    }
    return "None";
}