def saludo():
    print("¡Hola, carajo!")

saludo()

#----------

def saludo_nombre(nombre):
    print(f"¡Hola, {nombre}! ¡Carajo!")

saludo_nombre("Sebastian")

# Funciones anonimas (LAMBDA)

cuadrado = lambda x, y: x + 5 + y
print(cuadrado(12, 12))

def calcular_media(*numeros):
    suma = sum(numeros)
    cantidad = len(numeros)
    media = suma / cantidad

    return media

print("La media es:", calcular_media(10, 20))

def sumar_3(x):
    return x + 3

sumar = lambda y: y + 3

print(sumar_3(5))
print(sumar(5))

# Funcion con cantidad indeterminada de argumentos:

def calcular_total(*numeros):
    total = 0
    for numero in numeros:
        total += numero

    return total

print("El total es:", calcular_total(20, 10, 30))