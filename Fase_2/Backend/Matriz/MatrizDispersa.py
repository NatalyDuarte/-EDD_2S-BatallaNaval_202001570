from Cabecera import Cabecera
from ListaCabecera import ListaCabecera
from Celda import Celda
import os
import webbrowser

class Matriz():
    
    def __init__(self):
        self.capa = 0
        self.filas = ListaCabecera('fila')
        self.columnas = ListaCabecera('columna')

    def InsertarMatriz(self,  coordefila, coordecolumna, caracter):
        new = Celda( coordefila, coordecolumna, caracter)
        verfila = self.filas.getCabecera(coordefila)
        vercolumna = self.columnas.getCabecera(coordecolumna)
        if verfila == None: 
            verfila = Cabecera(coordefila)
            self.filas.insertarCabe(verfila)
            #self.filas.imprimirCabecera()
        if vercolumna== None: 
            vercolumna = Cabecera(coordecolumna)
            self.columnas.insertarCabe(vercolumna)
            #self.columnas.imprimirCabecera()
        if verfila.getAcceso() == None: 
            verfila.setAcceso(new)
        else: 
            if new.coordecolumna < verfila.getAcceso().coordecolumna:     
                new.setDerecha(verfila.getAcceso())        
                verfila.getAcceso().setIzquierda(new)
                verfila.setAcceso(new)
            else:
                tmp : Celda = verfila.getAcceso() 
                while tmp != None:                      
                    if new.coordecolumna < tmp.coordecolumna:
                        new.setDerecha(tmp)
                        new.setIzquierda(tmp.getIzquierda())
                        tmp.getIzquierda().setDerecha(new)
                        tmp.setIzquierda(new)
                        break
                    elif new.coordefila == tmp.coordefila and new.coordecolumna == tmp.coordecolumna:
                        break
                    else:
                        if tmp.getDerecha() == None:
                            tmp.setDerecha(new)
                            new.setIzquierda(tmp)
                            break
                        else:
                            tmp = tmp.getDerecha() 
        if vercolumna.getAcceso() == None:  
            vercolumna.setAcceso(new)
        else: 
            if new.coordefila < vercolumna.getAcceso().coordefila:
                new.setAbajo(vercolumna.getAcceso())
                vercolumna.getAcceso().setArriba(new)
                vercolumna.setAcceso(new)
            else:
                tmp2 : Celda = vercolumna.getAcceso()
                while tmp2 != None:
                    if new.coordefila < tmp2.coordefila:
                        new.setAbajo(tmp2)
                        new.setArriba(tmp2.getArriba())
                        tmp2.getArriba().setAbajo(new)
                        tmp2.setArriba(new)
                        break
                    elif new.coordefila == tmp2.coordefila and new.coordecolumna == tmp2.coordecolumna:
                        break
                    else:
                        if tmp2.getAbajo() == None:
                            tmp2.setAbajo(new)
                            new.setArriba(tmp2)
                            break
                        else:
                            tmp2 = tmp2.getAbajo()
    
    def ImprimirFila(self, fila):
        inicio= self.filas.getCabecera(fila)
        if inicio == None:
            print('No existe')
            return None
        tmp = inicio.getAcceso()
        while tmp != None:
            print(tmp.caracter)
            tmp = tmp.getDerecha()

    
    def ImprimirColumna(self, columna):
        inicio = self.columnas.getCabecera(columna)
        if inicio == None:
            print('No existe')
            return None
        tmp= inicio.getAcceso()
        while tmp != None:
            print(tmp.caracter)
            tmp = tmp.getAbajo()

    def Sustitu(self, fila, columna, cade):
        try:
            tmp = self.filas.getCabecera(fila).getAcceso()
            while tmp != None:
                if tmp.coordefila == fila and tmp.coordecolumna == columna:
                    #print("Llego")
                    tmp.caracter = cade
                tmp = tmp.getDerecha()
            return None
        except:
            #print('Coordenada no encontrada')
            return None