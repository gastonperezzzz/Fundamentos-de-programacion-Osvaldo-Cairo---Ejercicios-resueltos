def superposicion(lista1, lista2):
    flag = False
    for i in lista1:
        for j in lista2:
            if i == j:
                flag = True
    
    return flag

conjunto1 = [1, 2, 3, 4]
conjunto2 = [5, 5, 6, 7]

if superposicion(conjunto1, conjunto2):
    print("Las listas tienen al menos un elemento en comun.")
else:
    print("Las listas no tienen ningun elemento en comun.")