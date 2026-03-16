#include <stdio.h>
#include <string.h>

main () {

    char welcome[] = "Bienvenido/a ", nombre[20];

    printf ("Ingrese su nombre: ");
    fgets(nombre, sizeof(nombre), stdin);

    printf ("%s", strcat(welcome, nombre));
}