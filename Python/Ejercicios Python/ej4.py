def es_vocal(letra):
    flag = False
    vocales = "aeiouAEIOU"
    for vocal in vocales:
        if vocal == letra:
            flag = True
        
    return flag

letter = input("Ingrese una letra para determinar si es vocal o no: ")

if es_vocal(letter):
    print(f"'{letter}' es una letra vocal.")
else:
    print(f"'{letter}' NO es una letra vocal.")
