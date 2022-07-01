from os import read
import tkinter as tk
from tkinter import Label, filedialog 
import matplotlib.pyplot as plt
import numpy as np

#Declaracion de nuevos Objetos
class Operacion:
    def __init__(self,numero,tiempos):
        self.numero=numero
        self.tiempos=tiempos    # Tiempos de ejecucion en c/maquina

class Tarea:
    def __init__(self,numero, op, tiempo):
        self.numero=numero
        self.op=op
        self.tiempo=tiempo  # Tiempo hasta poder hacer otra operacion

    def asignado(self):
        self.op.pop(0)

    def copia(self):
        return Tarea(self.numero, list(self.op), self.tiempo)

class Maquina:
    def __init__(self):
        self.operaciones=[]     # Cola de operaciones en cada maquina
        self.tiempo=0           # Tiempo en el que se desocupa la maquina

    def asignaOperacion(self,tf,job,op):
        self.operaciones.append([self.tiempo,tf,job,op])
        self.tiempo=tf

#Declaracion de nuevas funciones
def asigna(op,job): # Asigna una operacion
    esperas=[]
    for i in range(len(Machine)):
        esperas.append(Machine[i].tiempo+op.tiempos[i])
    minimo=esperas.index(min(esperas))
    Machine[minimo].asignaOperacion(esperas[minimo],job,op.numero)
    return esperas[minimo]

def simul():    # Asigna todas las tareas
    
    Jobs=[]     # Copia de Job
    for i in Job:
        Jobs.append(i.copia())

    # Reinicio de las máquinas
    for i in Machine:
        i.operaciones=[]
        i.tiempo=0

    tiempoTranscurrido=0
    while len(Jobs)!=0:

        # Actualiza los tiempos de ocupacion de las maquinas 
        for i in Machine:
            if tiempoTranscurrido>i.tiempo:
                i.tiempo=tiempoTranscurrido

        for i in range(len(Jobs)): 
            if Jobs[i].tiempo<=tiempoTranscurrido:
                Jobs[i].tiempo=asigna(Jobs[i].op[0],Jobs[i].numero)
                Jobs[i].asignado()      # Quita la operacion asignada
                if len(Jobs[i].op)==0:
                    Jobs.pop(i)         # Quita las tareas sin operaciones
                    break
        tiempoTranscurrido+=1

    reporte()
    Gantt()

def reporte():
    doc.write('\nMaquina\t  Trabajos/Operaciones\t ti\t tf\tTiempo total\n')
    for i in range(len(Machine)):
        doc.write('  M'+str(i+1))
        for j in Machine[i].operaciones:
            doc.write('\t\tO '+str(j[2])+','+str(j[3])+'       \t')
            doc.write(' '+str(j[0])+'\t '+str(j[1])+'\t     '+str(j[1]-j[0])+'\n')

def Gantt():    # Genera el diagrama de Gantt
    colores=['#22ff55','#0055ff','m','#ff0f00','#ffff00','violet','c','pink']   # Posibles colores para los trabajos
    lim=0
    hbar=5
    maquinas=[]

    # Arreglo con los nombres de las máquinas
    for i in range(len(Machine)):
        maquinas.append('M'+str(len(Machine)-i))
        if Machine[i].tiempo>lim:lim=Machine[i].tiempo
    nMaq=len(maquinas)

    fig, gantt =plt.subplots()
    
    # Etiquetas de los ejes
    gantt.set_xlabel('Tiempo')
    gantt.set_ylabel('Máquinas')

    # Limites de los ejes
    gantt.set_xlim(0,lim)
    gantt.set_ylim(0,nMaq*hbar)

    # Lineas horizontales
    gantt.set_yticks(range(hbar,nMaq*hbar,hbar), minor=True)
    gantt.grid(True, axis='y', which='minor')

    # Etiquetas de máquinas
    gantt.set_yticks(np.arange(hbar/2, hbar*nMaq+hbar/2, hbar))
    gantt.set_yticklabels(maquinas)

    # Bloques de cada operacion
    for i in range(len(Machine)):
        for j in Machine[i].operaciones:
            gantt.broken_barh([(j[0],j[1]-j[0])],(hbar*(nMaq-1-i), hbar), facecolors=colores[(j[2]-1)%8])
            gantt.text(x=(j[0]+j[1])/2, y=(hbar*(nMaq-1-i))+hbar/2, s=('O('+str(j[2])+', '+str(j[3])+')'), va='center', ha='center', color='black')
    plt.show()

def menu():
    print('\n\t\t    Menu\n============================================')
    print('1. Cambiar numero de maquinas')
    print('2. Agregar tarea')
    print('3. Agregar operacion')
    print('4. Visualizar datos de entrada')
    print('5. Simular')
    print('6. Salir\n')
    op=int(input('Seleccione una opcion: '))
    while(op<1 or op>6):
        print('\n\t> Error <\n')
        op=int(input('Seleccione una opcion valida: '))
    return op

def info(nMaq):
    for i in range(nMaq):
        Machine.append(Maquina())

    nOp=int(input('\nIntroduzca el numero de operaciones: '))

    for i in range(nOp):
        Op=[]
        print('\nO'+str(i+1))
        for j in range(nMaq):
            Op.append(float(input('t M'+str(j+1)+': ')))
        O.append(Operacion(i+1,Op))
    
    # cadena con formato ''
    nTar=int(input('\nIntroduzca el numero de tareas: '))
    print('\nIntroduzca las operaciones de cada tarea (O1, O2, ..., On)\n')
    for i in range(nTar):
        Tar=input('J'+str(i+1)+': ')
        j=0
        op=[]
        while j<len(Tar):
            if Tar[j]=='O':
                aux=''
                j+=1
                while j<len(Tar) and Tar[j]!=',':
                    aux=aux+Tar[j]
                    j+=1
                op.append(int(aux))
            j+=1
        aux=[]
        for j in op:
            aux.append(O[j-1])
        Job.append(Tarea(i+1,aux,0))

def verDatos():
    aux=''
    for i in range(len(Machine)):
        aux=aux+'\tM'+str(i)
    print('\n\tTiempos de operacion\nOperacion'+aux)
    
    for i in O:
        aux='   O'+str(i.numero)+'    '
        for j in i.tiempos:
            aux=aux+'\t'+str(j)
        print(aux)
    print('\n\t   Tareas')
    for i in Job:
        aux='J'+str(i.numero)+':'
        for j in i.op:
            aux=aux+' O'+str(j.numero)
        print(aux)
        
'''
def browseFiles():  # Cargar archivos
    filename = filedialog.askopenfilename(initialdir = "/", title = "Select a File", filetypes = (("Text files", "*.txt*"), ("all files", "*.*"))) 
    label_file_explorer.configure(text="Docuemnto: "+filename)


# Crear la vista del planificador
root = tk.Tk() 
root.title("Configuracion inicial del Planificacion de Tareas") #Nombre
root.geometry("800x500")
Datos=tk.Frame(root,width=800, height=300)
Datos.pack(side='top')


tk.Label(Datos, text='Elija la configuración inicial del problema', font=('Abadi', 12)).grid(column=0, row=0, padx=15, pady=10)
Maquinas=tk.Frame(Datos)
Maquinas.grid(column=0, row=1)
tk.Label(Maquinas, text='Número de máquinas disponibles:', font=('Abadi', 12)).grid(column=0, row=0, padx=5, sticky='e')
M = tk.StringVar(Maquinas, value='')
numMac = tk.Entry(Maquinas,width=5, textvariable=M)
numMac.grid(column=1, row=0)
numMac.config(justify='center')

Trabajos=tk.Frame(Datos)
Trabajos.grid(column=1, row=1)
tk.Label(Trabajos, text='Número de tareas:', font=('Abadi', 12)).grid(column=0, row=0, padx=5, sticky='e')
J = tk.StringVar(Trabajos, value='')
Job = tk.Entry(Trabajos,width=5, textvariable=J)
Job.grid(column=1, row=0)
Job.config(justify='center')

# Frame distinto para mostrar las máquinas y los timepo de las operaciones
Operaciones=tk.Frame(Datos,width=400,bg='green')
Operaciones.grid(column=0, row=2)

tk.Label(Operaciones, text='Operaciones',font=('Abadi', 10)).grid(row=0, column=0)

Archivos=tk.Frame(root)
Archivos.pack(side='bottom')
tk.Label(Archivos, text='Cargar archivos de configuración',font=('Abadi', 12)).grid(column=0, row=3, padx=10, pady=5, sticky='w')
tk.Button(Archivos, width=40, text="Maquinas disponibles y tiempo de operación",command = browseFiles).grid(column=0, row=4,padx=30)
tk.Button(Archivos, width=40, text="Trabajo a ejecutar y sus operaciones      ",command = browseFiles).grid(column=0, row=5,padx=30) 
tk.Button(Archivos, text="Iniciar simulación", command=lambda: simul()).grid(column=1, row=4,padx=50)

#Usa el command= para poner la clase a la que va a poner a trabajar -> text_"", command= 
label_file_explorer = tk.Label(Archivos, text = "Documento: ", fg = "blue").grid(column = 0, row = 6,pady=10)
root.mainloop()
'''

Machine=[] # Conjunto de máquinas
Job=[] # Conjunto de tareas
O=[] # Conjunto de operaciones con los tiempos de ejecución en c/máquina
doc=open('Reporte de tiempos.txt','w')

print('\nAun no hay ningun dato')
info(int(input('\nIngrese el número de máquinas: ')))
verDatos()

while True:
    op=menu()
    if op==1:   # Cambiar numero de maquinas
        Machine=[]
        Job=[]
        O=[]
        info(int(input('\nNumero de máquinas: ')))

    elif op==2: # Agregar tarea
        print('Introduzca las operaciones de la nueva tarea (O1, O2, ..., On)\n')
        Tar=input('J'+str(len(Job)+1)+': ')
        j=0
        op=[]
        while j<len(Tar):
            if Tar[j]=='O':
                aux=''
                j+=1
                while j<len(Tar) and Tar[j]!=',':
                    aux=aux+Tar[j]
                    j+=1
                op.append(int(aux))
            j+=1
        aux=[]
        for j in op:
            aux.append(O[j-1])
        Job.append(Tarea(len(Job)+1,aux,0))

    elif op==3: # Agregar operacion
        Op=[]
        print('\nO'+str(len(O)+1))
        for j in range(len(Machine)):
            Op.append(float(input('t M'+str(j+1)+': ')))
        O.append(Operacion(len(O)+1,Op))

    elif op==4: # Visualizar datos de entrada
        verDatos()

    elif op==5: # Simular
        simul()

    elif op==6: # Salir
        doc.close()
        print('\nHasta luego :D\n')
        break