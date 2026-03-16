import random

magic_num = random.randint(0, 1000)
intentos = 0

while True:
    num = int(input("Adivina el numero: "))

    if num > magic_num:
        print("¡Menos!")
        intentos += 1
    elif num < magic_num:
        print("¡Mas!")
        intentos += 1

    if num == magic_num:
        print("¡Adivinaste!")
        print(f"Cantidad de intentos: {intentos}")
        break