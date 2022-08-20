#include <stddef.h>
#include <string>
#include <iostream>
using namespace std;
class Usuario{
    //atributos y metodos
    private: 
        
    public:
        string nick, pass; 
        int mon, edad;
        Usuario* siguiente;
        Usuario* anterior;
        Usuario(string nick, string pass,int mon, int edad){
            this->nick= nick;
            this->pass= pass;
            this->mon= mon;
            this->edad= edad;
        }

};
    
