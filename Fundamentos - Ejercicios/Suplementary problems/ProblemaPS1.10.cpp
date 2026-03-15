#include <stdio.h>

int readInt(int a);

main() {
    int w = 0, x = 0, y = 0, z = 0;

    w = readInt(w);
    x = readInt(x);
    y = readInt(y);
    z = readInt(z);

    printf ("%d \n%d \n%d \n%d", w, x, y, z);
}

int readInt(int a) {
    printf ("Ingrese un numero: ");
    scanf ("%d", &a);
    return (a);
}