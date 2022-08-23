#include <iostream>
#include "ListaUsuario.h"
#include "sha256/sha256.h"

using namespace std;

void ListaUsuario::agregarlista(string nick, string pass,int mon, int edad){
    Usuario* usu= new Usuario(nick,encriptar(pass),mon,edad);
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
void ListaUsuario::mostrarlista(){
    Usuario* aux = inicio;
	if(inicio!=NULL){
		do{
            //cout << "\n " << aux->nick;
            cout<<"[nick:"<< aux->nick <<"], [pass:"<<aux->pass<<"], [mon:"<<aux->mon<<"], [edad:"<<aux->edad<<"]."<<endl;
            aux=aux->siguiente;
		}while(aux!=inicio);	
	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
       
}
string ListaUsuario:: verificar(string nic, string pass){
    Usuario* aux = inicio;
    if(inicio!=NULL){
        while (aux!=NULL)
            {
                if( aux->nick==nic){
                     if (aux->pass==encriptar(pass)){
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

void ListaUsuario::editar(string res,string nick, string pass,int mon, int edad){
    Usuario* aux = inicio;
	bool encontrado = false;
	if(inicio!=NULL){
		do{
            if(aux->nick==res){
                aux->nick = nick;
                aux->pass = encriptar(pass);
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

void ListaUsuario::eliminar(string res){
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

string ListaUsuario::encriptar(string pass){
    SHA256 sha256;
    string contraencrip = sha256(pass);
    return contraencrip;
}