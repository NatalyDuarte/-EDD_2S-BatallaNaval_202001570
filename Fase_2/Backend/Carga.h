//importando librerias
#include <iostream>
#include <fstream>
#include <string> 
#include "ListaUsuarios.h"
#include "Carpetas/dist/jsoncpp.cpp"
#include "Carpetas/include/json/json.h"
#include "ColaTutorial.h"
#include "ListaCategoria.h"

using namespace::std;
ListaUsuarios listausu;
ListaCategoria listacate;
ColaTutorial colatuto;

class ListaUsuarios
{
private:
public:
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

};


