#include <stdio.h>
#include <math.h>

main() {
    const float pi = 3.141692;
    float rad, area, circ;

    printf ("Ingrese el radio del circulo: ");
    scanf ("%f", &rad);

    area = pi * pow (rad, 2);
    circ = 2 * pi * rad;

    printf ("El area del circulo es %.3f y su circunferencia es %.3f", area, circ);
}