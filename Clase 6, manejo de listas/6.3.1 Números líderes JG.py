'''
Clase:        6
Tema:         Manejo de listas
Ejercicio:    6.3.1
Descripción:  Un número en una lista es "líder" si es
                estrictamente mayor que todos los
                elementos a su derecha. Dada una lista de
                números ingresada por el usuario, imprime
                todos los números líderes.
Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-06-1
Estado:       [Terminado]
'''
numeros = input("Ingrese números: ")
nums = list(map(int, numeros.strip().split()))
leader = []
for i in range(len(nums)):
    lider = True
    for j in range(i + 1, len(nums)):
        if nums[i] <= nums[j]:
            lider = False
            break
    if lider == True:
        leader.append(nums[i])
print(" ".join(map(str, leader)))