#include <stdio.h>

main() {
    int arreglo[] = {9, 8, 5, 7, 2};
    int i, posActual, valorPos;

    printf("Arreglo sin ordenar...\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arreglo[i]);
    }

    for (i = 0; i < 5; i++) {
        posActual = i;
        valorPos = arreglo[i];

        while ((posActual > 0) && (valorPos < arreglo[posActual - 1])) {
            arreglo[posActual] = arreglo[posActual - 1];
            posActual--;
        }
        arreglo[posActual] = valorPos;
    }
    printf("\nOrden ascendente del arreglo...\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arreglo[i]);
    }
}