#LISTAS: Estructura de datos mutable, que puede almacenar distintos tipos de datos que son accesibles por indice

nombre = "pepe"

frutas = ["manzana", "banana", "naranja", 5, nombre]

print(frutas[0])
print(frutas[1])
print(frutas[2])
print(frutas[3])
print(frutas[4])

print(frutas[-1])  # Imprime "Pepe"
print(frutas[-2])  # Imprime "5"
print(frutas[-3])  # Imprime "naranja"

#Metodos de listas

# append(elemento): agrega un elemento al final de la lista.
# insert(indice, elemento): inserta un elemento en una posición específica de la lista.
# remove(elemento): elimina la primera aparición de un elemento en la lista.
# pop(indice): elimina y devuelve el elemento en una posición específica de la lista.
# sort(): ordena los elementos de la lista en orden ascendente.
# reverse(): invierte el orden de los elementos en la lista.

frutas.append("Hola")
print(frutas)
frutas.insert(2, "Carajo")
print(frutas)
frutas.remove("Hola")
frutas.remove(5)
print(frutas)
deletedfruit = frutas.pop(2)
print(deletedfruit)
frutas.sort()
print(frutas)
frutas.reverse()
print(frutas)

# nueva_lista = [expresion for elemento in secuencia if condicion]

numeros = [1, 2, 3, 4, 5]
cuadrados = [x ** 2 for x in numeros if x % 2 == 0]
print(cuadrados)  # Imprime [4, 16]