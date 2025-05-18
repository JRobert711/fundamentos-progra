'''
Clase:        Número 1
Tema:         Tipos de variables en Python
Ejercicio:    1.3.2 generador de correo de key
Descripción:  Solicita al usuario su nombre completo (asume dos nombres y
dos apellidos). Luego, el programa generará, su correo con el
formato:

Autor:        Julio Roberto Guardado Quijano
Fecha:        2025-05-18
Estado:       [Terminado]
'''

nombre = input('Escriba su nombre completo')
noms = nombre.split()
print(noms)
print(f'Su correo asignado será: {noms[0]}.{noms[2]}@keyinstitute.edu.sv')