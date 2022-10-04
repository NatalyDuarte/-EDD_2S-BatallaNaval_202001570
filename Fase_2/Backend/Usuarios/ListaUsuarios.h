#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "sha256/sha256.cpp"

using namespace std;
SHA256 probando;
class Usuario
{
private:
public:
        string nick, passw; 
        int mon, id, edad;
        Usuario* siguiente;
        Usuario* anterior;
        Usuario(int id, string nick, string passw,int mon, int edad){
            this->id = id;
            this->nick= nick;
            this->passw= passw;
            this->mon= mon;
            this->edad= edad;
            this->siguiente=NULL;
            this->anterior=NULL;
        }
};
class ListaUsuarios
{
private:
    Usuario *inicio;
    Usuario *fin;

public:
        ListaUsuarios(){
            inicio=NULL;
            fin= NULL;
        }
        //metodos
        //metodo de insertar
        void agregarlista(int id, string nick, string passw,int mon, int edad){
            Usuario* usu= new Usuario(id,nick,probando(passw),mon,edad);
            if(inicio == NULL){
                inicio = usu;
                inicio->siguiente = NULL;
                fin = usu;
            }else{
                fin->siguiente = usu;
                usu->siguiente = NULL;
                fin = usu;
            }
        }
        //metodo para obtener id
        int obtener(){
            Usuario *aux = inicio;
            int i = 0;
            if (inicio == NULL){
                i=0;
            }else{
                while (aux != NULL){
                    aux = aux->siguiente;
                    i++;
                }
            }
            return i++;
        }
        //metodo de mostrar lista 
        string mostrarlista(){
            Usuario *aux = inicio;
            int i = 0;
            string dato, dato1;
            if (inicio == NULL){
                return "No hay elementos en la lista." ;
            }else{
                dato="Los Usuarios son: ";
                while (aux != NULL){
                    dato1=dato1+"[id:"+ to_string(aux->id)+"],[nick:"+aux->nick+"], [pass:"+aux->passw+"], [mon:"+ to_string(aux->mon)+ "], [edad:"+to_string(aux->edad)+"].";
                    aux = aux->siguiente;
                    i++;
                }
                return dato+dato1;
            }
        }

        //metodo para ingresar usuario 
        string verificar(string nic, string passw){
            Usuario* aux = inicio;
            bool encontrado = false;
            if(inicio != NULL){
                while(aux != NULL && encontrado != true){
                    if(aux->nick == nic){
                        if (aux->passw ==probando(passw)){
                            return nic;
                        }else{
                            cout << "\n Contrasena incorrecta\n\n";
                            return "Contra"; 
                        }
                        encontrado = true;
                    }
                    aux = aux->siguiente;
                }
                if(!encontrado){
                    cout << "\n Usuario No Encontrado\n\n";
                    return "None";
                }
            }else{
                cout  << "\n La Lista se Encuentra Vacia\n\n";
                return "None";
            }
            return "None";
        }
    
        //metodo de editar
        void editar(string res,string nick, string passw,int mon, int edad){
            Usuario* aux = inicio;
            bool encontrado = false;
            if(inicio!=NULL){
                do{
                    if(aux->nick==res){
                        aux->nick = nick;
                        aux->passw =probando(passw);
                        aux->mon = mon; 
                        aux->edad = edad;
                        encontrado = true;				
                    }
                    aux = aux->siguiente;
                }while(aux!=inicio && encontrado != true);
                
                if(!encontrado){
                    cout << "\n Usuario no Encontrado\n\n";
                }
                
            }else{
                cout << "\n La lista se Encuentra Vacia\n\n";
            }
        }
        //metodo de eliminar 
        void eliminar(string UsuarioBuscado){
            Usuario* actual = inicio;
            Usuario* anterior = NULL;
            bool encontrado = false;
            if(inicio != NULL){    
                while(actual != NULL && encontrado != true){
                    if(actual->nick == UsuarioBuscado){
                        cout << "\n Usuario con el dato " << UsuarioBuscado << " Encontrado\n\n";             
                        if(actual == inicio){
                            inicio = inicio->siguiente;
                        }else if(actual == fin){
                            anterior->siguiente = NULL;
                            fin = anterior;
                        }else{
                            anterior->siguiente = actual->siguiente;
                        }
                        cout << "\n Usuario ELiminado con exito\n\n";
                        encontrado = true;
                    }
                    anterior = actual;
                    actual = actual->siguiente;
                }
                if(!encontrado){
                    cout << "\n Usuario No Encontrado\n\n";
                }
            }else{
                cout  << "\n La Lista se Encuentra Vacia\n\n";
            }
        }
        int obtemonedas(string nic, string passw){
            Usuario* aux = inicio;
            if(inicio!=NULL){
                while (aux!=NULL)
                    {
                        if( aux->nick==nic){
                            if (aux->passw==probando(passw)){
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
        int obtedad(string nic, string passw){
            Usuario* aux = inicio;
            if(inicio!=NULL){
                while (aux!=NULL)
                    {
                        if( aux->nick==nic){
                            if (aux->passw==probando(passw)){
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
        void ordeanamiento(){
            Usuario* actual= inicio;
            Usuario* i =NULL;
            Usuario* j;
            Usuario* temp;
            Usuario* te1;
            bool cambio= false;
            if (inicio !=NULL){
                j=actual->siguiente;
                while(j!=NULL){
                    if(actual->edad > j->edad ){
                       cambio = true;
                       if(i!=NULL){
                        temp=j->siguiente;
                        i->siguiente=j;
                        j->siguiente=actual;
                        actual->siguiente=temp; 
                       }else{
                        te1=j->siguiente;
                        inicio=j;
                        j->siguiente=actual;
                        actual->siguiente=te1;
                       } 
                       i=j;
                       j=actual->siguiente;
                    }else{
                        i=actual;
                        actual=j;
                        j=j->siguiente;
                    }
                }
                
            }
        }  
    
};