from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMainWindow, QApplication
from PyQt5.uic import loadUi
import sys
import webbrowser
import Listas
from tkinter import *
from tkinter import filedialog
import json
listausu = Listas.ListaUsuarios()
listacate = Listas.ListaCategoria()
colatuto = Listas.ColaTutorial()

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
            colatuto.insertar(int(ancho),int(alto),"Tablero")
            for tutorial in datos['tutorial']["movimientos"]:
                movix=tutorial["x"]
                moviy=tutorial["y"]
                colatuto.insertar(int(movix),int(moviy),"Movimiento")
    else:
        print("No se reconocio el archivo")
        

    


if __name__ == '__main__':
    app = QtWidgets.QApplication([])
    login = uic.loadUi("Frontend/Paginas/Login.ui")
    admini = uic.loadUi("Frontend/Paginas/Administracion.ui")
    entrar = uic.loadUi("Frontend/Paginas/Bienvenido.ui")
    edita = uic.loadUi("Frontend/Paginas/Editar.ui")
    tienda = uic.loadUi("Frontend/Paginas/Tienda.ui")
    regis = uic.loadUi("Frontend/Paginas/Registro.ui")
    listausu.agregarlista(0,"EDD","edd123",0,50)
    listausu.agregarlista(1,"Javier","edd123",12,12)
    listausu.agregarlista(2,"Pedro","edd123",12,22)
    listausu.agregarlista(3,"Maria","edd123",12,23)
    listausu.agregarlista(4,"Jaan","edd123",12,90)
    login.show()
    login.pushButton.clicked.connect(incio)
    login.pushButton_2.clicked.connect(carga)
    login.pushButton_3.clicked.connect(registr)
    sys.exit(app.exec_())