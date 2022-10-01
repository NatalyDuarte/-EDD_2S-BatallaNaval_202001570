#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
class UsuarioB {
    private:
    public:
        string nick, passw; 
        int mon, id, edad;
        //Apuntadores dentro de la rama
        UsuarioB* siguiente;
        UsuarioB* anterior;

        //apuntadores al inicio de otra rama
        UsuarioB* derecha;
        UsuarioB* izquierda;

        UsuarioB(int id, string nick, strinf passw, int mon, int edad) {
            id = id;
            nick = nick;
            passw = passw; 
            mon = mon; 
            edad = edad;
            siguiente = NULL;
            anterior = NULL;
            derecha = NULL;
            izquierda = NULL;
        }
};
class ArbolB {
    public:
        int orden_arbol = 4;
        UsuarioB* raiz;

        ArbolB() {
            raiz = NULL;
        }
        void insertar(int id,string nick, string passw, int mon, int edad){
            UsuarioB* nodo = new UsuarioB(id,nick,passw,mon,edad);
            if (raiz == NULL) {
                raiz = nodo;
            } else {
                pair < UsuarioB*, pair<bool, bool>> ret = insertarCrearRama(nodo, raiz);
                UsuarioB* obj = ret.first;
                if ((ret.second.first or ret.second.second) and obj != NULL) {//si se divide la rama o se inserta al inicio, la raiz cambia
                    cout << "se cambia de rama principal ID:" << obj->id << "\n";
                    raiz = obj;
                }
            }
        }
        pair<UsuarioB*, pair<bool, bool>> insertarCrearRama(UsuarioB* nodo, UsuarioB* rama) {
            pair < UsuarioB*, pair<bool, bool>> ResultadoRama;
            ResultadoRama.first = NULL; //nodo Inicial de la rama
            ResultadoRama.second.first = false; //indica si se dividio la rama
            ResultadoRama.second.second = false; //indica si se modifica el inicio de la rama
            if (esHoja(rama)) {//si el nodo es hoja se inseta directamente dentro de ella
                pair < UsuarioB*, bool> resultado = insertarEnRama(rama, nodo); //insertamos el nuevo elemento dentro de la rama actual
                ResultadoRama.first = resultado.first; //posee la rama con el valor ya insertado
                ResultadoRama.second.second = resultado.second; //posee el resultado de si se modifico el inicio en el insert anterior
                if (contador(resultado.first) == orden_arbol) {//si la rama posee mas elementos de los permitidos se divide
                    cout << "La rama debe dividirse\n";
                    ResultadoRama.first = dividir(resultado.first); //dividimos la rama y obtenemos una nueva rama con sus respectivos apuntadores
                    ResultadoRama.second.first = true; //identificar que la rama se dividio
                }
            } else {//si el nodo es rama se debe buscar la posicion donde insertarlo
                UsuarioB*temp = rama;
                do {
                    if (nodo->id == temp->id) {//valor ya insertado, no se permiten repeditos
                        cout << "insertarCrearRama(), El ID " << nodo->id << " ya existe\n";
                        return ResultadoRama;
                    } else if (nodo->id < temp->id) {
                        pair < UsuarioB*, pair<bool, bool>> ResultadoInsert = insertarCrearRama(nodo, temp->izquierda);
                        if (ResultadoInsert.second.second and ResultadoInsert.first != NULL) {//si se modifico el inicio de la rama
                            ResultadoRama.second.second = true;
                            temp->izquierda = ResultadoInsert.first;
                        }
                        if (ResultadoInsert.second.first) {//se dividio la subrama
                            pair < UsuarioB*, bool> auxInsert = insertarEnRama(rama, ResultadoInsert.first);
                            rama = auxInsert.first;
                            if (auxInsert.second) {
                                ResultadoRama.first = rama;
                            }
                            if (contador(rama) == orden_arbol) {
                                ResultadoRama.first = dividir(rama);
                                ResultadoRama.second.first = true;
                            }
                        }
                        return ResultadoRama;
                    } else if (temp->siguiente == NULL) {
                        pair < UsuarioB*, pair<bool, bool>> ResultadoInsert = insertarCrearRama(nodo, temp->derecha);
                        if (ResultadoInsert.second.second and ResultadoInsert.first != NULL) {//si se modifico el inicio de la rama
                            ResultadoRama.second.second = true;
                            temp->derecha = ResultadoInsert.first;
                        }
                        if (ResultadoInsert.second.first) {//se dividio la subrama
                            pair < UsuarioB*, bool> auxInsert = insertarEnRama(rama, ResultadoInsert.first);
                            rama = auxInsert.first;
                            if (auxInsert.second) {
                                ResultadoRama.first = rama;
                            }
                            if (contador(rama) == orden_arbol) {
                                ResultadoRama.first = dividir(rama);
                                ResultadoRama.second.first = true;
                            }
                        }
                        return ResultadoRama;
                    }
                    temp = temp->siguiente;
                } while (temp != NULL);
            }
            return ResultadoRama;
        }
        UsuarioB* dividir(UsuarioB* rama){
            int val = -999;
            UsuarioB* temp = NULL;
            UsuarioB* Nuevito = NULL;
            UsuarioB* aux = rama;

            UsuarioB* rderecha = NULL;
            UsuarioB* rizquierda = NULL;

            int cont = 0;
            while (aux != NULL) {
                cont++;
                //implementacion para dividir unicamente ramas de 4 nodos
                if (cont < 3) {
                    val = aux->id;
                    temp = new UsuarioB(val);
                    temp->izquierda = aux->izquierda;
                    if (cont == 2) {
                        temp->derecha = aux->siguiente->izquierda;
                    } else {
                        temp->derecha = aux->derecha;
                    }
                    rizquierda = insertarEnRama(rizquierda, temp).first;
                } else if (cont == 3) {
                    val = aux->id;
                    Nuevito = new UsuarioB(val);
                } else {
                    val = aux->id;
                    temp = new UsuarioB(val);
                    temp->izquierda = aux->izquierda;
                    temp->derecha = aux->derecha;
                    rderecha = insertarEnRama(rderecha, temp).first;
                }
                aux = aux->siguiente;
            }
            Nuevito->derecha = rderecha;
            Nuevito->izquierda = rizquierda;
            return Nuevito;
        }
        pair<UsuarioB*, bool>  insertarEnRama(UsuarioB* primero, UsuarioB* nuevo) {
            pair < UsuarioB*, bool> ret;
            ret.second = false;
            if (primero == NULL) {
                //primero en la lista
                ret.second = true;
                primero = nuevo;
            } else {
                //recorrer e insertar
                UsuarioB* aux = primero;
                while (aux != NULL) {
                    if (aux->id == nuevo->id) {//------------->ya existe en el arbol
                        cout << "insertarEnRama(), El ID " << nuevo->id << " ya existe\n";
                        break;
                    } else {
                        if (aux->id > nuevo->id) {
                            if (aux == primero) {//------------->insertar al inicio
                                aux->anterior = nuevo;
                                nuevo->siguiente = aux;
                                //ramas del nodo
                                aux->izquierda = nuevo->derecha;
                                nuevo->derecha = NULL;
                                ret.second = true;
                                primero = nuevo;
                                break;
                            } else {//------------->insertar en medio;
                                nuevo->siguiente = aux;
                                //ramas del nodo
                                aux->izquierda = nuevo->derecha;
                                nuevo->derecha = NULL;

                                nuevo->anterior = aux->anterior;
                                aux->anterior->siguiente = nuevo;
                                aux->anterior = nuevo;
                                break;
                            }
                        } else if (aux->siguiente == NULL) {//------------->insertar al final
                            aux->siguiente = nuevo;
                            nuevo->anterior = aux;
                            break;
                        }
                    }
                    aux = aux->siguiente;
                }

            }
            ret.first = primero;

            return ret;
        }
        bool esHoja(UsuarioB* primero){
            UsuarioB* aux = primero;
            while (aux != NULL) {
                cout << "[" << aux->id << "]->";
                if (aux->izquierda != NULL or aux->derecha != NULL) {
                    return false;
                }
                aux = aux->siguiente;
            }
            cout << "Null\n";
            return true;
        }
        int contador(UsuarioB* primero) {
            int contador = 0;
            UsuarioB* aux = primero;
            while (aux != NULL) {
                contador++;
                aux = aux->siguiente;
            }
            return contador;
        }
        void Grafo(){
            string dotFull = "";
            //escribir dot

            dotFull += "digraph G {\n";
            dotFull += "node[shape=record]\n";
            dotFull += "\t\t//Agregar Nodos Rama\n";
            dotFull += GrafoArbolAbb(raiz);
            //agregar conexiones de ramas
            dotFull += "\t\t//Agregar conexiones\n";
            dotFull += GrafoConexionRamas(raiz);

            dotFull += "}";

            //------->escribir archivo
            ofstream file;
            file.open("Pruebas.dot");
            file << dotFull;
            file.close();

            //------->generar png
            system(("dot -Tpng Pruebas.dot -o  Pruebas.png"));

            //------>abrir archivo
            system(("Pruebas.png"));

        }
        string GrafoArbolAbb(UsuarioB*rama) {
            string dot = "";
            if (rama != NULL) {
                //agrear rama actual
                dot += GrafoRamas(rama);
                //agregar las ramas siguientes recursivamente
                UsuarioB*aux = rama;
                while (aux != NULL) {
                    if (aux->izquierda != NULL) {
                        dot += GrafoArbolAbb(aux->izquierda);
                    }
                    if (aux->siguiente == NULL) {
                        if (aux->derecha != NULL) {
                            dot += GrafoArbolAbb(aux->derecha);
                        }
                    }
                    aux = aux->siguiente;
                }
            }
            return dot;
        }
        string GrafoRamas(UsuarioB*rama){
            string dot = "";
            stringstream auxTXT;
            if (rama != NULL) {
                //============================================agregar rama=================================
                UsuarioB*aux = rama;
                auxTXT.str("");
                auxTXT << rama;
                dot = dot + "R" + auxTXT.str() + "[label=\"";
                int r = 1;
                while (aux != NULL) {
                    if (aux->izquierda != NULL) {
                        dot = dot + "<C" + to_string(r) + ">|";
                        r++;
                    }
                    if (aux->siguiente != NULL) {
                        dot = dot + to_string(aux->id) + "|";
                    } else {
                        dot = dot + to_string(aux->id);
                        if (aux->derecha != NULL) {
                            dot = dot + "|<C" + to_string(r) + ">";
                        }
                    }
                    aux = aux->siguiente;
                }
                dot = dot + "\"];\n";
            }
            return dot;
        }
        string GrafoConexionRamas(UsuarioB*rama) {
        string dot = "";
        stringstream auxTXT;
        if (rama != NULL) {
            //============================================agregar rama=================================
            UsuarioB*aux = rama;
            auxTXT << rama;
            string actual = "R" + auxTXT.str();
            int r = 1;
            while (aux != NULL) {
                if (aux->izquierda != NULL) {
                    auxTXT.str("");
                    auxTXT << aux->izquierda;
                    dot += actual + ":C" + to_string(r) + "->" + "R" + auxTXT.str() + ";\n";
                    r++;
                    dot += GrafoConexionRamas(aux->izquierda);
                }
                if (aux->siguiente == NULL) {
                    if (aux->derecha != NULL) {
                        auxTXT.str("");
                        auxTXT << aux->derecha;
                        dot += actual + ":C" + to_string(r) + "->" + "R" + auxTXT.str() + ";\n";
                        r++;
                        dot += GrafoConexionRamas(aux->derecha);
                    }
                }
                aux = aux->siguiente;
            }
        }
        return dot;
    }
    private:

};