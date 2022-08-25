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

void ListaCategoria::graficarListas(){
    int cont = 0;
    int conts = 0;
    string cadena = "",cadena2="" ,conexion2="" ,conexion="";

    ofstream grafico;
    grafico.open("graficaListas.dot", ios::out);
    cadena ="digraph G{\nbgcolor = \"none\"\nlabel=\"LISTA ARTICULOS\";\nnode[shape=box, color=black, style=filled fillcolor=cadetblue1]\n";
    conexion ="{rank=same;\n";
    Categoria* aux = cabecera;
    while(aux!=NULL){
        cadena +=" N"+to_string(cont)+"[label=\""+aux->dato +"\", ];\n";
        Articulo* prob=aux->abajo;
        int nu=0;
        if(aux->abajo!=NULL){
            while(prob!=NULL){
                 cadena2 +="n"+to_string(cont+nu)+"[label=\""+prob->nombre+"\",color=black, style=filled fillcolor=cornsilk];\n";
                 if(prob->abajo!=NULL){
                    conexion2 +="n"+to_string(cont+nu)+" -> n"+to_string(cont+nu+1)+";\n";
                 }
                prob=prob->abajo;
                nu++;
            }
            conexion2 = conexion2 +" N"+to_string(cont)+" -> n"+to_string(cont)+"0";
            cadena+=cadena2+"\n"+conexion2+"\n";
            conexion2="";
            cadena2="";
        }
        if(aux->abajo!=NULL){
            conexion+=" N"+to_string(cont)+" -> N"+to_string(cont+1)+"\n"; 
        }else{
            conexion+= cadena +" N"+to_string(cont)+" -> N0";
        }
        aux = aux->siguiente;
        cont++;
    }
    cadena+="\n"+conexion+"}\n";
    cadena+= "}";
    grafico<<cadena;
    grafico.close();
    system("dot -Tpng graficaListas.dot -o graficaListas.png");
    //os.startfile("grafica.png")
    cout<<"Generada exitosamente"<<endl;

        
}

void ListaCategoria::ordenamietno(){
    Categoria* auxcate = cabecera;
    Articulo *auxarti=NULL;
    string nombre, src;
    int id, precio;
    Articulo* aux=NULL;
    while(auxcate != NULL){
        auxarti = auxcate->abajo;
        Articulo* probando=NULL;
        Articulo* aux=NULL;
            while(auxarti!= NULL){
                probando=auxarti->abajo;
                while(probando!=NULL){
                    if(auxarti->precio < probando->precio){
                        nombre=auxarti->nombre;
                        src=auxarti->src;
                        id=auxarti->id;
                        precio = auxarti->precio;
                        aux=auxarti->abajo;


                        auxarti->nombre=probando->nombre;
                        auxarti->id=probando->id;
                        auxarti->src=probando->src;
                        auxarti->precio=probando->precio;

                        probando->nombre=nombre;
                        probando->src=src;
                        probando->id=id;
                        probando->precio=precio;
                        probando->abajo=aux;
                    }
                    probando=probando->abajo;
                }
                auxarti=auxarti->abajo;
            }
        auxcate=auxcate->siguiente;
    }
}