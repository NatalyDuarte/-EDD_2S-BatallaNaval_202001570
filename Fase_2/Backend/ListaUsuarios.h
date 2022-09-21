#include <iostream>
#include "sha256/sha256.cpp"
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;
class Usuario
{
private:
public:
        string nick, pass; 
        int mon, id, edad;
        Usuario* siguiente;
        Usuario* anterior;
        Usuario(int id, string nick, string pass,int mon, int edad){
            this->id = id;
            this->nick= nick;
            this->pass= pass;
            this->mon= mon;
            this->edad= edad;
            this->siguiente=NULL;
            this->anterior=NULL;
        }
};
class ListaUsuarios
{
private:
    Usuario* inicio;
    Usuario* fin;

public:
        ListaUsuarios(){
            inicio=NULL;
            fin= NULL;
        }
        //metodos
        //metodo de insertar
        void agregarlista(int id, string nick, string pass,int mon, int edad){
            Usuario* usu= new Usuario(id,nick,probando(pass),mon,edad);
            if(inicio == NULL){
                inicio = usu; 
                inicio -> siguiente = inicio;
                fin = inicio;
            }else{
                fin -> siguiente = usu;
                usu->siguiente = inicio;
                fin = usu;
            }
        }
        //metodo para obtener id
        int obtener(){
            Usuario* aux = inicio;
            int id=0;
            if(inicio!=NULL){
                do{
                    id++;
                    aux=aux->siguiente;
                }while(aux!=inicio);	
            }else{
                cout << "\n La lista se Encuentra Vacia\n\n";
            }
            id++;
            return id; 
        }
        //metodo de mostrar
        void mostrarlista(){
            Usuario* aux = inicio;
            if(inicio!=NULL){
                do{
                    //cout << "\n " << aux->nick;
                    cout<<"[id:"<< aux->id <<"], [nick:"<< aux->nick <<"], [pass:"<<aux->pass<<"], [mon:"<<aux->mon<<"], [edad:"<<aux->edad<<"]."<<endl;
                    aux=aux->siguiente;
                }while(aux!=inicio);	
            }else{
                cout << "\n La lista se Encuentra Vacia\n\n";
            }
        }
        //metodo verificar usuario
        string verificar(string nick, string pass){
            Usuario* aux = inicio;
            if(inicio!=NULL){
                while (aux!=NULL)
                    {
                        if( aux->nick==nic){
                            if (aux->pass==probando(pass)){
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
        //metodo editar informacion
        void editar(string res, string nick,string pass,int mon, int edad){
            Usuario* aux = inicio;
            bool encontrado = false;
            if(inicio!=NULL){
                do{
                    if(aux->nick==res){
                        aux->nick = nick;
                        aux->pass =probando(pass);
                        aux->mon = mon; 
                        aux->edad = edad;
                        encontrado = true;				
                    }
                    aux = aux->siguiente;
                }while(aux!=inicio && encontrado != true);
                
                if(!encontrado){
                    cout << "\n Nodo no Encontrado\n\n";
                }
                
            }else{
                cout << "\n La lista se Encuentra Vacia\n\n";
            }
        }
        //metodo eliminar cuenta
        void eliminar(string res){
            Usuario* aux = inicio;
            Usuario* aux1 = NULL;
            bool encontrado = false;
            if(inicio!=NULL){
                do{		
                    if(aux->nick==res){
                        if(aux==inicio){
                            inicio = inicio->siguiente;
                            inicio->anterior = fin;
                            fin->siguiente=inicio;
                        }else if(aux==fin){
                            fin= fin->anterior;
                            inicio->anterior = fin;
                            fin->siguiente=inicio;
                        }else{;
                            aux1->siguiente = aux->siguiente;
                            aux->siguiente->anterior=aux1;
                        }			
                        cout << "\n Usuario Eliminado\n\n";
                        encontrado = true;				
                    }	
                    aux1 = aux;
                    aux = aux->siguiente;
                }while(aux!=inicio && encontrado != true);	
                if(!encontrado){
                    cout << "\n Usuario no Encontrado\n\n";
                }
            }else{
                cout << "\n La lista se Encuentra Vacia\n\n";
            }
        }
        
        //metodo obtener monedas
        int obtemonedas(string res,string pass){
            Usuario* aux = inicio;
            if(inicio!=NULL){
                while (aux!=NULL)
                    {
                        if( aux->nick==nic){
                            if (aux->pass==probando(pass)){
                                return aux->mon;
                            }else{
                                cout<<"Contraseña incorrecta"<<endl;
                            }
                        }else{
                            cout<<"No existe el nombre del Usuario"<<endl;
                        }
                        aux=aux->siguiente;
                    }
            }else{
                cout<<"No existe ese Usuario \n";
            }
            return 0;
        }
        //metodo obtener edad
        int obtedad(string res,string pass){
            Usuario* aux = inicio;
            if(inicio!=NULL){
                while (aux!=NULL)
                    {
                        if( aux->nick==nic){
                            if (aux->pass==probando(pass)){
                                return aux->edad;
                            }else{
                                cout<<"Contraseña incorrecta"<<endl;
                            }
                        }else{
                            cout<<"No existe el nombre del Usuario"<<endl;
                        }
                        aux=aux->siguiente;
                    }
            }else{
                cout<<"No existe ese Usuario \n";
            }
            return 0;
        }
};