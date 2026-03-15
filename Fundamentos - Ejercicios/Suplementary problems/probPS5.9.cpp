#include <stdio.h>

void cargaVec(int *, int);
void printVec(int *, int);
void newArray(int *, int *, int, int, int *);
void ordenamientoDescent(int *, int);
void ordenamientoAscent(int *, int);

int main() {
    int n, m;

    do {
        printf("Ingrese el tamaño del primer arreglo: ");
        scanf("%d", &n);
        if(n < 1 || n > 100) {
            printf("Error: tamaño invalido.\n");
        }
    } while(n < 1 || n > 100);

    do {
        printf("Ingrese el tamaño del segundo arreglo: ");
        scanf("%d", &m);
        if(m < 1 || m > 100) {
            printf("Error: tamaño invalido.\n");
        }
    } while(m < 1 || m > 100);

    int array1[n], array2[m], array3[n + m];

    cargaVec(array1, n);
    cargaVec(array2, m);
    ordenamientoAscent(array1, n);
    ordenamientoAscent(array2, m);
    newArray(array1, array2, n, m, array3);
    ordenamientoAscent(array3, n + m);
    printVec(array3, n + m);

    return 0;
}

void cargaVec(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void printVec(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}
void newArray(int *arr1, int *arr2, int T1, int T2, int *arr3) {
    int i, j;
    for(i = 0; i < T1; i++) {
        arr3[i] = arr1[T1 - i - 1];
    }
    for(j = 0; j < (T1 + T2); j++) {
        arr3[j + T1] = arr2[T2 - j - 1];
    }
}
void ordenamientoDescent(int *arr, int size) {
    int position, aux;
    for(int i = 0; i < size; i++) {
        position = i;
        for(int j = (i + 1); j < size; j++) {
            if(arr[i] < arr[j]) {
                position = j;
            }
        }
        aux = arr[i];
        arr[i] = arr[position];
        arr[position] = aux;
    }
}
void ordenamientoAscent(int *arr, int size) {
    int position, aux;
    for(int i = 0; i < (size - 1); i++) {
        position = i;
        for(int j = (i + 1); j < size; j++) {
            if(arr[i] > arr[j]) {
                position = j;
            }
        }
        aux = arr[i];
        arr[i] = arr[position];
        arr[position] = aux;
    }
}