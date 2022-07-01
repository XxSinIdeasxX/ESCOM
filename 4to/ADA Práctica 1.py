import random
import time
import matplotlib.pyplot as plt

def lista(n):
    l=[]
    for i in range(n):
        l.append(random.randint(1,100))
    return l  
def listaOrd(n):
    l=[]
    for i in range(n):
        l.append(i)
    return l

def MaxIt(l):
    max=l[0]
    for i in l:
        if i > max:
            max=i
    return max
def MaxRe(l):
    n=len(l)
    if n==1:
        return l[0]
    else:
        a=MaxRe(l[:n//2])
        b=MaxRe(l[n//2:])
        if a>b: return a
        else: return b

def Maximos():
    tIt=[]
    tRe=[]
    a=[]
    x=[]
    for i in range(1,5001):
        x.append(i)
        a=lista(i)

        ti=1000000*(time.time())
        max1=MaxIt(a)
        tf=1000000*(time.time())
        tIt.append(tf-ti)

        ti=1000000*(time.time())
        max2=MaxRe(a)
        tf=1000000*(time.time())
        tRe.append(tf-ti)
    '''
    print('Unidades | Iterativo | Recursivo')
    for i in range(len(tIt)):
        print(200*(i+1),':\t    ',tIt[i],'\t',tRe[i])
    '''
    plt.title('Tiempo busqueda de elemento máximo')    
    plt.xlabel('Elementos')
    plt.ylabel('Tiempo (micro s)')
    plt.plot(x, tRe, label = 'Recursivo', c='violet')
    plt.plot(x, tIt, label = 'Iterativo', c='green')
    plt.legend()
    plt.show() 

def Bubble(l):
    n = len(l)
    for i in range(n-1):  
        for j in range(0, n-i-1):
            if l[j] > l[j + 1] :
                l[j], l[j + 1] = l[j + 1], l[j]
def Insertion(l):
    for i in range(1, len(l)):
        aux = l[i]
        j = i
        while j > 0 and aux<l[j-1]:
            l[j] = l[j-1]
            j-=1
        l[j]=aux
def MergeSort(l):
    if len(l) > 1:
        mid = len(l) // 2
        left = l[:mid]
        right = l[mid:]

        MergeSort(left)
        MergeSort(right)

        i = 0
        j = 0
        k = 0
        
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                l[k] = left[i]
                i += 1
            else:
                l[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            l[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            l[k]=right[j]
            j += 1
            k += 1

def Orden(op):
    tBub=[]
    tIns=[]
    tMer=[]
    a=[]
    x=[]
    for i in range(1000,10001,1000):
        x.append(i)
        if op==1:a=lista(i)             # Promedio
        elif op==2:a=listaOrd(i)        # Mejor
        elif op==3:a=listaOrd(i)[::-1]  # Peor
        ti=1000*(time.time())
        Bubble(a.copy())
        tf=1000*(time.time())
        tBub.append(tf-ti)

        ti=1000*(time.time())
        Insertion(a.copy())
        tf=1000*(time.time())
        tIns.append(tf-ti)

        ti=1000*(time.time())
        MergeSort(a.copy())
        tf=1000*(time.time())
        tMer.append(tf-ti)

    print('Unidades |        Bubble       |     Insertion     |       Merge')
    for i in range(len(tBub)):
        print(1000*(i+1),':\t    ',tBub[i],'\t',tIns[i],'\t',tMer[i])

    if op==1:plt.title('Tiempo ordenamiento promedio')      # Promedio
    elif op==2:plt.title('Tiempo ordenamiento mejor caso')  # Mejor
    elif op==3:plt.title('Tiempo ordenamiento peor caso')   # Peor
        
    plt.xlabel('Elementos')
    plt.ylabel('Tiempo (ms)')
    plt.plot(x, tBub, label = 'Bubble')
    plt.plot(x, tIns, label = 'Insertion')
    plt.plot(x, tMer, label = 'Merge sort')
    plt.legend()
    plt.show() 

'''Seleccionar un proceso a la vez para que la
generación de gráficas no afecte a los demás resultados

1 : Busqueda de mMaximo
2 : Ordenamiento promedio
3 : Ordenamiento mejor caso
4 : Ordenamiento peor caso
'''
op=2

if op==1:
    print('\n\t\tBusqueda de maximo\n')
    Maximos()
elif op==2:
    print('\n\t\tOrdenamiento promedio\n')
    Orden(1)
elif op==3:
    print('\n\t\tOrdenamiento mejor caso\n')
    Orden(2)
elif op==4:
    print('\n\t\tOrdenamiento peor caso\n')
    Orden(3)