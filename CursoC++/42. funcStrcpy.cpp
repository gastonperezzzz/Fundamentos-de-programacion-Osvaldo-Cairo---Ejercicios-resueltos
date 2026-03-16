#include <stdio.h>
#include <string.h>

main() {

    char nombre[] = "Gaston";
    char nombre1[10];

    strcpy(nombre1, nombre);

    printf ("%s", nombre1);
} 