# Un hospital tiene puntos de reparto de vacunas que se pretende funcionen de la
# siguiente manera. Cada día, va a empezar con un stock de 1000 vacunas
# disponibles y a través de un programa que controla las entregas. Va a avisar si el
# inventario baja de 200 unidades, suspender el reparto. Desarrollar diagrama de flujo.
# Para ello utilizar una estructura repetitiva “Do While”.

vacunas = 1000

while True:
    dif = int(input("Ingrese el numero de vacunas que se solicitan: "))
    vacunas -= dif
    if vacunas < 200:
        print("Hay menos de 200 vacunas disponibles...")
        break
