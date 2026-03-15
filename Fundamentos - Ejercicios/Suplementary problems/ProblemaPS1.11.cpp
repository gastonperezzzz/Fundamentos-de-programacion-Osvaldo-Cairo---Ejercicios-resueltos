#include <stdio.h>

#define PI 3.141692

main() {

    float rad, alt, gen, areabase = 0, arealat = 0, areatot = 0, vol = 0;

    printf ("Ingrese el radio del cono: ");
    scanf ("%f", &rad);

    printf ("Ingrese la generatriz del cono: ");
    scanf ("%f", &gen);

    printf ("Ingrese la altura del cono: ");
    scanf ("%f", &alt);

    areabase = PI * rad * rad;
    arealat = PI * rad * gen;
    areatot = areabase + arealat;
    vol = 0.3333 * areabase * alt;

    printf ("El area base es: %.3f", areabase);
    printf ("\nEl area lateral es: %.3f", arealat);
    printf ("\nEl area total es: %.3f", areatot);
    printf ("\nEl volumen es: %.3f", vol);
}