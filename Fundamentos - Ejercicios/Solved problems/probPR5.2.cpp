#include <stdio.h>

void cargaArray(int *, int tam);
void printArray(int *, int tam);
void deleteElement(int *, int *);

int main() {
    int n;

    do {
        printf("Ingrese el numero de elementos para el array: ");
        scanf("%d", &n);
    } while(n <= 0 || n > 100);

    int array[n];
    cargaArray(array, n);
    deleteElement(array, &n);
    printArray(array, n);

    return 0;
}

void cargaArray(int *arr, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void printArray(int *arr, int tam) {
    for(int i = 0; i < tam; i++)
        printf("Posicion [%d]: %d\n", i, arr[i]);
}
void deleteElement(int *arr, int *tam) {
    int i = 0, k, l;
    while(i < (*tam - 1)) {
        k = i + 1;
        while(k <= (*tam - 1)) {
            if(arr[i] == arr[k]) {
                for(l = k; l < (*tam - 1); l++) {
                    arr[l] = arr[l + 1];
                    *tam = *tam - 1;
                }
            }
            else {
                k++;
            }
        }
        i++;
    }
}