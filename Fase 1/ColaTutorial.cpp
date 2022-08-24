#include <iostream>
#include "ColaTutorial.h"

using namespace std;

void ColaTutorial::insertar(int x, int y,string indi){
    Tutorial* coorde = new Tutorial(x,y,indi);
    if(adelante==NULL){
        adelante = coorde;
		adelante->siguiente = NULL;
		atras = adelante;
    }else{
        atras->siguiente = coorde;
		coorde->siguiente = NULL;
		atras = coorde;

    }

}

void ColaTutorial::eliminar(){
    Tutorial* coorde = adelante;
    Tutorial* eliminado = NULL;
    if(adelante != NULL){
        while(coorde!=NULL){	
            if(coorde == adelante){
                adelante = adelante -> siguiente;
            }else if(coorde == atras){
                eliminado->siguiente = NULL;
                atras = eliminado;
            }else{
                eliminado->siguiente = coorde->siguiente;
            }
            cout << "\n Coordenada Eliminado\n\n";
			eliminado = coorde;
			coorde = coorde->siguiente;
        }
    }else{
		cout << " La cola se encuentra Vacia "<< endl;
	}

}
void ColaTutorial::mostrar(){
    Tutorial* aux=adelante;
    if(adelante!=NULL){
		while(aux!=NULL){
            if (aux->indi=="Tablero"){
                cout<<"Tablero"<<endl;
                cout<<"Ancho: "<< aux->ancho <<endl;
                cout<<"Alto: "<<aux->alto<<endl;
            }else{
                cout<<"Movimientos"<<endl;
                cout<<"[Coordenada X:"<< aux->ancho <<"], [Coordenada Y:"<<aux->alto<<"]."<<endl;
            }
			aux = aux->siguiente;
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}

void ColaTutorial::graficar(){
    int cont = 0;
    int conts = 0;
    Tutorial* aux=adelante;
    string cadena = "";
    ofstream grafico;
    grafico.open("graficaCola.dot", ios::out);
    cadena = cadena +"digraph G {\n";
    cadena = cadena +"node[shape=box fillcolor=\"white:yellow\" style =filled]\n";
    while(aux!=NULL){
        if(aux->indi=="Movimiento"){
            cadena = cadena + "Node"+to_string(cont)+"[label=\"X:"+to_string(aux->ancho) +" Y: "+to_string(aux->alto)+"\"];\n";
        } 
        aux = aux->siguiente;
        cont= cont+1;
    }

    cadena = cadena + "}";
    grafico<<cadena;
    grafico.close();
    system("dot -Tpng graficaCola.dot -o graficaCola.png");
    //os.startfile("grafica.png")
    cout<<"Generada exitosamente"<<endl;
}
