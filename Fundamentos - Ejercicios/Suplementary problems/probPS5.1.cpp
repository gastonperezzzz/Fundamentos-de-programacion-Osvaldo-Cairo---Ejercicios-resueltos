#include <stdio.h>

void cargaArray(int *, int);
void printArray(int *, int);
void arrayPosNeg(int *, int, int *, int *, int *);

int main() {
    int n, cont_pos = 0, cont_neg = 0, cont_nul = 0;

    do {
        printf("Ingrese el tamaño del array: ");
        scanf("%d", &n);
    } while(n < 1 || n > 100);

    int array_nums[n];

    cargaArray(array_nums, n);
    arrayPosNeg(array_nums, n, &cont_pos, &cont_neg, &cont_nul);

    printf("Positivos: %d | Negativos: %d | Nulos: %d\n", cont_pos, cont_neg, cont_nul);

    return 0;
}

void cargaArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d", i, arr[i]);
    }
}
void arrayPosNeg(int *arr, int size, int *pos, int *neg, int *nul) {
    for(int i = 0; i < size; i++) {
        if(arr[i] > 0) {
            *pos += 1;
        }
        else if(arr[i] < 0){
            *neg += 1;
        }
        else {
            *nul += 1;
        }
    }
}