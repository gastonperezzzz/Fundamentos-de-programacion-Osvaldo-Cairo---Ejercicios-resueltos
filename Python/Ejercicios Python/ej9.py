def generar_n_caracteres(num, letter):
    new_string = ""
    for i in range(0, num):
        new_string += letter

    return new_string

letra = 'o'
print(generar_n_caracteres(3, letra))