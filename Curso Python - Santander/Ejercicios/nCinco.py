# Se desea calcular independientemente la suma de los números pares comprendidos
# entre 1 y 200.
cont = 1
for cont in range(1, 200):
    cont += 1
    if cont % 2 == 0:
        print(cont)
