//importando librerias
#include <iostream>
#include <fstream>
#include <string> 
#include "ListaUsuario.cpp"
#include "ListaCategoria.cpp"
#include "dist/jsoncpp.cpp"
#include "include/json/json.h"

using namespace::std;
using namespace Json;
ListaUsuario listausu;
ListaCategoria listacate;

void carga(){
    string dire;
    //cout<<"Ingrese la ruta de su archivo"<<endl;
    //cin>>dire;
    ifstream file("pruebas.json");
    Json::Reader reader;  
    Json::Value root; 
    reader.parse(file, root);
    std::cout<<root<<std::endl;
    int sia; 
    sia= root.size();   //  Number of root nodes

    /*for (int j = 0; j < size; j++) {
        const Json::Value arrayObj = root[j]["usuarios"];
        for (int i = 0; i < arrayObj.size(); i++) {
            if (arrayObj[i].isMember("nick")) {
                cout << arrayObj[i]["nick"].asString() << endl;
            }
            if (arrayObj[i].isMember("password")) {
                cout << arrayObj[i]["password"].asString() << endl;
            }
            if (arrayObj[i].isMember("monedas")) {
                cout << arrayObj[i]["monedas"].asString() << endl;
            }
            if (arrayObj[i].isMember("edad")) {
                cout << arrayObj[i]["edad"].asString() << endl;
            }
            int m = 0;
        }
    }*/
    
}

void menu1(){
    string nick1, pass1,res1;
    int op;
    string nick2, pass2;
    int mon2, edad2;
    cout<<"============BIENVENIDO==============" <<endl;
    cout<<"Ingresa tu nick:                    " <<endl;
    cin>>nick1;
    cout<<"Ingresa tu password:                " <<endl;
    cin>>pass1;
    res1=listausu.verificar(nick1,pass1);
    if (res1=="None"){
        cout<<"INCORRECTO"<<endl;
    }else{
        do{ 
            cout<<"===================================" <<endl;
            cout<<"|1. Editar informacion            |" <<endl;
            cout<<"|2. Eliminar cuenta               |" <<endl;
            cout<<"|3. Ver tutorial                  |" <<endl;
            cout<<"|4. Ver articulos de la tienda    |" <<endl;
            cout<<"|5. Realizar movimientos          |" <<endl;
            cout<<"|6. Regresar a menu principal     |" <<endl;
            cout<<"===================================" <<endl;
            cout<<"Dijite su opcion: ";
            cin>>op;
            switch(op){
		    case 1:
                cout<<"Ingresa el nuevo nick:                    " <<endl;
                cin>>nick2;
                cout<<"Ingresa la nueva password:                " <<endl;
                cin>>pass2;
                cout<<"Ingresa las monedas:                " <<endl;
                cin>>mon2;
                cout<<"Ingresa la edad:                " <<endl;
                cin>>edad2;
                listausu.editar(res1,nick2,pass2,mon2,edad2);
                listausu.mostrarlista();
                break;
            case 2: 
                listausu.eliminar(res1);
                op=6;
                break;
            case 3:
                break;
            case 4: 
                break; 
            case 5: 
                break;
            case 6: 
                cout<<"Regresando......."<<endl;
                break;
            default:
			    cout << "\n\n Opcion No Valida \n\n";
		    }
        }while (op != 6);
    }
}

void inicio(){
    int opc;
    string nick, pass;
    int mon, edad;
    do
    {      
        cout<<"================MENU===============" <<endl;
        cout<<"|1. Carga Masiva                  |" <<endl;
        cout<<"|2. Registrar Usuario             |" <<endl;
        cout<<"|3. Login                         |" <<endl;
        cout<<"|4. Reportes                      |" <<endl;
        cout<<"|5. Salir                         |" <<endl;
        cout<<"===================================" <<endl;
        cout<<"Dijite su opcion: ";
        cin>>opc;
        switch(opc){
		case 1:
			carga();
			break;
        case 2: 
            cout<<"============BIENVENIDO==============" <<endl;
            cout<<"Ingresa tu nick:                    " <<endl;
            cin>>nick;
            cout<<"Ingresa tu password:                " <<endl;
            cin>>pass;
            cout<<"Ingresa las monedas:                " <<endl;
            cin>>mon;
            cout<<"Ingresa tu edad:                    " <<endl;
            cin>>edad;
            cout<<"Registrado correctamente"<<endl;
            listausu.agregarlista(nick,pass,mon,edad);
            //listausu.mostrarlista();
            break;
        case 3:
            menu1();
            break;
        case 4: 
            cout <<"Llego op4";
            break;
        case 5:
            cout <<"Feliz dia!!";
            break;
        default:
			cout << "\n\n Opcion No Valida \n\n";
		}
    }while (opc != 5);
      
}



int main(int argc, char** argv){
    //El login no agarra
    //listacate.agregarCate("Rock");
    //listacate.mostrarCate();
    //string res;
    //res=listacate.getCate("Rock");
    //cout<<res<<endl;
    inicio();
    return 0;
}

