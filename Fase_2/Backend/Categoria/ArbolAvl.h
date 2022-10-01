include <iostream>
#include <string>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Compra {
    int dato,cantidad;
    string nombre;
    Compra* derecha;
    Compra* izquierda;
    Compra* padre;
    public:
    string textoGraphviz() {
        if (izquierda == NULL && derecha == NULL) {
            return to_string(dato);
        } else {
            string texto = "";
            if (izquierda != NULL) {
                texto += dato + "->" + izquierda->textoGraphviz() + "\n";
            }
            if (derecha != NULL) {
                texto += dato + "->" + derecha->textoGraphviz() + "\n";
            }
            return texto;
        }
    }
};
class ArbolAvl{
    private: 
    public:
        //Función para crear un nuevo nodo
        Compra* CrearNodo(int dato,string nombre,int cantidad,Compra* padre) {
            Compra* nuevo = new Compra();
            nuevo->dato = dato;
            nuevo->nombre = nombre;
            nuevo->cantidad = cantidad;
            nuevo->derecha = NULL;
            nuevo->izquierda = NULL;
            nuevo->padre = padre;

            return nuevo;
        }
        //Función para insertar nodos en el árbol
        void Insertar(Compra *&arbol, int dato,string nombre,int cantidad,Compra*padre) {
            if (arbol == NULL) { //Si el arbol está vacío
                Compra *nuevo = CrearNodo(dato,nombre,cantidad,padre);
                arbol = nuevo;
            }
            else { // Si el arbol tiene un nodo o más
                int raiz;
                raiz= arbol->dato; // Obtener valor de la raíz
                if (dato < raiz) {
                    Insertar(arbol->izquierda, dato,nombre,cantidad,arbol);
                }
                else {
                    Insertar(arbol->derecha, dato,nombre,cantidad,arbol);
                }
            }
        }
        //Función para mostrar el arbol
        void MostrarArbol(Compra* arbol, int cont) {
            if (arbol == NULL) {
                return;
            }
            else {
                MostrarArbol(arbol->derecha, cont + 1);
                for (int i = 0; i < cont; i++) {
                    cout <<"    ";
                }
                cout << arbol->dato << endl;
                MostrarArbol(arbol->izquierda, cont + 1);
            }
        }
        // Función para buscar un dato en el arbol
        bool Busqueda(Compra* arbol, int dato) {
            if (arbol == NULL) {
                return false;
            }
            else if (arbol->dato == dato){
                return true;
            }
            else if (dato <arbol->dato) {
                return Busqueda(arbol->izquierda, dato);
            }
            else {
                return Busqueda(arbol->derecha, dato);
            }
        }
        // Funcion para recorrido en profundidad - PreOrden
        void PreOrden(Compra* arbol) {
            if (arbol == NULL) {
                return;
            }
            else {
                cout << arbol->dato << " - ";
                PreOrden(arbol->izquierda);
                PreOrden(arbol->derecha);
            }
        }
        // Funcion para recorrido en profundidad - InOrden
        void InOrden(Compra* arbol) {
            if (arbol == NULL) {
                return;
            }
            else {
                InOrden(arbol->izquierda);
                cout << arbol->dato << " - ";
                InOrden(arbol->derecha);
            }
        }
        // Funcion para recorrido en profundidad - PostOrden
        void PostOrden(Compra* arbol) {
            if (arbol == NULL) {
                return;
            }
            else {
                PostOrden(arbol->izquierda);
                PostOrden(arbol->derecha);
                cout << arbol->dato << " - ";
            }
        }
        // Funcion para eliminar un nodo del arbol
        void Eliminar(Compra* arbol, int n) {
            if (arbol == NULL) {
                return;
            }
            else if (n < arbol->dato) { //Si el valor es menor
                Eliminar(arbol->izquierda, n); // Busca por la izquierda
            }
            else if (n > arbol->dato) { // Si el valor es mayor
                Eliminar(arbol->derecha, n); //Busca por la derecha
            }
            else {
                EliminarNodo(arbol);
            }
        }
        // Funcion para eliminar el nodo encontrado
        void EliminarNodo(Compra* nodoEliminar) {
            if (nodoEliminar->izquierda && nodoEliminar->derecha) {
                Compra* menor = Minimo(nodoEliminar->derecha); // Primero te vas hacia la derecha
                nodoEliminar->dato = menor->dato;
                nodoEliminar->dato = menor->dato;
                EliminarNodo(menor);
            }
            else if (nodoEliminar->izquierda) {
                Reemplazar(nodoEliminar, nodoEliminar->izquierda);
                DestruirNodo(nodoEliminar);
            }
            else if (nodoEliminar->derecha) {
                Reemplazar(nodoEliminar, nodoEliminar->derecha);
                DestruirNodo(nodoEliminar);
            }
            else { // No tiene hijos
                Reemplazar(nodoEliminar, NULL);
                DestruirNodo(nodoEliminar);
            }
        }
        // Función para determinar el nodo más izquierdo posible
        Compra* Minimo(Compra* arbol) {
            if (arbol == NULL) {
                return NULL;
            }
            if (arbol->izquierda) { // Si tiene hijo izquierdo
                return Minimo(arbol->izquierda); // retorna el hijo izquierdo
            }
            else { // Si no tiene hijo izquierdo (significa que él es el más izquierdo)
                return arbol; // se retorna a sí mismo
            }
        }
        // Función para reemplazar dos nodos
        void Reemplazar(Compra* arbol, Compra* nuevoNodo) {
            if (arbol->padre) {
                //arbol->padre hay que asignarle su nuevo hijo
                if (arbol->dato == arbol->padre->izquierda->dato) {
                    arbol->padre->izquierda = nuevoNodo;
                }
                else if (arbol->dato == arbol->padre->derecha->dato) {
                    arbol->padre->derecha = nuevoNodo;
                }
            }
            if (nuevoNodo) {
                // Procedemos a asignarle su nuevo padre
                nuevoNodo->padre = arbol->padre;
            }
        }
        // Función para destruir un nodo
        void DestruirNodo(Compra* nodo) {
            nodo->izquierda = NULL;
            nodo->derecha = NULL;
            delete nodo;
        }
        void graficar(Compra* nodo) {
            string res;
            int raiz;
            ofstream file;
            file.open("ArbolAvl.dot");
            res = "digraph grafica{\nrankdir=TB;\nnode[shape=box, style=filled, fillcolor=lightpink, penwidth=3]\n";
            if (nodo != NULL) {
                int raiz;
                raiz= nodo->dato;
                res+=nodo->textoGraphviz();
            }
            res +="\n}";
            file << res;
            file.close();
            //------->generar png
            system(("dot -Tpng ArbolAvl.dot -o  ArbolAvl.png"));

        }
        
         
};