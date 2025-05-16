'''
Clase:        Número 2
Tema:         Bloque if, elif, else 
Ejercicio:    2.4.1 Número mágico
Descripción:  Crea un programa en Python para determinar si un número es "mágico“.
Un número es “mágico” si es divisible por 7 pero no por 5.

Autor:        Julio Roberto Guardado Quijano
Fecha:        2025-05-15
Estado:       [Terminado]
'''

num = int(input("Ingrese un numero: "))

if num % 7 == 0 and num % 5 != 0:
    print("Mágico")
else:
    print("No es mágico")