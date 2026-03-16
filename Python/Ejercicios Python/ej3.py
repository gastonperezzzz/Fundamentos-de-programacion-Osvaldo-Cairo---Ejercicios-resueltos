def cont_elem(lista):
    cont = 0
    for i in lista:
        cont += 1

    return cont

lista = [1, 2, 3, 4, 5]
tuplona = (20, 72, 45)
conjunt = {33, 123, 91}

print(cont_elem(lista))
print(cont_elem(tuplona))
print(cont_elem(conjunt))