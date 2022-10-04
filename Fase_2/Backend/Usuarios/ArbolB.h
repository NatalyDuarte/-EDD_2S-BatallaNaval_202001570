#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
class Usu {
    private:
    public:
        int id;
        Usu* siguiente;
        Usu* anterior;
        Usu* derecha;
        Usu* izquierda;
        Usu(int valor) {
            id = valor;
            siguiente = NULL;
            anterior = NULL;
            derecha = NULL;
            izquierda = NULL;
        }
};
class ArbolB {
    private:
    public:
        int OrdenAr = 5;
        Usu* raiz;

        ArbolB() {
            raiz = NULL;
        }
        void Insertar(int id) {
            Usu* nodo = new Usu(id);
            if (raiz == NULL) {
                raiz = nodo;
            } else {
                pair < Usu*, pair<bool, bool>> ret = InsertarRama(nodo, raiz);
                Usu* obj = ret.first;
                if ((ret.second.first or ret.second.second) and obj != NULL) {
                    raiz = obj;
                }
            }
        }
        pair<Usu*, pair<bool, bool>> InsertarRama(Usu* nodo, Usu* rama) {
            pair < Usu*, pair<bool, bool>> ResultadoRama;
            ResultadoRama.first = NULL; 
            ResultadoRama.second.first = false;
            ResultadoRama.second.second = false;
            if (Hoja(rama)) {
                pair < Usu*, bool> resultado = InsertarInRama(rama, nodo); 
                ResultadoRama.first = resultado.first;
                ResultadoRama.second.second = resultado.second; 
                if (Conta(resultado.first) == OrdenAr) {
                    ResultadoRama.first = Divi(resultado.first);
                    ResultadoRama.second.first = true; 
                }
            } else {
                Usu*temp = rama;
                do {
                    if (nodo->id == temp->id) {
                        return ResultadoRama;
                    } else if (nodo->id < temp->id) {
                        pair < Usu*, pair<bool, bool>> ResultadoInsert = InsertarRama(nodo, temp->izquierda);
                        if (ResultadoInsert.second.second and ResultadoInsert.first != NULL) {
                            ResultadoRama.second.second = true;
                            temp->izquierda = ResultadoInsert.first;
                        }
                        if (ResultadoInsert.second.first) {
                            pair < Usu*, bool> auxInsert = InsertarInRama(rama, ResultadoInsert.first);
                            rama = auxInsert.first;
                            if (auxInsert.second) {
                                ResultadoRama.first = rama;
                            }
                            if (Conta(rama) == OrdenAr) {
                                ResultadoRama.first = Divi(rama);
                                ResultadoRama.second.first = true;
                            }
                        }
                        return ResultadoRama;
                    } else if (temp->siguiente == NULL) {
                        pair < Usu*, pair<bool, bool>> ResultadoInsert = InsertarRama(nodo, temp->derecha);
                        if (ResultadoInsert.second.second and ResultadoInsert.first != NULL) {
                            ResultadoRama.second.second = true;
                            temp->derecha = ResultadoInsert.first;
                        }
                        if (ResultadoInsert.second.first) {
                            pair < Usu*, bool> auxInsert = InsertarInRama(rama, ResultadoInsert.first);
                            rama = auxInsert.first;
                            if (auxInsert.second) {
                                ResultadoRama.first = rama;
                            }
                            if (Conta(rama) == OrdenAr) {
                                ResultadoRama.first = Divi(rama);
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

        Usu* Divi(Usu* rama) {
            int val = -999;
            Usu*temp = NULL;
            Usu*Nuevito = NULL;
            Usu*aux = rama;

            Usu*rderecha = NULL;
            Usu*rizquierda = NULL;

            int cont = 0;
            while (aux != NULL) {
                cont++;
                if (cont < 3) {
                    val = aux->id;
                    temp = new Usu(val);
                    temp->izquierda = aux->izquierda;
                    if (cont == 2) {
                        temp->derecha = aux->siguiente->izquierda;
                    } else {
                        temp->derecha = aux->derecha;
                    }
                    rizquierda = InsertarInRama(rizquierda, temp).first;
                } else if (cont == 3) {
                    val = aux->id;
                    Nuevito = new Usu(val);
                } else {
                    val = aux->id;
                    temp = new Usu(val);
                    temp->izquierda = aux->izquierda;
                    temp->derecha = aux->derecha;
                    rderecha = InsertarInRama(rderecha, temp).first;
                }
                aux = aux->siguiente;
            }
            Nuevito->derecha = rderecha;
            Nuevito->izquierda = rizquierda;
            return Nuevito;
        }
        pair<Usu*, bool> InsertarInRama(Usu* primero, Usu* nuevo) {
            pair < Usu*, bool> ret;
            ret.second = false;
            if (primero == NULL) {
                ret.second = true;
                primero = nuevo;
            } else {
                Usu* aux = primero;
                while (aux != NULL) {
                    if (aux->id == nuevo->id) {
                        break;
                    } else {
                        if (aux->id > nuevo->id) {
                            if (aux == primero) {
                                aux->anterior = nuevo;
                                nuevo->siguiente = aux;
                                aux->izquierda = nuevo->derecha;
                                nuevo->derecha = NULL;
                                ret.second = true;
                                primero = nuevo;
                                break;
                            } else {
                                nuevo->siguiente = aux;
                                aux->izquierda = nuevo->derecha;
                                nuevo->derecha = NULL;
                                nuevo->anterior = aux->anterior;
                                aux->anterior->siguiente = nuevo;
                                aux->anterior = nuevo;
                                break;
                            }
                        } else if (aux->siguiente == NULL) {
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

        bool Hoja(Usu* primero) {
            Usu* aux = primero;
            while (aux != NULL) {
                if (aux->izquierda != NULL or aux->derecha != NULL) {
                    return false;
                }
                aux = aux->siguiente;
            }
            return true;
        }

        int Conta(Usu* primero) {
            int contador = 0;
            Usu* aux = primero;
            while (aux != NULL) {
                contador++;
                aux = aux->siguiente;
            }
            return contador;
        }

        void Grafo() {
            string texto = "";
            texto += "digraph G {\n";
            texto += "     node[shape=record]\n";
            texto +="      node[style=filled]\n";
            texto +="      node[fillcolor=lightpink]\n";
            texto +="      node[color=black]\n";
            texto +="      edge[color=black]\n";
            texto +="      label=Arbol_Id_de_Usuasrios\n";
            texto +="      labelloc=\"t\"\n";
            texto += GrafoArb(raiz);
            texto += ConeRamas(raiz);
            texto += "}";
            ofstream file;
            file.open("ArbolB.dot");
            file << texto;
            file.close();
            system(("dot -Tpng ArbolB.dot -o  ArbolB.png"));
            system(("ArbolB.png"));
        }

        string GrafoArb(Usu* rama) {
            string dot = "";
            if (rama != NULL) {
                dot += Ramitas(rama);
                Usu*aux = rama;
                while (aux != NULL) {
                    if (aux->izquierda != NULL) {
                        dot += GrafoArb(aux->izquierda);
                    }
                    if (aux->siguiente == NULL) {
                        if (aux->derecha != NULL) {
                            dot += GrafoArb(aux->derecha);
                        }
                    }
                    aux = aux->siguiente;
                }
            }
            return dot;
        }

        string Ramitas(Usu*rama) {
            string dot = "";
            stringstream auxTXT;
            if (rama != NULL) {
                Usu*aux = rama;
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

        string ConeRamas(Usu*rama) {
            string dot = "";
            stringstream auxTXT;
            if (rama != NULL) {
                Usu*aux = rama;
                auxTXT << rama;
                string actual = "R" + auxTXT.str();
                int r = 1;
                while (aux != NULL) {
                    if (aux->izquierda != NULL) {
                        auxTXT.str("");
                        auxTXT << aux->izquierda;
                        dot += actual + ":C" + to_string(r) + "->" + "R" + auxTXT.str() + ";\n";
                        r++;
                        dot += ConeRamas(aux->izquierda);
                    }
                    if (aux->siguiente == NULL) {
                        if (aux->derecha != NULL) {
                            auxTXT.str("");
                            auxTXT << aux->derecha;
                            dot += actual + ":C" + to_string(r) + "->" + "R" + auxTXT.str() + ";\n";
                            r++;
                            dot += ConeRamas(aux->derecha);
                        }
                    }
                    aux = aux->siguiente;
                }
            }
            return dot;
        }
};