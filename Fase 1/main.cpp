//importando librerias
#include <iostream>
#include <fstream>
#include <string> 
#include "ListaUsuario.cpp"
#include "ListaCategoria.cpp"
#include "dist/jsoncpp.cpp"
#include "include/json/json.h"
#include "ColaTutorial.cpp"

using namespace::std;
ListaUsuario listausu;
ListaCategoria listacate;
ColaTutorial colatuto;

void carga(){
    string dire,nick,pass;
    string mon,edad;
    string cate,cate1,nom,src,ob,id,precio;
    string texto,data;
    string ancho,alto,movix,moviy;
    cout<<"Ingrese la ruta de su archivo"<<endl;
    cin>>dire;
    ifstream prue;
    prue.open(dire,ios::in);
    if (prue.fail())
    {
        cout << "Error al abrir el archivo";
        exit(1);
    }
    try
    {
        while (!prue.eof())
        {
            getline(prue, data);
            texto = texto + data + "\n";
        }
        prue.close();
        Json::Value root; 
        Json::Reader reader;  
        reader.parse(texto, root);
        const Json::Value& characters = root["usuarios"];
        const Json::Value& chara = root["articulos"];
        const Json::Value& tuto = root["tutorial"]["movimientos"];
        //const Json::Value& chari = root["movimientos"];
        for (int i = 0; i < characters.size(); i++){
            nick=characters[i]["nick"].asString();
            pass=characters[i]["password"].asString();
            mon=characters[i]["monedas"].asString();
            edad=characters[i]["edad"].asString();
            listausu.agregarlista(nick,pass,stoi(mon),stoi(edad));
        }
        for (int o = 0; o < chara.size(); o++){
            cate=chara[o]["categoria"].asString();
            cate1=listacate.getCate(cate);
            if(cate1=="None"){
                listacate.agregarCate(cate);
                id=chara[o]["id"].asString();
                nom=chara[o]["nombre"].asString();
                src=chara[o]["src"].asString();
                precio=chara[o]["precio"].asString();
                listacate.agregarArti(stoi(id),cate,stod(precio),nom,src);
            }else{
                id=chara[o]["id"].asString();
                nom=chara[o]["nombre"].asString();
                src=chara[o]["src"].asString();
                precio=chara[o]["precio"].asString();
                listacate.agregarArti(stoi(id),cate1,stod(precio),nom,src);
            }
        }
        ancho= root["tutorial"]["ancho"].asString();
        alto= root["tutorial"]["alto"].asString();
        colatuto.insertar(stoi(ancho),stoi(alto),"Tablero");
        for (int u = 0; u < tuto.size(); u++){
                movix=tuto[u]["x"].asString();
                moviy=tuto[u]["y"].asString();
                colatuto.insertar(stoi(movix),stoi(moviy),"Movimiento");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

}

void menu1(){
    string nick1, pass1,res1;
    int op;
    string nick2, pass2;
    int mon2, edad2;
    int id,mon,pre;
    int edad;
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
                colatuto.mostrar();
                break;
            case 4: 
                mon=listausu.obtemonedas(res1,pass1);
                cout<<"Total tokens: "<<mon<<endl;
                listacate.mostrarArti();
                cout<<"Elija opcion para comprar: "<<endl;
                cin>>id;
                pre=listacate.getPrecio(id);
                if( mon>=pre){
                    cout<<"Comprado exitosamente"<<endl;
                    mon=mon-pre;
                    edad=listausu.obtedad(res1,pass1);
                    listausu.editar(res1,res1,pass1,mon,edad);
                }else{
                    cout<<"No se puede realizar la compra por falta de tokens"<<endl;
                }
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

void grafica(){
    int opc;
    string res;
    do
    {      
        cout<<"====================0====GRAFICAS=====================" <<endl;
        cout<<"|1. Lista doblemente enlazada circular (Usuarios)    |" <<endl;
        cout<<"|2. Lista de listas (Articulos)                      |" <<endl;
        cout<<"|3. Cola de movimientos (Tutorial)                   |" <<endl;
        cout<<"|4. Lista de pilas (Listado de jugadas)              |" <<endl;
        cout<<"|5. Regresar a menu                                  |" <<endl;
        cout<<"======================================================" <<endl;
        cout<<"Dijite su opcion: ";
        cin>>opc;
        switch(opc){
		case 1:
            listausu.graficadoble();
			break;
        case 2: 
            listacate.graficarListas();
            break;
        case 3:
            colatuto.graficar();
            break;
        case 4: 
            cout<<"Regresando...."<<endl;
            break;
        case 5: 
            cout<<"Regresando...."<<endl;
            break;
        default:
			cout << "\n\n Opcion No Valida \n\n";
		}
    }while (opc != 5);

}
void reportes(){
    int opc;
    string res;
    do
    {      
        cout<<"==============REPORTES===============" <<endl;
        cout<<"|1. Graficas                        |" <<endl;
        cout<<"|2. Listado de usuarios             |" <<endl;
        cout<<"|3. Listado de articulos            |" <<endl;
        cout<<"|4. Regresar a menu                 |" <<endl;
        cout<<"=====================================" <<endl;
        cout<<"Dijite su opcion: ";
        cin>>opc;
        switch(opc){
		case 1:
            grafica();
			break;
        case 2: 
            cout<<"Si desea ordenarlos ascendentemente ingre [A] y descendente [D]"<<endl;
            cin>>res;
            if(res=="A"){
                listausu.ordeascen();
                //listausu.mostrarlista();
            }else if (res=="D"){
                cout<<"Llego";
            }else{
                cout<<"Letra invalida"<<endl;
            }

            break;
        case 3:
            menu1();
            break;
        case 4: 
            cout<<"Regresando...."<<endl;
            break;
        default:
			cout << "\n\n Opcion No Valida \n\n";
		}
    }while (opc != 4);

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
            reportes();
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
    inicio();
    return 0;
}

