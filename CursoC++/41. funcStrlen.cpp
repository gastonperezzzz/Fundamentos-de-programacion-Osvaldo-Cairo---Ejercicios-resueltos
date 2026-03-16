#include <stdio.h>
#include <string.h>

// Funcion "strlen()" nos sirve para determinar la cantidad de letras que tiene una cadena de caracteres

main() {

    char nombre[] = "EL DIAPLO";
    int longitud = 0;

    longitud = strlen(nombre);

    printf ("El nombre es: %s\n", nombre);
    printf ("La longitud del nombre es: %d", longitud);
}