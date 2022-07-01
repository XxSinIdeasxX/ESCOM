import time
import math

def menu():
    print('\n\t\t    Menu\n============================================')
    print('1. Problema de devolver el cambio')
    print('2. Problema de la mochila')
    print('3. Salir\n\nSeleccione una opcion: ')
    op=int(input())
    while(op<1 or op>3):
        print('\n\t> Error <\n\nSeleccione una opcion valida: ')
        op=int(input())
    return op

def menuCam(den):
    print('\n\t    Devolver el cambio','\n ============================================')
    print('  Denominaciones:',den)
    print('  1. Evaluar algoritmo voraz y dinamico')
    print('  2. Cambiar denominaciones')
    print('  3. Regresar\n\n Seleccione una opcion: ')
    op=int(input())
    while(op<1 or op>3):
        print('\n\t> Error <\n\nSeleccione una opcion valida: ')
        op=int(input())
    return op

def menuMoc():
    print('\n\tProblema de la mochila\n ============================================')
    print('  1. Evaluar algoritmo voraz y dinamico')
    print('  2. Cambiar objetos')
    print('  3. Regresar\n\nSeleccione una opcion: ')
    op=int(input())
    while(op<1 or op>3):
        print('\n\t> Error <\n\nSeleccione una opcion valida: ')
        op=int(input())
    return op

def resCam(den,solV,solD):
    print('\nMoneda    Voraz   Dinamico')
    for i in range(len(den)):
        print(' ',den[i],'\t   ',solV[i],'\t    ',solD[i])

def resMoc(inv,solV,solD):
    
    for i in range(1, len(inv)):
        aux = inv[i]
        aux2 = solV[i]
        j = i
        while j > 0 and aux[1]<inv[j-1][1]:
            inv[j] = inv[j-1]
            solV[j] = solV[j-1]
            j-=1
        inv[j]=aux
        solV[j]=aux2

    print('\nObjeto    Valor    Peso   Dinamico    Voraz')
    for i in range(len(inv)):
        print(' ',i+1,'\t  ',inv[i][0],'\t   ',inv[i][1],'\t    ',solD[i],'\t      ',solV[i])

def ordInv(inv,x):# 0 para orden v/p desc, 1 otro para peso asc
    if x==0:
        for i in range(1, len(inv)):
            aux = inv[i]
            j = i
            while j > 0 and (aux[0]/aux[1])<(inv[j-1][0]/inv[j-1][1]):
                inv[j] = inv[j-1]
                j-=1
            inv[j]=aux
        return inv[::-1]
    else:
        for i in range(1, len(inv)):
            aux = inv[i]
            j = i
            while j > 0 and aux[1]<inv[j-1][1]:
                inv[j] = inv[j-1]
                j-=1
            inv[j]=aux
        return inv

def inventario():
    inv=[]
    print('\n¿Cuantos objetos deseas ingresar?')
    n=int(input())
    for i in range(n):
        aux=[]
        print('\nObjeto',i+1)
        print('Valor:')
        aux.append(int(input()))
        print('Peso:')
        aux.append(int(input()))
        inv.append(aux)

    # [Valor, Peso]
   
    return inv

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

def cambioVoraz (den, cambio):
    sol=[]
    sum=0
    for i in den:
        x=0
        if i<=cambio:
            n=cambio//i
            x+=n
            sum+=n
            cambio=cambio%i
        sol.append(x)
    print('\nNumero de monedas algoritmo voraz:',sum)
    return sol[::-1]

def cambioDinamico(den,c):
    # tabla[len(den)+1][c+1]
    sol=[0]*len(den)
    tabla=[]
    tabla.append([0]+[math.inf]*(c))
    for i in range(len(den)):
        tabla.append([0]*(c+1))
    
    for j in range(1,c+1):
        for i in range(1,len(tabla)):
            if den[i-1]>j:
                tabla[i][j]=tabla[i-1][j]
            else:
                if tabla[i-1][j]<tabla[i][j-den[i-1]]+1:
                    tabla[i][j]=tabla[i-1][j]
                else:
                    tabla[i][j]=tabla[i][j-den[i-1]]+1
    
    sum=tabla[-1][-1]
    print('\nNumero de monedas algoritmo dinamico:',sum)

    while sum!=0:
        if(i>1)and(tabla[i][j]==tabla[i-1][j]):i-=1
        else:
            sol[i-1]+=1
            j=j-den[i-1]
            sum-=1

    return sol

def mochilaVor(inv, c):
    sum=0
    sol=[0]*len(inv)
    i=0
    while c>0 and i<len(inv):
        peso=inv[i][1]
        # inv[i]=[valor, peso]
        if peso<=c:
            sol[i]=1
            sum+=inv[i][0]
            c-=peso
        else:
            aux=c/peso
            sum+=aux*inv[i][0]
            sol[i]=aux
            c=0
        i+=1
        
    print('\nValor de la mochila fraccionaria voraz:',sum)
    return sol

def mochilaDin(inv, c):
    # tabla[len(inv)+1][c+1]
    sol=[0]*len(inv)
    tabla=[]
    for i in range(len(inv)+1):
        tabla.append([0]*(c+1))
    
    for j in range(1,c+1):
        for i in range(1,len(tabla)):
            if inv[i-1][1]>j:
                tabla[i][j]=tabla[i-1][j]
            else:
                v=inv[i-1][0]
                w=inv[i-1][1]
                if tabla[i-1][j]<tabla[i-1][j-w]+v:
                    tabla[i][j]=tabla[i-1][j-w]+v
                else:
                    tabla[i][j]=tabla[i-1][j]
    
    sum=tabla[-1][-1]
    print('\nValor de la mochila entera dinamica:',sum)

    while sum>0:
        if(i>1)and(tabla[i][j]==tabla[i-1][j]):i-=1
        else:
            v=inv[i-1][0]
            w=inv[i-1][1]
            sol[i-1]+=1
            i-=1
            j=j-w
            sum-=v
    return sol


#[valor, peso]
inv=[[20,10],[30,20],[66,30],[40,40],[60,50]]
den = [1,5,10,25,100]
MergeSort(den)

while True:
    op=menu()
    if op==1:
        while True:
            opCam=menuCam(den)
            if opCam==1:
                print('\nIngresa el cambio a devolver:')
                c = int(input())

                tv = 1000*time.time()
                solV = cambioVoraz(den[::-1],c)
                tv = 1000*time.time()-tv
                print('Tiempo de ejecucion:',tv,'ms')

                td = 1000*time.time()
                solD = cambioDinamico(den,c)
                td = 1000*time.time()-td
                print('Tiempo de ejecucion:',td,'ms')

                resCam(den,solV,solD)
                
            elif opCam==2:
                print('\n¿Cuantas denominaciones deseas?')
                n=int(input())
                den=[]
                print('\n')
                for i in range(n):
                    print('Denominacion',str(i+1)+':')
                    den.append(int(input()))
                MergeSort(den)

            elif opCam==3:
                break

    elif op==2:
        
            while True:
                opMoc=menuMoc()
                if opMoc==1:
                    if len(inv)==0:
                        print('\nAun no hay ningun objeto registrado, por favor ingrese los datos de los objetos')
                        inv=inventario()
                    
                    print('\nIngrese la capacidad de la mochila:')
                    c=int(input())

                    inv=ordInv(inv,1)
                    td = 1000*time.time()
                    solD = mochilaDin(inv,c)
                    td = 1000*time.time()-td
                    print('Tiempo de ejecucion:',td,'ms')
                    
                    inv=ordInv(inv,0)
                    tv = 1000*time.time()
                    solV = mochilaVor(inv,c)
                    tv = 1000*time.time()-tv
                    print('Tiempo de ejecucion:',tv,'ms')

                    resMoc(inv,solV,solD)

                elif opMoc==2:
                    inv=inventario()
                    print('\nInventario actualizado')
                
                elif opMoc==3:
                    break            

    elif op==3:
        print('\nHasta luego :D\n')
        break
