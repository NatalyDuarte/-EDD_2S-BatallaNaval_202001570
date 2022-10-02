class ListaCabecera():
    
    def __init__(self, tipo):
        self.primero = None
        self.ultimo = None
        self.tipo = tipo
        self.size = 0
   
    def insertarCabe(self, nuevo):
        self.size += 1
        if self.primero == None:
            self.primero = nuevo
            self.ultimo = nuevo
        else:
            if nuevo.correlativo < self.primero.correlativo:
                nuevo.siguiente = self.primero
                self.primero.anterior = nuevo
                self.primero = nuevo
            elif nuevo.correlativo > self.ultimo.correlativo:
                self.ultimo.siguiente = nuevo
                nuevo.anterior = self.ultimo
                self.ultimo = nuevo
            else:
                tmp = self.primero
                while tmp != None:
                    if nuevo.correlativo < tmp.correlativo:
                        nuevo.siguiente = tmp
                        nuevo.anterior = tmp.anterior
                        tmp.anterior.siguiente = nuevo
                        tmp.anterior = nuevo
                        break
                    elif nuevo.correlativo > tmp.correlativo:
                        tmp = tmp.siguiente
                    else:
                        break
  
    def imprimirCabecera(self):
        tmp = self.primero
        while tmp != None:
            print('Cabecera', self.tipo, tmp.correlativo)
            tmp = tmp.siguiente
            
    def getCabecera(self, id): 
        tmp = self.primero
        while tmp != None:
            if id == tmp.correlativo:
                return tmp
            tmp = tmp.siguiente
        return None