def inversa(cadena):
    cad_inv = ""
    for i in range(len(cadena) - 1, -1, -1):
        cad_inv += cadena[i]

    return cad_inv

    
cadena = input("Ingrese una cadena de caracteres: ")
print(inversa(cadena))