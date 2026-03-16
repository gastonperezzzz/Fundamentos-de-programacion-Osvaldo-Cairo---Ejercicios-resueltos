#include <stdio.h>
#include <string.h>

main() {

    char nombre[20];

    printf ("Ingrese su nombre en mayusculas: ");
    fgets(nombre, sizeof(nombre), stdin);

    if (nombre[0] == 'A' || nombre[0] == 'E' || nombre[0] == 'I' || nombre[0] == 'O' || nombre[0] == 'U') {
        strlwr(nombre);
        printf ("Su nombre en minusculas es: %s", nombre);
    }
    else {
        printf ("Su nombre no empieza con vocal...");
    }
}