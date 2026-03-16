# 1 - Definir una función max() que tome como argumento dos números y devuelva el mayor de ellos.
# Es cierto que python tiene una función max() incorporada, pero hacerla nosotros mismos es un muy buen ejercicio.

def fmax(n1, n2):
    if n1 > n2:
        print("El el primer numero es mayor")
    elif n2 > n1:
        print("El segundo numero es mayor")
    elif n1 == n2:
        print("Los numeros son iguales")

fmax(13, 144)
fmax(45, 36)
fmax(69, 69)
