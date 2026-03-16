def func_sum(numeros):
    sumatoria = 0
    for i in numeros:
        sumatoria += i

    return sumatoria

def func_multip(numeros):
    producto = 1
    for i in numeros:
        producto *= i

    return producto

list_numbers = []

while True:
    num = int(input("Ingrese un numero: "))
    list_numbers.append(num)
    option = input("Desea Ingresar otro numero? [S/N]: ")
    if option == 'N' or option == 'n':
        break

print("La sumatoria de los numeros ingresados es: ", func_sum(list_numbers))
print("La productoria de los numeros ingresados es: ", func_multip(list_numbers))