#include <stdio.h>
#include <string.h>

main() {

    char fullname[20], fullname2[20];
    int longitud = 0;

    printf ("Ingrese su nombre completo: ");
    fgets(fullname, sizeof(fullname), stdin);
    strcpy(fullname2, fullname);
    longitud = strlen(fullname);

    printf ("La longitud del texto es: %d", longitud);
    printf ("\nEl nombre completo es: %s", fullname2);
}