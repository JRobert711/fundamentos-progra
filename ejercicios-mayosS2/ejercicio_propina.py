'''
Clase:        Número 1
Tema:         Tipos de variables en Python
Ejercicio:    1.3.1 automatizando el cálculo de propina
Descripción:  Pide al usuario el total de una cuenta y el porcentaje de propina
(por ejemplo, 10%, 15%, 20%). Calcula y muestra en pantalla el total
a pagar.

Autor:        Julio Roberto Guardado Quijano
Fecha:        2025-05-18
Estado:       [Terminado]
'''

cuenta = float(input('Cuántas compras realizó?'))
propina = (int(input('Cuál es el porcentaje de propina?'))/100)
result = cuenta + (cuenta*propina)
print(f'Asume un total de ${cuenta} y {propina*100}% de propina, quedando con {result}% en total')