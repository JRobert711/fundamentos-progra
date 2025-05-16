'''
Clase:        Número 2
Tema:         Bloque if, elif, else
Ejercicio:    2.3.2 Cálculo de impuesto
Descripción:  Desarrollar un programa en Python que permita calcular el impuesto que debe pagar
un usuario por el consumo de energía. El cálculo debe realizarse basado en la siguiente
tabla.

Autor:        Julio Roberto Guardado Quijano
Fecha:        2025-05-15
Estado:       [Terminado]
'''

units = int(input("Ingrese las unidades gastadas: "))
impuesto = 0
if units >= 0 and units <= 100:
    impuesto = 0
elif units > 100 and units <= 200:
    for i in range(units - 1):
        impuesto = impuesto + 0.5
else:
    for i in range(units - 1):
        impuesto = impuesto + 0.7

print(f'Impuesto aplicado: ${impuesto}')