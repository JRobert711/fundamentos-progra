'''
Clase:        5
Tema:         Bloque for y bloque while
Ejercicio:    5.4.2
Descripción:  Pide un número al usuario y suma sus dígitos hasta que quede un solo dígito. Ejemplo:
Si el usuario ingresa 9875, entonces: 9+8+7+5 = 29 → 2+9 = 11 → 1+1 = 2.

Autor:        Julio Roberto Guardado Quijano 
Fecha:        2025-05-30
Estado:       [Terminado]
'''
numero = input("Ingresa un número: ")
digits = []
for digit in numero:
    digits.append(int(digit))
result = str(sum(digits))
print(f"{numero} = {result}")
while True:
    digits = []
    for num in result:
        digits.append(int(num))
    if len(digits) > 1:
            past_result = result
            result = str(sum(digits))
            print(f"{past_result} = {result}")
    if len(digits) == 1:
         break
print("\n")
print(f"El resultado final es: {result}")