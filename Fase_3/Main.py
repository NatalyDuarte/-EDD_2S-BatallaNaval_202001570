from unittest import result
from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMainWindow, QApplication, QLabel
from PyQt5.uic import loadUi
from PyQt5.QtGui import QIcon, QPixmap
import sys
import webbrowser
from tkinter import *
from tkinter import filedialog
import json
from random import randint,random,uniform
import Listas
from Matriz.main import MatrizJuego
listausu = Listas.ListaUsuarios()
listacate = Listas.ListaCategoria()
colatuto = Listas.ColaTutorial()
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
    else:
        print("No se reconocio el archivo")

def regre():
    regis.hide()
    login.show()
    
def registr():
    login.hide()
    regis.show()
    regis.pushButton.clicked.connect(agre)
    regis.pushButton_2.clicked.connect(regre) 

def agre():
    nick1 = regis.lineEdit.text()
    passw1 = regis.lineEdit_2.text()
    edad1 =  regis.lineEdit_3.text()  
    id1=listausu.obtener()
    listausu.agregarlista(int(id1),nick1,passw1,int("0"),int(edad1)) 
    regis.hide()
    login.show()
    
def cerra(): 
    nick = ""
    passw = ""
    entrar.hide()
    login.show()    

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
    tienda.pushButton.clicked.connect(cerrartienda)
    
def cerraadmi(): 
    nick = ""
    passw = ""
    admini.hide()
    login.show()

def JuegoInicio():
    juego.hide()
    juego.lineEdit.clear()
    matri.show()
    matri2.show()    

def JuegAmbos():
    global tamano
    juego.pushButton_5.show()
    juego.label_5.show()
    juego.lineEdit.show()
    tamano=juego.lineEdit.text()
    matriz = MatrizJuego(tamano)
    matriz.asignarPorta()
    matriz.asignarSubma()
    matriz.asignarDestru()
    matriz.asignarBuque()
    juego.pushButton_6.clicked.connect(JuegoInicio)
    
def Jueg():
    global tamano
    entrar.hide()
    juego.pushButton_5.hide()
    juego.label_5.hide()
    juego.lineEdit.hide()
    juego.show()
    juego.pushButton_4.clicked.connect(JuegAmbos)
    
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
            admini.pushButton_4.clicked.connect(cerraadmi)
        elif(respu=="None"):
            login.label_5.setText("Datos incorrectos")
        else:
            login.hide()
            entrar.show()
            login.lineEdit.clear()
            login.lineEdit_2.clear()
            entrar.pushButton_3.clicked.connect(tiend)
            entrar.pushButton_4.clicked.connect(cerra)
            entrar.pushButton_5.clicked.connect(Jueg)

if __name__ == '__main__':
    app = QtWidgets.QApplication([])
    login = uic.loadUi("Fase_3/Frontend/Paginas/Login.ui")
    admini = uic.loadUi("Fase_3/Frontend/Paginas/Administracion.ui")
    entrar = uic.loadUi("Fase_3/Frontend/Paginas/Bienvenido.ui")
    tienda = uic.loadUi("Fase_3/Frontend/Paginas/Tienda.ui")
    regis = uic.loadUi("Fase_3/Frontend/Paginas/Registro.ui")
    juego = uic.loadUi("Fase_3/Frontend/Paginas/Juego.ui")
    matri = uic.loadUi("Fase_3/Frontend/Paginas/Matri.ui")
    matri2 = uic.loadUi("Fase_3/Frontend/Paginas/Matri2.ui")
    #login = uic.loadUi("Frontend/Paginas/Login.ui")
    #admini = uic.loadUi("Frontend/Paginas/Administracion.ui")
    #entrar = uic.loadUi("Frontend/Paginas/Bienvenido.ui")
    #edita = uic.loadUi("Frontend/Paginas/Editar.ui")
    #tienda = uic.loadUi("Frontend/Paginas/Tienda.ui")
    #regis = uic.loadUi("Frontend/Paginas/Registro.ui")
    #juego = uic.loadUi("Frontend/Paginas/Juego.ui")
    #matri = uic.loadUi("Frontend/Paginas/Matri.ui")
    #matri2 = uic.loadUi("Frontend/Paginas/Matri2.ui")
    listausu.agregarlista(0,"EDD","edd123",0,50)
    listausu.agregarlista(1,"Nataly","Nataly123",300,22)
    login.show()
    login.pushButton.clicked.connect(incio)
    login.pushButton_2.clicked.connect(carga)
    login.pushButton_3.clicked.connect(registr)
    sys.exit(app.exec_())