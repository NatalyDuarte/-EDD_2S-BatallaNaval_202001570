from unittest import result
from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMainWindow, QApplication, QLabel
from PyQt5.uic import loadUi
from PyQt5.QtGui import QIcon, QPixmap
import sys
import webbrowser
import Listas
from tkinter import *
from tkinter import filedialog
import json
from random import randint,random,uniform
from Matriz.MatrizDispersa import Dispersa
listausu = Listas.ListaUsuarios()
listacate = Listas.ListaCategoria()
colatuto = Listas.ColaTutorial()
matriz = Dispersa(0)
arbolb = Listas.ArbolB()
arbolavl = Listas.ArbolAvl()

respu = " " 
nick = " "
passw = " "
ed=0
def editausu():
    global respu
    global passw
    nick = edita.lineEdit.text()
    passw1 = edita.lineEdit_2.text()
    edad = edita.lineEdit_4.text()
    print(respu)
    mon = listausu.obtemonedas(respu,passw)
    listausu.editar(respu,nick,passw1,mon,int(edad))
    

def editar():
    entrar.hide()
    edita.show()
    edita.pushButton.clicked.connect(editausu)
    
    
def geneavl():
    global pre
    nombre = tienda.lineEdit.text()
    id = tienda.lineEdit_3.text()
    cantidad = tienda.lineEdit_2.text() 
   # pre=listacate.getPrecio(int(id))
   # if ed>=pre:
   #     print("Comprado Exitosamente")
    #    ed=ed-pre
    #    edad=listausu.obtedad(respu,passw);
    #    listausu.editar(respu,respu,passw,ed,edad)
    #else:
   #     print("No se puede realizar la compra por falta de tokens")
    arbolavl.Insertar(int(id),str(nombre),int(cantidad))  
    
def cerrartienda():
    tienda.hide()
    entrar.show()

def tiend():
    global respu
    global passw
    global ed
    entrar.hide()
    tienda.show()
    ed=listausu.obtemonedas(respu,passw); 
    
    tienda.label_3.setText("Tokens Disponibles "+str(ed))
    tienda.pushButton_2.clicked.connect(geneavl)
    tienda.pushButton.clicked.connect(cerrartienda)
   
        
    
def agre():
    nick1 = regis.lineEdit.text()
    passw1 = regis.lineEdit_2.text()
    edad1 =  regis.lineEdit_3.text()  
    id1=listausu.obtener()
    listausu.agregarlista(int(id1),nick1,passw1,int("0"),int(edad1)) 
    arbolb.Insertar(int(id1))
    regis.hide()
    login.show()
    
def regre():
    regis.hide()
    login.show()
    
def registr():
    login.hide()
    regis.show()
    regis.pushButton.clicked.connect(agre)
    regis.pushButton_2.clicked.connect(regre) 
    
def elimini():
    global respu
    global arbolb
    listausu.eliminar(respu)
    nick = " "
    passw = " "
    respu = " "
    entrar.hide()
    login.show()
    
def cerra(): 
    nick = ""
    passw = ""
    entrar.hide()
    login.show()
    
def cerraadmi(): 
    nick = ""
    passw = ""
    admini.hide()
    login.show()
    
def ascen():
    admini.plainTextEdit.clear()
    listausu.ordeanamiento()
    dato=listausu.mostrarlista()
    admini.plainTextEdit.insertPlainText(dato)
    
def descen():
    admini.plainTextEdit.clear()
    listausu.ordeanamiento()
    dato=listausu.mostrarlistaF()
    admini.plainTextEdit.insertPlainText(dato)
    
def grafimatri():
    matriz.graficarDispersa()

def grafiarbolb():
    arbolb.Grafo()
    
def grafiarbolavl():
    global respu
    arbolavl.CrearGrafica(respu)
   
def incio():
    global passw
    global nick
    nick = login.lineEdit.text()
    passw = login.lineEdit_2.text()
    if len(nick)==0 or len(passw)==0:
        login.label_5.setText("Ingrese los datos para continuar")
    else:
        global respu
        respu=listausu.verificar(nick,passw)
        if respu=="EDD":
            login.hide()
            admini.show()
            admini.pushButton.clicked.connect(ascen)
            admini.pushButton_2.clicked.connect(descen)
            admini.pushButton_3.clicked.connect(grafiarbolb)
            admini.pushButton_4.clicked.connect(cerraadmi)
            admini.pushButton_5.clicked.connect(grafimatri)
        elif(respu=="None"):
            login.label_5.setText("Datos incorrectos")
        else:
            login.hide()
            entrar.show()
            entrar.pushButton.clicked.connect(editar)
            entrar.pushButton_3.clicked.connect(tiend)
            entrar.pushButton_2.clicked.connect(elimini)
            entrar.pushButton_4.clicked.connect(cerra)
            entrar.pushButton_5.clicked.connect(tiend)
            entrar.pushButton_6.clicked.connect(grafiarbolavl)
            
def portav(a,b):
    res1=matriz.Buscar(a+1,b)
    res2=matriz.Buscar(a+2,b)
    res3=matriz.Buscar(a+3,b)
    if res1=="NO" and res2=="NO" and res3=="NO":
        matriz.addDispersa("P",a,b)
        matriz.addDispersa("P",a+1,b) 
        matriz.addDispersa("P",a+2,b)
        matriz.addDispersa("P",a+3,b)
    elif res1=="SI" and res2=="SI" and res3=="SI":
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a-2,b)
        res3=matriz.Buscar(a-3,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a-1,b) 
            matriz.addDispersa("P",a-2,b)
            matriz.addDispersa("P",a-3,b)
    elif res1=="NO" and res2=="NO" and res3=="SI":
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a-2,b)
        res3=matriz.Buscar(a+1,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a-1,b) 
            matriz.addDispersa("P",a-2,b)
            matriz.addDispersa("P",a+1,b)
    elif res1=="NO" and res2=="SI":
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a+2,b)
        res3=matriz.Buscar(a+1,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a-1,b) 
            matriz.addDispersa("P",a+2,b)
            matriz.addDispersa("P",a+1,b)
    elif res1=="SI" :
        res1=matriz.Buscar(a+1,b)
        res2=matriz.Buscar(a+2,b)
        res3=matriz.Buscar(a+1,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a+1,b) 
            matriz.addDispersa("P",a+2,b)
            matriz.addDispersa("P",a+1,b)
            
def submar(a,b):
    res1=matriz.Buscar(a+1,b)
    res2=matriz.Buscar(a+2,b)
    if res1=="NO" and res2=="NO":
        matriz.addDispersa("S",a,b)
        matriz.addDispersa("S",a+1,b) 
        matriz.addDispersa("S",a+2,b)
    elif res1=="SI" and res2=="SI":
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a-2,b)
        if res1=="NO" and res2=="NO":
            matriz.addDispersa("S",a,b)
            matriz.addDispersa("S",a-1,b) 
            matriz.addDispersa("S",a-2,b)
    elif res1=="NO" and res2=="SI":
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a-2,b)
        if res1=="NO" and res2=="NO":
            matriz.addDispersa("S",a,b)
            matriz.addDispersa("S",a-1,b) 
            matriz.addDispersa("S",a-2,b)
    elif res1=="SI" :
        res1=matriz.Buscar(a+1,b)
        res2=matriz.Buscar(a+2,b)
        if res1=="NO" and res2=="NO":
            matriz.addDispersa("S",a,b)
            matriz.addDispersa("S",a+1,b) 
            matriz.addDispersa("S",a+2,b)
            
def destruct(a,b):
    res1=matriz.Buscar(a+1,b)
    if res1=="NO" :
        matriz.addDispersa("D",a,b)
        matriz.addDispersa("D",a+1,b) 
    elif res1=="SI" :
        res1=matriz.Buscar(a-1,b)
        if res1=="NO":
            matriz.addDispersa("D",a,b)
            matriz.addDispersa("D",a-1,b)

def matri(ancho,alto):  
    if ancho==10:
        porta = 1
        subma = 2
        destruc = 3
        buques =  4
    elif ancho>= 10 and ancho<=20:
        porta = 2
        subma = 4
        destruc = 6
        buques =  8
    else:
        formu=((ancho-1)/10)+1
        porta = int(formu)
        subma = int(formu)* 2
        destruc = int(formu) * 3
        buques = int(formu) * 4
    bus= randint(0,1)
    a=randint(0,ancho-1)
    b=randint(0,alto-1)
    bus=0
    print("Portaaviones :"+str(porta))
    print("Submarino :"+str(subma))
    print("Destructor :"+str(destruc))
    print("Buque :"+str(buques))
    if bus==0:
        res=matriz.Buscar(a,b)
        #insercion de barcos
        if res=="NO":
            #vertical
            #porta
            for i in range(porta):
                portav(a,b)
            #subma
            for i in range(subma):
                submar(a,b)
            #destruc
            for i in range(destruc):
                destruct(a,b)
            #buques
            matriz.addDispersa("B",a,b)
        else:
            a=randint(0,ancho-1)
            b=randint(0,alto-1)
            res=matriz.Buscar(a,b)
            #insercion de barcos
            if res=="NO":
                #vertical
                #porta
                for i in range(porta):
                    portav(a,b)
                #subma
                for i in range(subma):
                    submar(a,b)
                #destruc
                for i in range(destruc):
                    destruct(a,b)
                #buques   
                matriz.addDispersa("B",a,b) 
    else:
        #horizontal
        res=matriz.Buscar(a,b)
                
                         
        
def carga():
    archivo=filedialog.askopenfilename(filetypes=[("Archivos JSON", ".json .JSON")])
    if archivo!="":
        with open(archivo) as file:
            datos = json.load(file)
            for usua in datos['usuarios']:
                id=usua["id"]
                nick=usua["nick"]
                passw=usua["password"]
                mon=usua["monedas"]
                edad=usua["edad"]
                listausu.agregarlista(int(id),nick,passw,int(mon),int(edad))
                arbolb.Insertar(int(id))
            for arti in datos['articulos']:
                cate=arti["categoria"]
                cate1=listacate.getCate(cate)
                if(cate1=="None"):
                    listacate.agregarCate(cate)
                    id=arti["id"]
                    nom=arti["nombre"]
                    src=arti["src"]
                    precio=arti["precio"]
                    listacate.agregarArti(int(id),cate,int(precio),nom,src)
                else:
                    id=arti["id"]
                    nom=arti["nombre"]
                    src=arti["src"]
                    precio=arti["precio"]
                    listacate.agregarArti(int(id),cate1,int(precio),nom,src)
            ancho= datos["tutorial"]["ancho"]
            alto= datos["tutorial"]["alto"]
            if ancho>=10 and alto>=10:
                colatuto.insertar(int(ancho),int(alto),"Tablero")
                for tutorial in datos['tutorial']["movimientos"]:
                    movix=tutorial["x"]
                    moviy=tutorial["y"]
                    colatuto.insertar(int(movix),int(moviy),"Movimiento")
                matri(ancho,alto)
                      
    else:
        print("No se reconocio el archivo")
        

    


if __name__ == '__main__':
    app = QtWidgets.QApplication([])
    #login = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Login.ui")
    #admini = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Administracion.ui")
    #entrar = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Bienvenido.ui")
    #edita = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Editar.ui")
    #tienda = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Tienda.ui")
    #regis = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Registro.ui")
    login = uic.loadUi("Frontend/Paginas/Login.ui")
    admini = uic.loadUi("Frontend/Paginas/Administracion.ui")
    entrar = uic.loadUi("Frontend/Paginas/Bienvenido.ui")
    edita = uic.loadUi("Frontend/Paginas/Editar.ui")
    tienda = uic.loadUi("Frontend/Paginas/Tienda.ui")
    regis = uic.loadUi("Frontend/Paginas/Registro.ui")
    listausu.agregarlista(0,"EDD","edd123",0,50)
    listausu.agregarlista(11,"Nataly","Nataly123",4259,50)
    login.show()
    login.pushButton.clicked.connect(incio)
    login.pushButton_2.clicked.connect(carga)
    login.pushButton_3.clicked.connect(registr)
    sys.exit(app.exec_())