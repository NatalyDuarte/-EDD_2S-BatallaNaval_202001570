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

void ListaCategoria::agregarArti(int id, string categoria,int precio,string nom,string src){
    Categoria* auxcate = cabecera;
    while(auxcate != NULL){
        if(auxcate->dato== categoria){
            Articulo* arti = new Articulo(id, precio, nom,src);
            Articulo *iniciarti = auxcate->abajo;
            auxcate->abajo = arti;
            arti->abajo = iniciarti;
            break;
        }
        auxcate= auxcate->siguiente;
    }
    if (auxcate == NULL){
        cout<<"No se encontro la categoria"<<endl;
    }
}

void ListaCategoria::mostrarArti(){
    Categoria* auxcate = cabecera;
    while(auxcate != NULL){
        Articulo *auxarti = auxcate->abajo;
        while(auxarti!= NULL){
            cout<<"[id: "<<auxarti->id<<"], [Nombre: "<< auxarti->nombre<<"] "<<", [Categoria: "<< auxcate->dato<<"] "<<", [precio: "<< auxarti->precio<<"] "<<endl;
            auxarti = auxarti->abajo;
        }
        auxcate = auxcate->siguiente;
    }
}

int ListaCategoria::getPrecio(int id){
    Categoria* aux = cabecera;
    while (aux!=NULL){
        Articulo *auxarti = aux->abajo;
        while(auxarti!= NULL){
            if(auxarti->id == id){
                return auxarti->precio;
            }
            auxarti = auxarti->abajo;
        }
        aux = aux->siguiente;
    }
    return 0;
}