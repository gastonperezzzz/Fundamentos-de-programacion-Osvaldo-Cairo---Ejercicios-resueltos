#include <stdio.h>
#include <string.h>

main() {

    char text[10];

    printf ("Ingrese una palabra en mayusculas: ");
    fgets(text, sizeof(text), stdin);

    strlwr(text);

    printf("Palabra en minusculas: %s", text);
}