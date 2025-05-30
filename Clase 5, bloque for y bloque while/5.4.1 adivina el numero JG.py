'''
Clase:        Bloque for y bloqe while
Tema:         Listas
Ejercicio:    5.4.1
Descripción:  Genera un número aleatorio entre 1 y 100 y pide al usuario que lo adivine.
El programa debe seguir pidiendo números hasta que acierte. En cada
intento fallido el programa notificará al usuario si el número secreto es
mayor o menor al último valor ingresado.

Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-05-30
Estado:       [Terminado]
'''
import random
num = random.randint(1,100)
intento = int(input("Ingresa un número entre 1 y 100: "))
while intento != num:
    if intento > num:
        print("El número secreto es menor")
    elif intento < num:
        print("El número secreto es mayor")
    intento = int(input("Ingresa un número entre 1 y 100: "))
print("!Felicidades¡ Has advinado el número secreto")
print("Fin del juego")