'''
Clase:        10
Tema:         Manejo de matrices
Ejercicio:    10.3.1
Descripción:  Dada una matriz cuadrada ingresada por el
usuario, comprueba si la matriz cuadrada es
simétrica respecto a su diagonal principal.

Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-06-13
Estado:       [Terminado]
'''
n = int(input("Ingrese la dimensión de la matriz cuadrada: "))
m = []
for i in range(n):
    raw_input = input(f"ingrese numeros de la fila {i}: ")
    temp_m = list(map(int, raw_input.split(",")))
    m.append(temp_m)

# m = [[1,2,3],[2,5,0],[3,0,5]]
simetric = True
for i in range(n):
    for j in range(i + 1, n):  # solo revisa la mitad superior (sin incluir la diagonal)
        if m[i][j] != m[j][i]:
            simetric = False
            break
    if not simetric:
        break

if simetric == False:
    print("La matriz no es simétrica")
else:
    print("La matriz es simétrica")