#include <stdio.h>
#include <string.h>

main () {

    char text[20];
    int longitud = 0;

    printf ("Ingrese una cadena de texto: ");
    fgets(text, sizeof(text), stdin);

    longitud = strlen(text);

    printf ("%s", text);

    if (longitud > 10) {
        printf ("El texto tiene una longitud mayor a diez caracteres...");
    } 
    else {
        printf ("Es un texto corto, menos de 10 caracteres...");
    }
}