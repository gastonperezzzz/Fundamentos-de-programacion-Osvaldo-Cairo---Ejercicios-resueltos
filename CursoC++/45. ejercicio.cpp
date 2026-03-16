#include <stdio.h>
#include <string.h>

main() {

    char palabra[20], pali[20];

    printf ("Ingrese una palabra: ");
    scanf ("%s", palabra);

    strcpy(pali, palabra);

    //printf ("%s", palabra);
    //printf ("%s", pali);
    printf ("%s\n", strrev(palabra));

    if (strcmp(palabra, pali) == 0) {
        printf ("La palabra ingresada es palindroma...");
    } else {
        printf ("La palabra ingresada no es palindroma...");
    }
}