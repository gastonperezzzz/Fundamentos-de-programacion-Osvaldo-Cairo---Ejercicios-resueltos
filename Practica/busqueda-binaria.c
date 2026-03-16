#include <stdio.h>

void bubbleSort(int *, int);
void mostrarArray(int *arr, int n);

int busquedaBinaria(int arr[], int n, int clave) {
    int inicio = 0;
    int fin = n - 1; // n es el tamaño del array
    int contador_intentos = 0;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2; // Evita desbordamiento de entero

        // Comprobar si la clave está presente en el medio
        if (arr[medio] == clave) {
            printf("Cantidad de intentos: %d.\n", contador_intentos);
            return medio; // Retorna el índice del elemento encontrado
        }

        // Si la clave es mayor, buscar en la mitad derecha
        if (arr[medio] < clave) {
            inicio = medio + 1;
        }
        // Si la clave es menor, buscar en la mitad izquierda
        else {
            fin = medio - 1;
        }
        contador_intentos++;
    }

    // Si no se encuentra el elemento
    printf("Cantidad de intentos: %d.\n", contador_intentos);
    return -1;
}

int main() {
    int n = 12;

    int array[] = {2, 1, 9, 6, 4, 77, 89, 23, 41, 78, 21, 15};

    printf("Array sin ordenar.\n");
    mostrarArray(array, n);

    bubbleSort(array, n);

    printf("Array ordenado.\n");
    mostrarArray(array, n);

    // IMPLEMENTACION DE BUSQUEDA BINARIA.
    int elem;
    
    printf("Ingrese el elemento que desea buscar: ");
    scanf("%d", &elem);
    getchar();

    if(busquedaBinaria(array, n, elem) > 0) {
        printf("Se ha podido encontrar el elemento.\n");
    }
    else {
        printf("NO se pudo encotrar el elemento.\n");
    }

    return 0;
}

void bubbleSort(int *arr, int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void mostrarArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}