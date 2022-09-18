//importando librerias
#include <iostream>
#include <fstream>
#include <string> 
#include "Usuarios/ListaUsuario.cpp"
#include "Carpetas/dist/jsoncpp.cpp"
#include "Carpetas/include/json/json.h"
#include "Tutorial/ColaTutorial.cpp"
#include "Categoria/ListaCategoria.cpp"

using namespace::std;
ListaUsuario listausu;
ListaCategoria listacate;
ColaTutorial colatuto;
void carga(){
    string dire,nick,pass;
    string mon,edad, id;
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
            id=characters[i]["id"].asString();
            nick=characters[i]["nick"].asString();
            pass=characters[i]["password"].asString();
            mon=characters[i]["monedas"].asString();
            edad=characters[i]["edad"].asString();
            listausu.agregarlista(stoi(id),nick,pass,stoi(mon),stoi(edad));
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

void NuevoUsuario(){
    int id,mon,edad;
    string nick,pass;
    id=listausu.obtener();
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
    listausu.agregarlista(id,nick,pass,mon,edad);
}

