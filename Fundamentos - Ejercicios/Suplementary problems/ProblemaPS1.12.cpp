#include <stdio.h>

#define PI 3.141692

main() {

    float rad, area, vol;

    printf ("Ingrese el radio de la esfera: ");
    scanf ("%f", &rad);

    area = 4 * PI * rad * rad;
    vol = 0.33333 * PI * rad * rad * rad;

    printf ("El area de la esfera es: %.3f", area);
    printf ("\nEl volumen de la esfera es: %.3f", vol);
}