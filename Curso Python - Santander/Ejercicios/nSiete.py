# Diseñar un programa que me permita acumular valores en un ciclo repetitivo “for” y
# luego mostrar el resultado final. Para esto se deberá hacer su correspondiente
# diagrama de flujos y posteriormente su codificación en el lenguaje C.

num = 0
acu = 0

for i in range(10):
    num = int(input("Ingrese un valor: "))
    acu += num

print("La sumatoria de los valores acumulados es:", acu)