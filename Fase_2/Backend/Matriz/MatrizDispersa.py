import os
import webbrowser
from Matriz.ListaCabecera import ListaCabecera
from Matriz.Celda import Celda
from Matriz.Cabecera import Cabecera

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
        
    def Buscar(self, fila, columna):
        res="NO"
        try:
            tmp = self.filas.getCabecera(fila).getAcceso()
            while tmp != None:
                if tmp.coordefila == fila and tmp.coordecolumna == columna:
                    res="SI"
                tmp = tmp.getDerecha()
            return res
        except:
            #print('Coordenada no encontrada')
            return "NO"
        
   
    def graficarNeato(self, nombre):
        contenido = '''digraph G{
    node[shape=box, width=0.7, height=0.7, fontname="Arial", fillcolor="white", style=filled]
    edge[style = "bold"]
    node[label = "capa:''' + str(self.capa) +'''" fillcolor="darkolivegreen1" pos = "-1,1!"]raiz;'''
        contenido += '''label = "{}" \nfontname="Arial Black" \nfontsize="25pt" \n
                    \n'''.format('\nMATRIZ DISPERSA')

        # --graficar nodos ENCABEZADO
        # --graficar nodos fila
        pivote = self.filas.primero
        posx = 0
        while pivote != None:
            contenido += '\n\tnode[label = "F{}" fillcolor="azure3" pos="-1,-{}!" shape=box]x{};'.format(pivote.correlativo, 
            posx, pivote.correlativo)
            pivote = pivote.siguiente
            posx += 1
        pivote = self.filas.primero
        while pivote.siguiente != None:
            contenido += '\n\tx{}->x{};'.format(pivote.correlativo, pivote.siguiente.correlativo)
            contenido += '\n\tx{}->x{}[dir=back];'.format(pivote.correlativo, pivote.siguiente.correlativo)
            pivote = pivote.siguiente
        contenido += '\n\traiz->x{};'.format(self.filas.primero.correlativo)

        # --graficar nodos columna
        pivotey = self.columnas.primero
        posy = 0
        while pivotey != None:
            contenido += '\n\tnode[label = "C{}" fillcolor="azure3" pos = "{},1!" shape=box]y{};'.format(pivotey.correlativo, 
            posy, pivotey.correlativo)
            pivotey = pivotey.siguiente
            posy += 1
        pivotey = self.columnas.primero
        while pivotey.siguiente != None:
            contenido += '\n\ty{}->y{};'.format(pivotey.correlativo, pivotey.siguiente.correlativo)
            contenido += '\n\ty{}->y{}[dir=back];'.format(pivotey.correlativo, pivotey.siguiente.correlativo)
            pivotey = pivotey.siguiente
        contenido += '\n\traiz->y{};'.format(self.columnas.primero.correlativo)

        #ya con las cabeceras graficadas, lo siguiente es los nodos internos, o nodosCelda
        pivote = self.filas.primero
        posx = 0
        while pivote != None:
            pivote_celda : Celda = pivote.acceso
            while pivote_celda != None:
                # --- buscamos posy
                pivotey = self.columnas.primero
                posy_celda = 0
                while pivotey != None:
                    if pivotey.correlativo == pivote_celda.coordenadaY: break
                    posy_celda += 1
                    pivotey = pivotey.siguiente
                if pivote_celda.caracter == '*':
                    contenido += '\n\tnode[label="*" fillcolor="black" pos="{},-{}!" shape=box]i{}_{};'.format( #pos="{},-{}!"
                        posy_celda, posx, pivote_celda.coordenadaX, pivote_celda.coordenadaY
                    )
                else:
                    contenido += '\n\tnode[label=" " fillcolor="white" pos="{},-{}!" shape=box]i{}_{};'.format( # pos="{},-{}!"
                        posy_celda, posx, pivote_celda.coordenadaX, pivote_celda.coordenadaY
                    ) 
                pivote_celda = pivote_celda.derecha
            
            pivote_celda = pivote.acceso
            while pivote_celda != None:
                if pivote_celda.derecha != None:
                    contenido += '\n\ti{}_{}->i{}_{};'.format(pivote_celda.coordenadaX, pivote_celda.coordenadaY,
                    pivote_celda.derecha.coordenadaX, pivote_celda.derecha.coordenadaY)
                    contenido += '\n\ti{}_{}->i{}_{}[dir=back];'.format(pivote_celda.coordenadaX, pivote_celda.coordenadaY,
                    pivote_celda.derecha.coordenadaX, pivote_celda.derecha.coordenadaY)
                pivote_celda = pivote_celda.derecha
        
            contenido += '\n\tx{}->i{}_{};'.format(pivote.correlativo, pivote.acceso.coordenadaX, pivote.acceso.coordenadaY)
            contenido += '\n\tx{}->i{}_{}[dir=back];'.format(pivote.correlativo, pivote.acceso.coordenadaX, pivote.acceso.coordenadaY)
            pivote = pivote.siguiente
            posx += 1
        
        pivote = self.columnas.primero
        while pivote != None:
            pivote_celda : Nodo_Interno = pivote.acceso
            while pivote_celda != None:
                if pivote_celda.abajo != None:
                    contenido += '\n\ti{}_{}->i{}_{};'.format(pivote_celda.coordenadaX, pivote_celda.coordenadaY,
                    pivote_celda.abajo.coordenadaX, pivote_celda.abajo.coordenadaY)
                    contenido += '\n\ti{}_{}->i{}_{}[dir=back];'.format(pivote_celda.coordenadaX, pivote_celda.coordenadaY,
                    pivote_celda.abajo.coordenadaX, pivote_celda.abajo.coordenadaY) 
                pivote_celda = pivote_celda.abajo
            contenido += '\n\ty{}->i{}_{};'.format(pivote.correlativo, pivote.acceso.coordenadaX, pivote.acceso.coordenadaY)
            contenido += '\n\ty{}->i{}_{}[dir=back];'.format(pivote.correlativo, pivote.acceso.coordenadaX, pivote.acceso.coordenadaY)
            pivote = pivote.siguiente
                
        contenido += '\n}'
        #--- se genera DOT y se procede a ecjetuar el comando
        dot = "matriz_{}_dot.txt".format(nombre)
        with open(dot, 'w') as grafo:
            grafo.write(contenido)
        result = "matriz_{}.pdf".format(nombre)
        os.system("neato -Tpdf " + dot + " -o " + result)
        webbrowser.open(result)