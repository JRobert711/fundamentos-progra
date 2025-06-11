'''
Clase:        10
Tema:         Manejo de matrices
Ejercicio:    10.3.1
Descripción:  Dada una matriz cuadrada ingresada por el
usuario, comprueba si la matriz cuadrada es
simétrica respecto a su diagonal principal.

Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-06-11
Estado:       [Terminado]
'''
n = int(input("Ingrese la dimensión de la matriz cuadrada: "))
m = []
for i in range(n):
    raw_input = input(f"ingrese numeros de la fila {i}: ")
    temp_m = list(map(int, raw_input.split(",")))
    m.append(temp_m)

# m = [[1,2,3],[2,5,0],[3,0,5]]
counter = 0
simetric = False
for line in m:
    if m[counter][counter + 1] == m[counter + 1][counter]:
        simetric = True
    else:
        continue
if simetric == False:
    print("La matriz no es simétrica")
else:
    print("La matriz es simétrica")
