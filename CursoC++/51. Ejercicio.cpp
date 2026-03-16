#include <stdio.h>

int cargaArray(int array[]);

main () {
    int arreglo[100], elementos;

    elementos = cargaArray(arreglo);

    printf("La cantidad de elementos son: %d", elementos);
}

int cargaArray(int array[]) {
    int elem;
    printf("Ingrese la cantidad de elementos del array: ");
    scanf("%d", &elem);

    for (int i = 0; i < elem; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &array[i]);
    }
    return elem;
}