#include <stdio.h>

main() {
    int dia;

    printf ("Ingresen cantidad de dias: "); scanf ("%d", &dia);

    dia = dia * 24 * 60 * 60;

    printf ("La cantidad de segundos que hay en esos dias es %d", dia);
}