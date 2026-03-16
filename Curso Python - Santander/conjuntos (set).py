# Para crear un conjunto:

frutas = {"Naranja", "Kiwi", "Frutilla"}
numeros = set([1, 2, 3, 4, 5])

# Ejemplos y operaciones con conjuntos:

conjunto1 = {1, 2, 3}
conjunto2 = {3, 4, 5}

union = conjunto1 | conjunto2
print(union)

interseccion = conjunto1 & conjunto2
print(interseccion)

diferencia = conjunto1 - conjunto2
print(diferencia)

dif_simetrica = conjunto1 ^ conjunto2
print(dif_simetrica)

# Metodos de conjuntos

cocina = {"Olla", "Espatula", "Cuchillo", "Tenedor"}

cocina.add("Plato")
print(cocina)

cocina.remove("Olla")
print(cocina)

cocina.discard("Cebolla")
print(cocina)

cocina.clear()
print(cocina)