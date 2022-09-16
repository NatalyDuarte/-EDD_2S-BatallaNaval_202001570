from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMainWindow, QApplication
from PyQt5.uic import loadUi
import sys
import webbrowser

def editar():
    entrar.hide()
    edita.show()

def tiend():
    entrar.hide()
    tienda.show()    

def incio():
    nick = login.lineEdit.text()
    passw = login.lineEdit_2.text()
    if len(nick)==0 or len(passw)==0:
        login.label_5.setText("Ingrese los datos para continuar")
    else:
        login.hide()
        entrar.show()
        entrar.pushButton.clicked.connect(editar)
        entrar.pushButton_3.clicked.connect(tiend)


if __name__ == '__main__':
    app = QtWidgets.QApplication([])
    login = uic.loadUi("Fase 2\Frontend\Paginas\Login.ui")
    entrar = uic.loadUi("Fase 2\Frontend\Paginas\Bienvenido.ui")
    edita = uic.loadUi("Fase 2\Frontend\Paginas\Editar.ui")
    tienda = uic.loadUi("Fase 2\Frontend\Paginas\Tienda.ui")
    login.show()
    login.pushButton.clicked.connect(incio)
    sys.exit(app.exec_())