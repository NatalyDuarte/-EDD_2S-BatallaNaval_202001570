from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMainWindow, QApplication
from PyQt5.uic import loadUi
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

respu = ""
nick= ""
passw= ""
respu = ""

def editar():
    entrar.hide()
    edita.show()
    nick = login.lineEdit.text()
    passw = login.lineEdit_2.text()
    edad =  login.lineEdit_4.text()  
    listausu.editar(respu,nick,passw,int(edad))

def tiend():
    entrar.hide()
    tienda.show() 
    listaca.canti()
    
    
def agre():
    nick1 = regis.lineEdit.text()
    passw1 = regis.lineEdit_2.text()
    edad1 =  regis.lineEdit_3.text()  
    id1=listausu.obtener()
    listausu.agregarlista(int(id1),nick1,passw1,int("0"),int(edad1)) 
    listausu.mostrarlista()
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
    listausu.eliminar(respu)
    nick = ""
    passw = ""
    respu = ""
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
   

def incio():
    matriz.graficarDispersa()
    nick = login.lineEdit.text()
    passw = login.lineEdit_2.text()
    if len(nick)==0 or len(passw)==0:
        login.label_5.setText("Ingrese los datos para continuar")
    else:
        respu=listausu.verificar(nick,passw)
        print(respu)
        if respu=="EDD":
            login.hide()
            admini.show()
            admini.pushButton.clicked.connect(ascen)
            admini.pushButton_2.clicked.connect(descen)
            admini.pushButton_4.clicked.connect(cerraadmi)
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
            
def portav(a,b):
    res1=matriz.Buscar(a+1,b)
    res2=matriz.Buscar(a+2,b)
    res3=matriz.Buscar(a+3,b)
    if res1=="NO" and res2=="NO" and res3=="NO":
        print("Llego1")
        matriz.addDispersa("P",a,b)
        matriz.addDispersa("P",a+1,b) 
        matriz.addDispersa("P",a+2,b)
        matriz.addDispersa("P",a+3,b)
    elif res1=="SI" and res2=="SI" and res3=="SI":
        print("Llego2")
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a-2,b)
        res3=matriz.Buscar(a-3,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            print("Llego3")
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a-1,b) 
            matriz.addDispersa("P",a-2,b)
            matriz.addDispersa("P",a-3,b)
    elif res1=="NO" and res2=="NO" and res3=="SI":
        print("Llego4")
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a-2,b)
        res3=matriz.Buscar(a+1,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            print("Llego5")
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a-1,b) 
            matriz.addDispersa("P",a-2,b)
            matriz.addDispersa("P",a+1,b)
    elif res1=="NO" and res2=="SI":
        print("Llego6")
        res1=matriz.Buscar(a-1,b)
        res2=matriz.Buscar(a+2,b)
        res3=matriz.Buscar(a+1,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            print("Llego7")
            matriz.addDispersa("P",a,b)
            matriz.addDispersa("P",a-1,b) 
            matriz.addDispersa("P",a+2,b)
            matriz.addDispersa("P",a+1,b)
    elif res1=="SI" :
        print("Llego9")
        res1=matriz.Buscar(a+1,b)
        res2=matriz.Buscar(a+2,b)
        res3=matriz.Buscar(a+1,b)
        if res1=="NO" and res2=="NO" and res3=="NO":
            print("Llego8")
            matriz.addDispersa(a,b)
            matriz.addDispersa(a+1,b) 
            matriz.addDispersa(a+2,b)
            matriz.addDispersa(a+1,b)

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
    if bus==0:
        res=matriz.Buscar(a,b)
        #insercion de barcos
        if res=="NO":
            #vertical
            #porta
            for i in range(porta):
                portav(a,b)
            #subma
            #destruc
            #buques
        else:
            a=randint(0,ancho-1)
            b=randint(0,alto-1)
            res=matriz.Buscar(a,b)
            #insercion de barcos
            if res=="NO":
                #vertical
                #porta
                for i in porta:
                    portav(a,b)
                #subma
                #destruc
                #buques    
    else:
        #horizontal
        res=matriz.Buscar(a,b)
                
                         
        
def carga():
    archivo=filedialog.askopenfilename(filetypes=[("Archivos JSON", ".json .JSON")])
    print(archivo)
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
    login = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Login.ui")
    admini = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Administracion.ui")
    entrar = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Bienvenido.ui")
    edita = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Editar.ui")
    tienda = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Tienda.ui")
    regis = uic.loadUi("Fase_2/Backend/Frontend/Paginas/Registro.ui")
    listausu.agregarlista(0,"EDD","edd123",0,50)
    login.show()
    login.pushButton.clicked.connect(incio)
    login.pushButton_2.clicked.connect(carga)
    login.pushButton_3.clicked.connect(registr)
    sys.exit(app.exec_())