#for variable in secuencia:

    # Bloque de código a repetir
    #instrucciones

frutas = ["manzana", "banana", "naranja"]


for fruta in frutas:
    print(fruta)

#while condicion:

    # Bloque de código a repetir
    #instrucciones

contador = 0


while contador < 5:

    print(contador)
    contador += 1

#Ejemplo

# print("Numeros del 1 al 5 multiplicados por dos en 'for' ")
# for numero in range(1, 6):
#     print(numero * 2)

# print("Numeros del 1 al 5 multiplicados por dos en 'while' ")
# contador = 1
# while contador <= 5:
#     print(contador * 2)
#     contador += 1
print("")
for i in range(10):

    if i % 2 == 0:
        continue
    print(i)

print("")
for i in range(10):
    if i % 2 != 0:
        print(i)

contador = 0


while True:
    print(contador)
    contador += 1

    if contador == 5:
        break

for i in range(5):
    pass