# Desarrollar un algoritmo que me permita ingresar tres números por teclado y
# determinar cuál de ellos es el mayor. Por último calcular el promedio de ellos y
# mostrarlo por pantalla.

cont = 0
mayor = 0
acu = 0.0

while cont < 3:
    num = int(input("Ingrese un numero: "))
    cont += 1
    acu += num
    if num > mayor:
        mayor = num

print("El mayor numero ingresado es:", mayor)
print("El promedio de los numeros ingresados es:", acu / 3)