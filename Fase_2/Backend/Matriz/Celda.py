class Celda():
    def __init__(self, coordefila, coordecolumna, caracter):
        self.caracter = caracter
        self.coordefila = coordefila 
        self.coordecolumna = coordecolumna
        self.siguien= None
        self.anteri= None
        self.arriba = None
        self.abajo = None
        self.derecha = None
        self.izquierda = None 

    def setFila(self, coordefila):
        self.coordefila = coordefila
    
    def getFila(self):
        return self.coordefila

    def setColum(self, coordecolumna):
        self.coordecolumna = coordecolumna
    
    def getColum(self):
        return self.coordecolumna

    def setCara(self, caracter):
        self.caracter = caracter
    
    def getCaracter(self):
        return self.caracter
       
    def setArriba(self, arriba):
        self.arriba = arriba
    
    def getArriba(self):
        return self.arriba

    def setAbajo(self, abajo):
        self.abajo = abajo
    
    def getAbajo(self):
        return self.abajo

    def setDerecha(self, derecha):
        self.derecha = derecha
    
    def getDerecha(self):
        return self.derecha
    
    def setIzquierda(self, izquierda):
        self.izquierda = izquierda    

    def getIzquierda(self):
        return self.izquierda
    