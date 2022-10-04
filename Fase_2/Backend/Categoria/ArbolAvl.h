#include <iostream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Compra{
    private:
    public:
    int id;
    int altura;
    string nombre; 
    int cantidad;
    Compra* derecha;
    Compra* izquierda;
    Compra(int id,string nombre, int cantidad){
        this->id = id;
        this->nombre = nombre; 
        this->cantidad = cantidad;
        this->altura = 0;
        this->derecha = NULL;
        this->izquierda = NULL;
    }
    string textoGraphviz(){
        if(derecha==NULL && izquierda==NULL){
            return to_string(id);
        }else{
            string texto = "";
            if(izquierda!=NULL){
                texto += to_string(id)+" ->" + izquierda->textoGraphviz()+ "\n";
            }
            if(derecha!=NULL){
                texto += to_string(id)+" ->" +  derecha->textoGraphviz()+ "\n";
            }
            return texto;
        }
    }
};
class ArbolAvl{
    private: 
        Compra* raiz;
    public:
        ArbolAvl(){
            raiz=NULL;
        }
        Compra* ObtenerRaiz(){
            return raiz;
        }
        Compra* Buscar(int id, Compra* nodo){
            if(raiz==NULL){
                return NULL;
            }else if(nodo->id == id){
                return nodo;
            }else if(nodo->id < id){
                return Buscar(id,nodo->derecha);
            }else{
                return Buscar(id,nodo->izquierda);
            }
        }
        int ObtenerAlt(Compra* nodo){
            if(nodo==NULL){
                return -1;
            }else{
                return nodo->altura;
            }
        }
        Compra* RotaIzqui(Compra* nodo){
            Compra* aux=nodo->izquierda;
            nodo->izquierda=aux->derecha;
            aux->derecha=nodo;
            nodo->altura=max(ObtenerAlt(nodo->izquierda),ObtenerAlt(nodo->derecha))+1;
            aux->altura=max(ObtenerAlt(aux->izquierda),ObtenerAlt(aux->derecha))+1;
            return aux;
        }
        Compra* RotaDere(Compra* nodo){
            Compra* aux=nodo->derecha;
            nodo->derecha=aux->izquierda;
            aux->izquierda=nodo;
            nodo->altura=max(ObtenerAlt(nodo->izquierda),ObtenerAlt(nodo->derecha))+1;
            aux->altura=max(ObtenerAlt(aux->izquierda),ObtenerAlt(aux->derecha))+1;
            return aux;
        }
        Compra* RotaDobleIzq(Compra* nodo){
            Compra* aux;
            nodo->izquierda=RotaDere(nodo->izquierda);
            aux= RotaIzqui(nodo);
            return aux;
        }
        Compra* RotaDobleDere(Compra* nodo){
            Compra* aux;
            nodo->derecha=RotaIzqui(nodo->derecha);
            aux= RotaDere(nodo);
            return aux;
        }
        Compra* InsertarAvl(Compra* nuevo,Compra* subAr) {
            Compra* nuevoPadre = subAr;
            if (nuevo->id < subAr->id) {
                if (subAr->izquierda == NULL) {
                    subAr->izquierda = nuevo;
                } else {
                    subAr->izquierda = InsertarAvl(nuevo, subAr->izquierda);
                    if ((ObtenerAlt(subAr->izquierda) - ObtenerAlt(subAr->derecha )) == 2) {
                        if (nuevo->id < subAr->izquierda->id) {
                            nuevoPadre = RotaIzqui(subAr);
                        } else {
                            nuevoPadre = RotaDobleIzq(subAr);
                        }
                    }
                }
            } else if (nuevo->id > subAr->id) {
                if (subAr->derecha == NULL) {
                    subAr->derecha = nuevo;
                } else {
                    subAr->derecha = InsertarAvl(nuevo, subAr->derecha);
                    if ((ObtenerAlt(subAr->derecha) - ObtenerAlt(subAr->izquierda)) == 2) {
                        if (nuevo->id > subAr->derecha->id) {
                            nuevoPadre = RotaDere(subAr);
                        } else {
                            nuevoPadre = RotaDobleDere(subAr);
                        }
                    }

                }
            } else {
                cout<<"Nodo duplicado"<<endl;
            }
            //acutalizar la altura;
            if (subAr->izquierda == NULL && subAr->derecha != NULL) {
                subAr->altura = subAr->derecha->altura + 1;
            } else if (subAr->derecha == NULL && subAr->izquierda != NULL) {
                subAr->altura = subAr->izquierda->altura + 1;
            } else {
                subAr->altura = max(ObtenerAlt(subAr->izquierda),ObtenerAlt(subAr->derecha)) + 1;
            }
            return nuevoPadre;
        }
        //meotod para insertar
        void Insertar(int dato,string nombre,int cantidad) {
            Compra* nuevo = new Compra(dato,nombre,cantidad);
            if (raiz == NULL) {
                raiz = nuevo;
            } else {
                raiz = this->InsertarAvl(nuevo,raiz);
            }
        }
        //motodo recorridos:
        void PreOrden(Compra* nodo) {
            if (nodo != NULL) {
                cout<<to_string(nodo->id)+" "<<endl;
                PreOrden(nodo->izquierda);
                PreOrden(nodo->derecha);
            }
        }  
        void CrearGrafica(string nombre){
            ofstream file;
            file.open("ArbolAvl.dot");
            string texto;
            texto ="digraph G\n";
            texto +="{\n";
            texto +="      node[shape=circle]\n";
            texto +="      node[style=filled]\n";
            texto +="      node[fillcolor=lightpink]\n";
            texto +="      node[color=black]\n";
            texto +="      edge[color=black]\n";
            texto +="      label="+nombre+"\n";
            texto +="      labelloc=\"t\"\n";
            if (raiz != NULL) {
                texto += raiz->textoGraphviz();
            }
           
            texto+="\n}";
            file << texto;
            file.close();
            //------->generar png
            system(("dot -Tpng ArbolAvl.dot -o  ArbolAvl.png"));
        }  
        

};    
