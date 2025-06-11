'''
Clase:        10
Tema:         Manejo de matrices
Ejercicio:    10.2.1
Descripción:  Dada una matriz cuadrada ingresada por el
usuario, crea dos listas, una con los
elementos de la diagonal principal y la otra
con los elementos de la diagonal
secundaria.

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

# m = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]

diagonales = []
diag_de = len(m[0])
print(diag_de)
temp_list = []
for line in m:
    for j in line:
        if j == line[diag_de - 1]:
            temp_list.append(line[diag_de - 1])
    diag_de -= 1
diagonales.append(temp_list)

diag_pri = len(m[-1])
counting = 0
temp_list2 = []
for line in m:
    for j in line:
        if j == line[counting]:
            temp_list2.append(j)
    if counting == diag_pri:
        break
    counting += 1
diagonales.append(temp_list2)
print(f"Las diagonales son: ")
for i in diagonales:
    print(i)