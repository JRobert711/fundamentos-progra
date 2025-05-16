'''
Clase:        Número 2
Tema:         Bloque if, elif, else
Ejercicio:    2.3.1 contraseña segura
Descripción:  Solicita una cadena de texto que representa una contraseña, y verifica si la contraseña
cumple con las siguientes condiciones: tener al menos 8 caracteres, un número y una
mayúscula.

Autor:        Julio Roberto Guardado Quijano
Fecha:        2025-05-15
Estado:       [Terminado]
'''
contraseña = input("Escribe tu contraseña:")
num = False
letter = False
if len(contraseña) >= 8:
    for i in contraseña:
        if i.isdigit():
            num = True
            continue
        elif i.isupper():
            letter = True
            continue
    if num == True and letter == True:
        print("contraseña segura")
    else:
        print("contraseña no segura")
    
