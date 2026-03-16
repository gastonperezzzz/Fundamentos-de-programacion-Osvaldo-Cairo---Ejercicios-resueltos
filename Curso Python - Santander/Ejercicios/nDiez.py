# Construye un diagrama y el programa correspondiente en C que, al recibir como
# datos los pagos efectuados en el último mes, permite obtener la suma de los
# mismos. El programa terminará cuando se ingrese un pago=0. Imprimir por pantalla
# el resultado de la suma.

pago = 0
sum = 0

while True:
    pago = int(input("Ingrese el pago efectuado el ultimo mes: "))
    sum += pago
    if pago == 0:
        break

print("La sumatoria de los pagos efectuados es:", sum)