#include <iostream>
#include "ListaUsuario.h"
#include "sha256/sha256.cpp"
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;
SHA256 probando;

void ListaUsuario::agregarlista(string nick, string pass,int mon, int edad){
    Usuario* usu= new Usuario(nick,probando(pass),mon,edad);
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

void ListaUsuario::editar(string res,string nick, string pass,int mon, int edad){
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

int ListaUsuario:: obtemonedas(string nic, string pass){
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

int ListaUsuario:: obtedad(string nic, string pass){
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

void ListaUsuario::ordeascen(){
    Usuario* aux = inicio;
    Usuario* prob=NULL;
    Usuario* apaux=NULL;
    if(inicio!=NULL){
        while(aux!=NULL){
            prob=aux->siguiente;
            while(prob!=NULL){
                if(aux->edad > prob->edad){
                    apaux->nick=aux->nick;
                    apaux->pass=aux->pass;
                    apaux->mon=aux->mon;
                    apaux->edad=aux->edad;

                    aux->nick=prob->nick;
                    aux->pass=prob->pass;
                    aux->mon=prob->mon;
                    aux->edad=prob->edad;

                    prob->nick=apaux->nick;
                    prob->pass=apaux->pass;
                    prob->mon=apaux->mon;
                    prob->edad=apaux->edad;
                }
                prob=prob->siguiente;
            }
            aux=aux->siguiente;
        }
	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

void ListaUsuario::graficadoble(){
        Usuario* aux = inicio;
        int cont = 0;
        string cadena = "";
        ofstream archivo;
        archivo.open("grafica.dot", ios::out);
        cadena = cadena + "digraph G { \n";
        while(aux->siguiente != inicio){
            cadena = cadena + "Node"+to_string(cont)+"[label=\"Nick: "+aux->nick+",Password: "+aux->pass+",Edad: "+to_string(aux->edad)+", Monedas: "+to_string(aux->mon)+"\"];\n";
            if(aux != inicio){
                cadena = cadena + "Node"+to_string(cont-1)+" -> "+"Node"+to_string(cont)+";\n";
                cadena = cadena + "Node"+to_string(cont)+" -> "+"Node"+to_string(cont-1)+";\n";
            }
            cont=cont+1;
            aux = aux->siguiente;
        }
        cadena = cadena + "Node"+to_string(cont)+"[label=\"Nick: "+aux->nick+",Password: "+aux->pass+",Edad: "+to_string(aux->edad)+",Monedas: "+to_string(aux->mon)+"\"];\n";
        cadena = cadena + "Node"+to_string(cont-1)+" -> "+"Node"+to_string(cont)+";\n";
        cadena = cadena + "Node"+to_string(cont)+" -> "+"Node"+to_string(cont-1)+";\n";
        cadena = cadena + "Node"+to_string(cont)+" -> "+"Node"+to_string(0)+";\n";
        cadena = cadena + "Node"+to_string(0)+" -> "+"Node"+to_string(cont)+";\n";
        cadena = cadena + "}";
        archivo<<cadena;
        archivo.close();
        system("dot -Tpng grafica.dot -o grafica.png");
        //startfile("grafica.png");
        cout<<"Generada exitosamente"<<endl;
}
   