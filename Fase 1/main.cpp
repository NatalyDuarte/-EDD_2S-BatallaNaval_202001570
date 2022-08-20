//importando librerias
#include <iostream>
//#include "ListaUsuario.cpp"
//#include "ListaCategoria.cpp"

using namespace std;
//ListaUsuario listausu;
//ListaCategoria listacate;
void inicio(){
    int opc;
    while (true)
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
        if (opc >= 1 and opc <= 5){
            break;
        }else if (opc<=6)
        {
            cout<<"Esta opcion no existe!!"<<endl;
        }
    }
    if(opc==1){
        cout <<"Llego op1";
    }else if(opc==2){
        string nick, pass;
        int mon, edad;
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
        //listausu.agregarlista(nick,pass,mon,edad);
        //listausu.mostrarlista();
    }else if(opc==3){
        string nick, pass;
        cout<<"============BIENVENIDO==============" <<endl;
        cout<<"Ingresa tu nick:                    " <<endl;
        cin>>nick;
        cout<<"Ingresa tu password:                " <<endl;
        cin>>pass;
        //string res;
        //res=listausu.verificar(nick,pass);
        /*if (res=="None"){
            cout<<"INCORRECTO";
        }else{
            int op;
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
        }*/
        
    }else if(opc==4){
        cout <<"Llego op4";
    }else if(opc==5){
        cout <<"Feliz dia!!";
    }else{
        cout<<"Algo no esta bien";
    }
      
}
int main(int argc, char** argv){
    //El login no agarra
    //listacate.agregarCate("Rock");
    //listacate.mostrarCate();
    //string res;
    //res=listacate.getCate("Rock");
    //cout<<res<<endl;
    //listausu.agregarlista("natu","pas12",150, 22);
    //listausu.mostrarlista();
    inicio();
    return 0;
}

