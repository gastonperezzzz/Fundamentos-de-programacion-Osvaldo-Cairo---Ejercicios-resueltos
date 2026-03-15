#include <stdio.h>

main() {
    float pre, pag, cam;

    printf ("Ingrese el precio del producto: ");
    scanf ("%f", &pre);

    printf ("Ingrese el monto a pagar: ");
    scanf ("%f", &pag);

    cam = pag - pre;

    if (cam < 0) {
        printf ("Su cambio es %.2f, debe dinero", cam);
    } 
    else {
        printf ("Compra exitosa, su cambio es: %.2f", cam);
    }

}