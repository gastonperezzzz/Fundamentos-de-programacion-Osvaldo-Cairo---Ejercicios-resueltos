text = input("Ingrese una frase para escribir en un archivo: ")

archivo = open("archivo1.txt", "w")
archivo.write(text)
archivo.close()

archivo = open("archivo1.txt", "r")
contenido = archivo.read()
print(contenido)
archivo.close()

with open("archivo1.txt", "r") as archivo:
    contenido2 = archivo.read()
    print(contenido2 + " :)")