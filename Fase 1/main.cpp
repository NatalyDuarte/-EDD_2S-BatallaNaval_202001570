//importando librerias
#include <iostream>
#include <fstream>
#include <string> 
#include "ListaUsuario.cpp"
#include "ListaCategoria.cpp"
#include "dist/jsoncpp.cpp"
#include "include/json/json.h"

using namespace::std;
ListaUsuario listausu;
ListaCategoria listacate;

void carga(){
    string dire,nick,pass;
    string mon,edad;
    string cate,cate1,nom,src,ob,id,precio;
    string texto,data;
    string ancho,alto,movimientos;
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
        const Json::Value& charac = root["tutorial"];
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
        for (int u = 0; u < charac.size(); u++){

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
                listacate.mostrarArti();
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
    inicio();
    return 0;
}

