#include <stdio.h>

void cargaArray(int *, int);
int busquedaSecuencial(int *, int, int);

int main() {
    int n, ele;

    do {
        printf("Ingrese el numero de elementos del arreglo: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(n <= 0);

    int array[n];

    cargaArray(array, n);

    printf("Ingrese el elemento que quiere determinar su posicion: ");
    scanf("%d", &ele);

    ele = busquedaSecuencial(array, n, ele);

    if(ele) {
        printf("El elemento se encuentra en la posicion: %d\n", ele);
    }
    else {
        printf("No se pudo encontrar el elemento.\n");
    }

    return 0;
}

void cargaArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
int busquedaSecuencial(int *arr, int size, int num) {
    int element;
    for(int i = 0; i < size; i++) {
        if(arr[i] == num) {
            element = i;
            break;
        }
        else {
            element = 0;
        }
    }
    return element;
}