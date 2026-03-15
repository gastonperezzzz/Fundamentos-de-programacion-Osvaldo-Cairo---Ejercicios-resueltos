#include <stdio.h>

void ordenamientoInsercion(int *, int);
void cargaArray(int *, int);
void mostrarArray(int *, int);

int main() {
    int n = 5;
    int array[n];

    cargaArray(array, n);
    ordenamientoInsercion(array, n);
    mostrarArray(array, n);

    return 0;
}
/*
void ordenamientoInsercion(int *arr, int size) {
    int aux;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}
*/
void cargaArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void mostrarArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}
void ordenamientoInsercion(int *arr, int size) {
    int aux, l, i;
    for(i = 1; i < size; i++) {
        aux = arr[i];
        l = i - 1;
        while((l >= 0) && (aux < arr[l])) {
            arr[l + 1] = arr[l];
            l--;
        }
        arr[l + 1] = aux;
    }
}