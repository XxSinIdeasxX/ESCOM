import random
from itertools import combinations

def check(a):
    if len(a)==0:
        return 'Ø'
    else:
        return a
def crear(nombre,n):
    a=[]
    for i in range (n):
        a.append(random.randint(1,9))
    print('\n '+nombre,'=',a)
    a=limpiar(a)
    print(' '+nombre,'=',a)
    print('|'+nombre+'|=',len(a),)
    return a
def limpiar(a):
    b=[]
    for i in range(len(a)):
        if b.count(a[i])==0:
            b.append(a[i])
    b.sort()
    return b
def conjuncion(a,b):
    c=[]
    for i in range(len(a)):
        if a[i] in b:
            c.append(a[i])
    return c
def complemento(a):
    U=[1,2,3,4,5,6,7,8,9]
    for i in range(len(a)):
        if a[i] in U:
            U.remove(a[i])
    return U
def resta(a,b):
    c=conjuncion(a,complemento(b))
    return c
def xor(a,b):
    c=limpiar(resta(a,b)+resta(b,a))
    return c
def cruz(a,b):
    axb='['
    for i in a:
        for j in b:
            if (i==a[-1])and(j==b[-1]):
                axb=axb+'('+str(i)+', '+str(j)+')]'
            else:
                axb=axb+'('+str(i)+', '+str(j)+'), '
    return axb
def potencia(a):
    pa='[Ø, '
    for i in a:
        pa=pa+'('+str(i)+'), '
    for x in range(2,len(a)):
        for c in (combinations(a,x)):
            pa=pa+str(c)+', '
    fin=str(a)
    fin=fin.replace('[','(')
    fin=fin.replace(']',')')
    pa=pa+fin+']'
    return pa

A=[]
B=[]
a=int(input('Número de elementos del conjunto A: '))
b=int(input('Número de elementos del conjunto B: '))
A=crear('A',a)
B=crear('B',b)
print('\n¬A =',check(complemento(A)))
print('¬B =',check(complemento(B)))
print('A ᴧ B =',check(conjuncion(A,B)))
print('A ᴠ B =',check(limpiar(A+B)))
print('A - B =',check(resta(A,B)))
print('B - A =',check(resta(B,A)))
print('A ⊕ B =',check(xor(A,B)))
print('A x B =',cruz(A,B))
print(' P(A) =',potencia(A))
print(' P(B) =',potencia(B))
