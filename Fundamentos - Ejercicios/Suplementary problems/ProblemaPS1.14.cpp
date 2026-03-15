#include <stdio.h>
#include <math.h>

main() {

    float x1, x2, x3, y1, y2, y3, area = 0;

    printf ("Ingrese el primer par ordenado: ");
    scanf ("%f %f", &x1, &y1);

    printf ("Ingrese el segundo par ordenado: ");
    scanf ("%f %f", &x2, &y2);

    printf ("Ingrese el tercer par ordenado: ");
    scanf ("%f %f", &x3, &y3);

    area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    printf ("El area del triangulo dados sus vertices es: %.3f", area);
}