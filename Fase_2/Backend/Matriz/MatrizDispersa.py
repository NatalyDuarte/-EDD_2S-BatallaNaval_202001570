from os import system
import webbrowser
import sys
class nodoCabecera():
    def __init__(self, id):
        self.id = id
        self.siguiente = None
        self.anterior = None
        self.acceso = None


class nodoSub():
    def __init__(self, dato, ejex, ejey):
        self.dato = dato
        self.valorx = ejex
        self.valory = ejey
        self.izquierda = None
        self.derecha = None
        self.arriba = None
        self.abajo = None
    
class ListaCabecera():
    def __init__(self, tipo):
        self.primero = None
        self.ultimo = None
        self.tipo = tipo
        self.size = 0
    
    def addNodoCabecera(self,nuevo):
        if self.primero == None:
            self.primero = nuevo
            self.ultimo = nuevo
        else:
            if nuevo.id < self.primero.id:
                nuevo.siguiente = self.primero
                self.primero.anterior = nuevo
                self.primero = nuevo
            elif nuevo.id > self.ultimo.id:
                self.ultimo.siguiente = nuevo
                nuevo.anterior = self.ultimo
                self.ultimo = nuevo
            else:
                tmp = self.primero
                while tmp!=None:
                    if nuevo.id < tmp.id:
                        nuevo.siguiente = tmp
                        nuevo.anterior = tmp.anterior
                        tmp.anterior.siguiente = nuevo
                        tmp.anterior = nuevo
                        break
                    elif nuevo.id > tmp.id:
                        tmp = tmp.siguiente
                    else:
                        break;      
        self.size+=1

    def showCabecera(self):
        tmp = self.primero
        while tmp!=None:
            print(self.tipo, tmp.id)
            tmp = tmp.siguiente
      
    def getCabecera(self,id):
        tmp = self.primero
        while tmp!=None:
            if tmp.id == id:
                return tmp
            tmp =tmp.siguiente
        return None
    
class Dispersa():
    def __init__(self, data):
        self.data = data
        self.fila = ListaCabecera("fila")
        self.columna = ListaCabecera("columna")
    

    def addDispersa(self,dato, ejex, ejey):
        nuevo = nodoSub(dato,ejex,ejey)
        nodox = self.fila.getCabecera(ejex)
        nodoy = self.columna.getCabecera(ejey)

        if nodox == None:
            nodox =  nodoCabecera(ejex)
            self.fila.addNodoCabecera(nodox)
        
        if nodoy == None:
            nodoy =  nodoCabecera(ejey)
            self.columna.addNodoCabecera(nodoy)

        if nodox.acceso == None:
            nodox.acceso = nuevo
        else:
            if nuevo.valory < nodox.acceso.valory:
                nuevo.derecha = nodox.acceso
                nodox.acceso.izquierda = nuevo
                nodox.acceso = nuevo
            else:
                tmp = nodox.acceso
                while tmp!=None:
                    if nuevo.valory < tmp.valory:
                        nuevo.derecha = tmp
                        nuevo.izquierda = tmp.izquierda
                        tmp.izquierda.derecha = nuevo
                        tmp.izquierda = nuevo
                        break
                    elif nuevo.valorx == tmp.valorx and nuevo.valory == tmp.valory:
                        break;
                    else:
                        if tmp.derecha == None:
                            tmp.derecha = nuevo
                            nuevo.izquierda = tmp
                            break
                        else:
                            tmp = tmp.derecha
        
        if nodoy.acceso == None:
            nodoy.acceso = nuevo
        else:
            if nuevo.valorx < nodoy.acceso.valorx:
                nuevo.abajo = nodoy.acceso
                nodoy.acceso.arriba = nuevo
                nodoy.acceso = nuevo
            else:
                aux = nodoy.acceso
                while aux!=None:
                    if nuevo.valorx < aux.valorx:
                        nuevo.abajo = aux
                        nuevo.arriba = aux.arriba
                        aux.arriba.abajo = nuevo
                        aux.arriba = nuevo
                        break;
                    elif nuevo.valorx == aux.valorx and nuevo.valory == aux.valory:
                        break
                    else:
                        if aux.abajo == None:
                            aux.abajo = nuevo
                            nuevo.arriba = aux
                            break
                        else:
                            aux = aux.abajo
                            
    def Buscar(self, elex, eley):
        res="NO"
        probando = self.fila.primero 
        probando1 = self.columna.primero 
        while probando != None and probando1 !=None :
            if probando.id == elex and probando1.id == eley:
                res="SI"
            probando = probando.siguiente
            probando1 = probando1.siguiente
        return res
                       

    def graficarDispersa(self):
        dot = 'digraph G{ \nnode[shape=box]'
        dot+= '\nbgcolor=white\nraiz[label = \"   \",color=black, style=filled fillcolor=cornsilk, group=1]\n'
        dot+='label = "Tablero" \n'
        
        filaX = self.fila.primero
        while filaX!=None:
            dot+='F'+str(filaX.id)+'[label="Fila '+str(filaX.id)+'",color=black, style=filled fillcolor=cornsilk,group=1];\n'
            filaX = filaX.siguiente
    
        filaX = self.fila.primero
        while filaX!=None:
            if filaX.siguiente!=None:
                dot+='F'+str(filaX.id)+' -> F'+str(filaX.siguiente.id)+'\n'
                dot+='F'+str(filaX.siguiente.id)+' -> F'+str(filaX.id)+'\n'
            filaX = filaX.siguiente

        columnaY = self.columna.primero
        while columnaY!=None:
            grupo = columnaY.id+1
            dot+='C'+str(columnaY.id)+'[label="Columna '+str(columnaY.id)+'",color=black, style=filled fillcolor=cornsilk,group='+str(grupo)+'];\n'
            columnaY = columnaY.siguiente
        
        count = 0
        columnaY = self.columna.primero
        while columnaY!=None:
            if columnaY.siguiente!=None:
                dot+='C'+str(columnaY.id)+' -> C'+str(columnaY.siguiente.id)+';\n'
                dot+='C'+str(columnaY.siguiente.id)+' -> C'+str(columnaY.id)+';\n'
            
            count+=1
            columnaY = columnaY.siguiente

        filaX = self.fila.primero
        columnaY = self.columna.primero
        dot+= 'raiz -> F'+str(filaX.id)+'\n'
        dot+= 'raiz -> C'+str(columnaY.id)+'\n'
        dot+= '{rank = same; raiz;'
        count = 0
        columnaY = self.columna.primero
        while columnaY!=None:
            dot+="C"+str(columnaY.id)+'; '
            count+=1
            columnaY = columnaY.siguiente
        dot+='}\n'

        aux = self.fila.primero
        aux2 = aux.acceso
        count=0
        while aux!=None:
            count+=1
            while aux2!=None:
                dot+='N'+str(aux2.valorx)+'_'+str(aux2.valory)+'[label="'+aux2.dato +'",color=black, style=filled fillcolor=cadetblue1,group="'+str((aux2.valory+1))+'"];\n'
                aux2 = aux2.derecha
            aux = aux.siguiente
            if aux!=None:
                aux2 = aux.acceso
            
        aux = self.fila.primero
        aux2 = aux.acceso
        count = 0
        while aux!= None:
            rank = '{rank=same;\nF'+str(aux.id)+';\n'
            count =0
            while aux2!=None:
                if count == 0:
                    dot+="F"+str(aux.id)+" -> N"+str(aux2.valorx)+"_"+str(aux2.valory)+";\n"
                    dot+="N"+str(aux2.valorx)+"_"+str(aux2.valory)+" -> F"+str(aux.id)+";\n"
                    count+=1
                
                if aux2.derecha!=None:
                    dot+="N"+str(aux2.valorx)+"_"+str(aux2.valory)+" -> "+"N"+str(aux2.derecha.valorx)+"_"+str(aux2.derecha.valory)+";\n"
                    dot+="N"+str(aux2.derecha.valorx)+"_"+str(aux2.derecha.valory)+" -> "+"N"+str(aux2.valorx)+"_"+str(aux2.valory)+";\n"
                rank+= "N"+str(aux2.valorx)+"_"+str(aux2.valory)+" "
                aux2 = aux2.derecha
            
            aux = aux.siguiente
            if aux!=None:
                aux2 = aux.acceso
            
            dot+= rank+"}\n"
        
        aux = self.columna.primero
        aux2 = aux.acceso
        count = 0
        while aux!=None:
            count = 0
            dot+=""
            while aux2!=None:
                if count == 0:
                    dot+='C'+str(aux.id)+' -> N'+str(aux2.valorx)+'_'+str(aux2.valory)+';\n'
                    dot+='N'+str(aux2.valorx)+'_'+str(aux2.valory)+' -> C'+str(aux.id)+';\n'
                    count+=1
                if aux2.abajo !=None:
                    dot+='N'+str(aux2.abajo.valorx)+'_'+str(aux2.abajo.valory)+' -> '+"N"+str(aux2.valorx)+"_"+str(aux2.valory)+';\n'
                    dot+='N'+str(aux2.valorx)+'_'+str(aux2.valory)+' -> '+"N"+str(aux2.abajo.valorx)+'_'+str(aux2.abajo.valory)+';\n'
                
                aux2 = aux2.abajo
            
            aux = aux.siguiente
            if aux!=None:
                aux2 = aux.acceso
        dot+=" } "
        grafi = open("Matriz"+".dot",'w')
        grafi.write(dot)
        grafi.close()
        system("dot Matriz.dot -Tpng -o Matriz.png")

    