# Construye un diagrama y el programa correspondiente en C que, al recibir como
# datos un grupo de números naturales positivos, calcule el cuadrado de estos
# números y al final la suma de los cuadrados. El programa terminará cuando se
# ingrese un 0. Imprimir por pantalla el resultado de la suma de todos los cuadrados.

num = 0
sumcuad = 0

while True:
    num = int(input("Ingrese un numero positivo: "))
    if num == 0:
        break
    if num > 0:
        sumcuad += num * num

print("La sumatoria del cuadrado de los numeros ingresados es:", sumcuad)