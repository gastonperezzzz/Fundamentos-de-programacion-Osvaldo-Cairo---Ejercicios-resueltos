#include <stdio.h>

void cargaVec(int *, int);
void printVec(int *, int);
void arrayElementInsert(int *, int *, int);
void arrayElementDelete(int *, int *, int);

int main() {
    int tam, element, option;

    do {
        printf("Ingrese el tamaño del array: ");
        scanf("%d", &tam);
        if(tam < 1 || tam > 100) {
            printf("Error: tamaño invalido.\n");
        }
    } while(tam < 1 || tam > 100);

    int array[tam];
    cargaVec(array, tam);

    do {
        printf("1) Insertar un elemento en el array.\n2) Eliminar un elemento del array.\n");
        printf("Opcion: ");
        scanf("%d", &option);
        if(option <= 0 || option > 2) {
            printf("Error: opcion invalida.\n");
        }
    } while(option <= 0 || option > 2);

    switch(option) {
        case 1:
            printf("Ingrese el elemento que desea agregar: ");
            scanf("%d", &element);
            arrayElementInsert(array, &tam, element);
            break;
        case 2:
            printf("Ingrese el elemento que desea eliminar: ");
            scanf("%d", &element);
            arrayElementDelete(array, &tam, element);
            break;
    }
    
    printVec(array, tam);

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
void arrayElementInsert(int *arr, int *size, int elem) {
    *size = *size + 1;
    arr[*size - 1] = elem;
}
void arrayElementDelete(int *arr, int *size, int elem) {
    int control = *size;
    for(int i = 0; i < *size; i++) {
        if(arr[i] == elem) {
            for(int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            *size = *size - 1;
        }
    }
    if(control == *size) {
        printf("No se ha podido localizar el elemento a eliminar.\n");
    }
}