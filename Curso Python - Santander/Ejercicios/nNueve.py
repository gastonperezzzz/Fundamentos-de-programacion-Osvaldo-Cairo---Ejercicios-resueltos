# Escribe un diagrama de flujo y el correspondiente programa en C que, al recibir
# como datos N números enteros, obtenga solamente la suma de los números
# positivos.

n = int(input("Ingrese la cantidad de veces que quiere iterar: "))
num = 0
sumpos = 0

for i in range(n):
    num = int(input("Ingrese un valor entero: "))
    if num > 0:
        sumpos += num

print("La sumatoria de los numeros positivos es:", sumpos)