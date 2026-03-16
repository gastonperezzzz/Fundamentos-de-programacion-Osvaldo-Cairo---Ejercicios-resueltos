# Diseñar un algoritmo que me permita ingresar 100 números enteros. Luego
# determinar cuántas veces se repite el número 10 y mostrarlo.

diez = 0
for i in range(10):
    value = int(input("Ingrese un numero: "))
    if value == 10:
        diez += 1

print("El numero diez se repite", diez, "veces")