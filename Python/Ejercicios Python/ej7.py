def es_palindromo(cadena):
    flag = True
    cad_inv = ""
    for i in range(len(cadena) - 1, - 1, -1):
        cad_inv += cadena[i]

    for i in range(0, len(cadena) - 1, 1):
        if  cadena[i] == cad_inv[i]:
            pass
        else:
            flag = False
            break

    return flag

print(es_palindromo("reconocer"))