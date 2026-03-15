// AlGORITMO DE ORDENAMIENTO SELECCION DIRECTA.

#include <stdio.h>

int main() {
    int size = 8;
    int array[size] = {12, 34, 22, 11, 54, 36, 19, 7};
    int i, j, aux;

    for(i = 0; i < size; i++) {
        for(j = (i + 1); j < size; j++) {
            if(array[i] > array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    for(i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, array[i]);
    }

    return 0;
}
