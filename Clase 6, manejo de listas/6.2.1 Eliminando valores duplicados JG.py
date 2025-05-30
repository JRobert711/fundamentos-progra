'''
Clase:        6
Tema:         Manejo de listas
Ejercicio:    6.2.1
Descripción:  Dada una lista ingresada por el usuario, elimina los elementos duplicados manteniendo la primera aparición de cada numero

Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-05-30
Estado:       [Terminado]
'''
numeros = input("Ingrese números: ")
nums = numeros.strip().split()
new_nums = []
for num in nums:
    if num not in new_nums:
        new_nums.append(num)
        new_nums.append(" ")
print("".join(new_nums))