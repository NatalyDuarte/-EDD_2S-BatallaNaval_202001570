#include <iostream>
#include "ListaUsuario.h"

using namespace std;

void ListaUsuario::agregarlista(string nick, string pass,int mon, int edad){
    Usuario* usu= new Usuario(nick,pass,mon,edad);
    if(inicio == NULL){
        inicio = usu;
        fin = usu; 
        usu -> siguiente = NULL;
        usu -> anterior = NULL;
    }else{
        usu -> siguiente = fin;
        fin -> anterior = usu; 
        fin = fin->anterior;
        fin->anterior=NULL;
    }
}
void ListaUsuario::mostrarlista(){
    Usuario* aux = inicio;
    if(inicio!=NULL){
        while (aux!=NULL)
            {
                cout<<"[nick:"<< aux->nick <<"], [pass:"<<aux->pass<<"], [mon:"<<aux->mon<<"], [edad:"<<aux->edad<<"]."<<endl;
                aux=aux->siguiente;
            }
    }else{
        cout<<"La lista esta vacia \n";
    }     
}
string ListaUsuario:: verificar(string nic, string pass){
    Usuario* aux = inicio;
    if(inicio!=NULL){
        while (aux!=NULL)
            {
                if( aux->nick==nic){
                     if (aux->pass==pass){
                        return nic;
                    }else{
                        cout<<"Contraseña incorrecta"<<endl;
                        return "None";
                    }
                }else{
                    cout<<"No existe el nombre del Usuario"<<endl;
                    return "None";
                }
                aux=aux->siguiente;
            }
    }else{
        cout<<"No existe ese Usuario \n";
        return "None";
    }
    return "None";
}