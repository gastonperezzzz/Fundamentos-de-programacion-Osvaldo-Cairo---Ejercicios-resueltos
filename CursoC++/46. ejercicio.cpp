#include <stdio.h>
#include <string.h>

main() {

    char text1[20], text2[20];

    printf ("Ingrese una palabra: ");
    scanf ("%s", text1);
    printf ("Ingrese una palabra: ");
    scanf ("%s", text2);
    

    strupr(text1);
    printf ("Salida: %s", text1);
    strupr(text2);
    printf ("\nSalida: %s", text2);

    if (strcmp(text1, text2) == 0) {
        printf ("\nLas cadenas de texto son iguales...");
    } else {
        printf ("\nLas cadenas son diferentes...");
    }
}