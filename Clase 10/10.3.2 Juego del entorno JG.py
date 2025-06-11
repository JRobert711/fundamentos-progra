'''
Clase:        10
Tema:         Manejo de matrices
Ejercicio:    10.3.2
Descripción:  Dada una matriz binaria ingresada por el
usuario, verifica para cada celda de una
matriz binaria cuántos elementos con valor
de 1 hay en las celdas vecinas (arriba, abajo,
izquierda, derecha, diagonales).

Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-06-10
Estado:       [Terminado]
'''
n = int(input("Ingrese la dimensión de la matriz cuadrada: "))
nu = int(input("Ingrese el número de columnas de la matriz cuadrada: "))
m = []
for i in range(n):
    raw_input = input(f"ingrese numeros de la fila {i}: ")
    temp_m = list(map(int, raw_input.split(",")))
    m.append(temp_m)
neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
vecinos = []
for i in range(n):
    new_filas = []
    for j in range(nu):
        counter = 0
        for neighborx, neighbory in neighbors:
            ni, nj = i + neighborx, j + neighbory
            if 0 <= ni < n and 0 <= nj < nu:
                if m[ni][nj] == 1:
                    counter += 1
        new_filas.append(counter)
    vecinos.append(new_filas)

for fila in vecinos:
    print(fila)