#include <stdio.h>

main() {

    float lad, areabase = 0, arealat = 0, areatot = 0, vol = 0;

    printf ("Ingrese el lado del hexaedro (cubo): ");
    scanf ("%f", &lad);

    areabase = lad * lad;
    arealat = 4 * lad * lad;
    areatot = 6 * lad * lad;
    vol = lad * lad * lad;

    printf ("El area base del hexaedro es: %.3f", areabase);
    printf ("\nEl area lateral del hexaedro es: %.3f", arealat);
    printf ("\nEl area total del hexaedro es: %.3f", areatot);
    printf ("\nEl volumen del hexaedro es: %.3f", vol);
}