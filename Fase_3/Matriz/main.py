from MatrizDispersa import MatrizDispersa
import math
import random
class NodoBarco:
    def __init__(self,xI:int,yI:int,xF:int,yF:int,tipo:str,name:str,tamano:int):
        self.xInicial = xI
        self.xFinal = xF
        self.yInicial = yI
        self.yFinal = yF
        self.tipo = tipo
        self.tamano = tamano
        self.Name = name
        self.nextNode = None
        self.previusNode = None
class ListaBarcos:
    def __init__(self) -> None:
        self.size = 0
        self.root = None
        self.end = None
    
    def insertarBarco(self,xI:int,yI:int,xF:int,yF:int,tipo:str,name:str,tamano:int):
        barco = NodoBarco(xI,yI,xF,yF,tipo,name,tamano)
        self.size+=1
        if(self.root == None):
            self.root = self.end = barco
        else:
            self.end.nextNode = barco
            barco.previusNode = self.end
            self.end = barco
class MatrizJuego:
    def __init__(self,dimesion:int) -> None:
        self.matriz = MatrizDispersa()
        self.dimension = dimesion
        self.portaAviones = 0
        self.subMarinos = 0
        self.destructores = 0
        self.buques = 0
        self.listaBarcos = ListaBarcos()
        self.generarValores()

    def generarValores(self):
        B = ((self.dimension-1)/10)+1
        parteEntera = int(math.modf(B)[1])
        self.portaAviones = parteEntera * 1
        print("la cantidad de porta aviones es " + str(self.portaAviones))
        self.subMarinos = parteEntera * 2
        print("la cantidad de porta submarinos es " + str(self.subMarinos))
        self.destructores = parteEntera * 3
        print("la cantidad de porta destructores es " + str(self.destructores))
        self.buques = parteEntera * 4
        print("la cantidad de porta buques es " + str(self.buques))
    
    def aleatorioNumero(self):
        return random.randint(0,self.dimension-1)
    
    def asignarPorta(self):
        for y in range(0,self.portaAviones):
            while True:
                x = self.aleatorioNumero()
                y = self.aleatorioNumero()
                dirreccion = random.randint(0,1)
                print(dirreccion)
                insertar = self.validarExistencia(x,y,dirreccion,4)
                if insertar:
                    if dirreccion == 0:
                        for i in range(0,4):
                            print(x+i,y,"P")
                            self.matriz.insertar(x+i,y,"P")
                        break
                    elif dirreccion == 1:
                        for i in range(0,4):
                            print(x,y+i,"P")
                            self.matriz.insertar(x,y+i,"P")
                        break

    def asignarSubma(self):
        for y in range(0,self.subMarinos):
            while True:
                x = self.aleatorioNumero()
                y = self.aleatorioNumero()
                dirreccion = random.randint(0,1)
                print(dirreccion)
                insertar = self.validarExistencia(x,y,dirreccion,3)
                if insertar:
                    if dirreccion == 0:
                        for i in range(0,3):
                            print(x+i,y,"S")
                            self.matriz.insertar(x+i,y,"S")
                        break
                    elif dirreccion == 1:
                        for i in range(0,3):
                            print(x,y+i,"S")
                            self.matriz.insertar(x,y+i,"S")
                        break

    def asignarSubma(self):
        for y in range(0,self.subMarinos):
            while True:
                x = self.aleatorioNumero()
                y = self.aleatorioNumero()
                dirreccion = random.randint(0,1)
                print(dirreccion)
                insertar = self.validarExistencia(x,y,dirreccion,3)
                if insertar:
                    if dirreccion == 0:
                        for i in range(0,3):
                            print(x+i,y,"S")
                            self.matriz.insertar(x+i,y,"S")
                        break
                    elif dirreccion == 1:
                        for i in range(0,3):
                            print(x,y+i,"S")
                            self.matriz.insertar(x,y+i,"S")
                        break
    
    def asignarDestru(self):
        for y in range(0,self.destructores):
            while True:
                x = self.aleatorioNumero()
                y = self.aleatorioNumero()
                dirreccion = random.randint(0,1)
                print(dirreccion)
                insertar = self.validarExistencia(x,y,dirreccion,2)
                if insertar:
                    if dirreccion == 0:
                        for i in range(0,2):
                            print(x+i,y,"D")
                            self.matriz.insertar(x+i,y,"D")
                        break
                    elif dirreccion == 1:
                        for i in range(0,2):
                            print(x,y+i,"D")
                            self.matriz.insertar(x,y+i,"D")
                        break

    def asignarBuque(self):
        for y in range(0,self.buques):
            while True:
                x = self.aleatorioNumero()
                y = self.aleatorioNumero()
                dirreccion = random.randint(0,1)
                print(dirreccion)
                insertar = self.validarExistencia(x,y,dirreccion,1)
                if insertar:
                    if dirreccion == 0:
                        for i in range(0,1):
                            print(x+i,y,"B")
                            self.matriz.insertar(x+i,y,"B")
                        break
                    elif dirreccion == 1:
                        for i in range(0,1):
                            print(x,y+i,"B")
                            self.matriz.insertar(x,y+i,"B")
                        break
    
    def validarExistencia(self,x,y,dirreccion,tamano):
        if x< self.dimension and y< self.dimension:
            if dirreccion == 0:
                insertar = False
                for i in range(0,tamano):
                    if x + i < self.dimension:
                        insertar = self.matriz.ubicarCoordenada(x+i,y)
                        if insertar == True:
                            return False
                    else:
                        return False
                if not insertar:
                    return True
            elif dirreccion == 1:
                insertar = False
                for i in range(0,tamano):
                    if y+i < self.dimension:
                        insertar = self.matriz.ubicarCoordenada(x,y+i)
                        if insertar == True:
                            return False
                    else:
                        return False
                if not insertar:
                    return True
        else:
            return False
