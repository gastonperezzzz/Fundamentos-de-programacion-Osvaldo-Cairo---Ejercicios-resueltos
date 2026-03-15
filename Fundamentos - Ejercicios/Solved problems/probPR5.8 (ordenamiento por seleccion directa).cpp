#include <stdio.h>

void ordenamientoSelDirecta(int *, int);
void cargaArray(int *, int);
void printArray(int *, int);

int main() {
    int tam;

    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &tam);
        if(tam <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(tam <= 0);

    int array[tam];

    cargaArray(array, tam);
    ordenamientoSelDirecta(array, tam);
    printArray(array, tam);

    return 0;
}

void ordenamientoSelDirecta(int *arr, int size) {
    int menor = 0, l;
    for(int i = 0; i < (size - 1); i++) {
        int menor = arr[i];
        l = i;
        for(int j = (i + 1); j < size; j++) {
            if(arr[j] < menor) {
                menor = arr[j];
                l = j;
            }
        }
        arr[l] = arr[i];
        arr[i] = menor;
    }
    if(menor == 100000) {
        printf("%d ", menor);
    }
}
void cargaArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}