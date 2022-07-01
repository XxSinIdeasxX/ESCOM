from tkinter import *
import tkinter as tk
from tkinter import filedialog 

PRES = Tk() #Crear la vista de presentación
PRES.wm_title("Presentación") #Nombre
PRES.geometry("800x500")
PRES.config(background = "#5D9B9B")
ETitulo = tk.Label(PRES, text="PROYECTO FINAL\n", font=("Times", 40, "italic"), bg="#5D9B9B").pack()
ENOMBRE = tk.Label(PRES, text="PLANITIFACIÓN DE TAREAS\n", font=("Arial", 25),bg="#5D9B9B").pack()
materia = tk.Label(PRES, text="Análisis y Diseño de Algoritmos\n", font=("Arial", 25),bg="#5D9B9B").pack()
Label(PRES, text="Caballero Perdomo Axel Lennyn", font=("Times", 20),bg="#5D9B9B").pack()
Label(PRES, text="Rodrígez Calderón Fernando", font=("Times", 20),bg="#5D9B9B").pack()
Label(PRES, text="Santos Mendoza Ana Paola\n",font=("Times", 20),bg="#5D9B9B").pack()
button = tk.Button(text = "Siguiente", command = PRES.destroy,font=("Times", 12)).pack()#Boton para pasar a la siguiente pestaña
PRES.mainloop()

def newWindow():
    SIMU = Tk() #Crear la vista
    SIMU.wm_title("Planificación de Tareas") #Nombre
    SIMU.geometry("900x600")
    SIMU.config(background = "#CDCDCD")
    Agre = Button(SIMU, text="Agregar tarea").grid(column=0, row=0) 
    Time = Button(SIMU, text="Visualizar tiempos de ejecución").grid(column=4, row=0) 
    
def browseFiles(): 
    filename = filedialog.askopenfilename(initialdir = "/", title = "Select a File", filetypes = (("Text files", "*.txt*"), ("all files", "*.*"))) 
    label_file_explorer.configure(text="Docuemnto: "+filename)
           

Trabajo = Tk() #Crear la vista
Trabajo.wm_title("Planificación de Tareas") #Nombre
Trabajo.geometry("900x600")
Trabajo.config(background = "#CDCDCD")
M = StringVar(Trabajo, value='')
J = StringVar(Trabajo, value='')
Label(Trabajo, text="Elija la configuración inicial del problema c:",font=("Times", 20),bg="#CDCDCD").grid(row=0, column=0)
Label(Trabajo, text="Número de máquinas disponibles:",font=("Arial", 15),bg="#CDCDCD").grid(row=1, column=0, padx=10, pady=2)
Mac = Entry(Trabajo,width=10, textvariable=M).grid(column=0, row=2, padx=10, pady=2)
Label(Trabajo, text="Número de tareas:",font=("Arial", 15),bg="#CDCDCD").grid(row=1, column=10, padx=10, pady=2)
Job = Entry(Trabajo,width=10,textvariable=J).grid(column=10, row=2,padx=10, pady=2)
botonT1 = Button(Trabajo, text="Maquinas disponibles y tiempo de operación",command = browseFiles).grid(column=0, row=6)
botonT1 = Button(Trabajo, text="Trabajo a ejecutar y sus operaciones",command = browseFiles).grid(column=0, row=7) 
Sim = Button(Trabajo, text="Iniciar Simulación", command=newWindow).grid(column=3, row=8)

#Usa el command= para poner la clase a la que va a poner a trabajar -> text_"", command= 
label_file_explorer = Label(Trabajo, text = "Documento", fg = "blue")
label_file_explorer.grid(column = 0, row = 9) 
Trabajo.mainloop()

