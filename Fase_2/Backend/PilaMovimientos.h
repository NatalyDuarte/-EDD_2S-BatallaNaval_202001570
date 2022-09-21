#include <iostream>
#include "Movimientos.h"
#include <fstream>

using namespace std;

class PilaMovimientos{
    //metodos y atributos
    public:
        //inicializamos o su constructor
        PilaMovimientos(){
            primero=NULL;
            ultimo=NULL;
        }
        //metodos
        void insertar(int coordeX, int coordeY){
            Movimientos* nuevo = new Movimientos(coordeX,coordeY);
            if (primero==NULL){
                primero = nuevo;
                ultimo = nuevo;
            }else{
                nuevo->anterior=ultimo;
                ultimo->siguiente=nuevo;
                ultimo=nuevo;

            }
        }
        void mostrar(){
            Movimientos* actual = primero;
            if(primero!=NULL){
                while(actual!=NULL){
                    cout<<"[X:"<< actual->coordeX <<"], [Y:"<<actual->coordeY<<"]."<<endl; 
                    actual = actual->siguiente;
                }
            }else{
                cout << endl << " La Pila se encuentra vacia" << endl << endl;
            }
        }
        void graficar(){
            Movimientos* actual = primero;
            int cont = 0;
            string cadena = "";
            ofstream file;
            file.open("graficaPila.dot", ios::out);
            cadena = cadena + "graph G { \n";
            if(primero!=NULL){
                while(actual!=NULL){
                    cadena = cadena + "Node"+to_string(cont)+"[label=\""+to_string(actual->coordeX )+" -> "+to_string(actual->coordeY )+"\"];\n";
                    if(actual!=primero){
                        cadena = cadena + "Node"+to_string(cont-1)+" -- "+"Node"+to_string(cont)+";\n";
                    }
                actual=actual->siguiente;
                cont+=1;
                }
                cadena = cadena + "}";
                file<<cadena;
                file.close();
                system("dot -Tpng graficaPila.dot -o graficaPila.png");
            }else{
                cout << endl << " La Pila se encuentra vacia" << endl << endl;
            }
        }
    private:
        Movimientos* primero;
        Movimientos* ultimo;
};