#include <iostream>
#include "PilaMovimientos.h"

using namespace std;

void PilaMovimientos::insertar(int coordeX, int coordeY){
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

void PilaMovimientos::mostrar(){
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