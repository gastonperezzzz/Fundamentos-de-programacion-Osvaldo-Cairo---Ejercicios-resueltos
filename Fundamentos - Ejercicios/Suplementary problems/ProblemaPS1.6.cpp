#include <stdio.h>

main() {
    float can, pes = 12.48, usd;

    printf ("Ingrese la cantidad de dolares que quiera convertir a MX: ");
    scanf ("%f", &usd);

    can = usd * pes;

    printf ("%.2f dolares son equivalentes a %.3f pesos mexicanos", usd, can);
}