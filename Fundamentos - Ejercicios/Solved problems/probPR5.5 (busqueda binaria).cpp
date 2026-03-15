#include <stdio.h>

void cargaArray(int *, int);
int busquedaBinaria(int *, int, int);

int main() {
    int n, element;

    do {
        printf("Ingrese el numero de elementos del array: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(n <= 0);

    int array[n];
    cargaArray(array, n);

    printf("Ingrese el elemento que quiere determinar su posicion: ");
    scanf("%d", &element);

    element = busquedaBinaria(array, n, element);

    if(element) {
        printf("El elemento se encuentra en la posicion: %d\n", element);
    }
    else {
        printf("No se ha podido localizar el elemento.\n");
    }

    return 0;
}

int busquedaBinaria(int *arr, int size, int element) {
    int right = size - 1, left = 0, mid, flag = 0;
    while((left <= right) && !flag) {
        mid = (left + right) / 2;
        if(element == arr[mid]) {
            flag = mid;
        }
        else if(element > arr[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return flag;
}
void cargaArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}