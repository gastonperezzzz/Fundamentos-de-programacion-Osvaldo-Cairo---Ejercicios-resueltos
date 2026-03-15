#include <stdio.h>

void cargaVec(int *, int);
void printVec(int *, int);
void deleteElementRepeat(int *, int *);

int main() {
    int n;

    do {
        printf("Ingrese el tamaño del array: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: tamaño invalido.\n");
        }
    } while(n <= 0);

    int array[n];

    cargaVec(array, n);
    deleteElementRepeat(array, &n);
    printVec(array, n);

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
void deleteElementRepeat(int *arr, int *size) {
    for(int i = 0; i < *size; i++) {
        for(int j = (i + 1); j < *size; j++) {
            if(arr[i] == arr[j]) {
                for(int k = j; k < *size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                *size = *size - 1;
            }
        }
    }
}