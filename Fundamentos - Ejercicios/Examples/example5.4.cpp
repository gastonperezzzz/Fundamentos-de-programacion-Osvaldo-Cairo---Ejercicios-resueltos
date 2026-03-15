#include <stdio.h>
#define MAX 10

void lectura(int arr[], int size);
void imprimir(int arr[], int size);
void producto(int *, int *, int *, int);
void newLine(void);

int main() {
    int vec1[MAX], vec2[MAX], vec3[MAX];

    lectura(vec1, MAX);
    newLine();
    lectura(vec2, MAX);
    producto(vec1, vec2, vec3, MAX);
    newLine();
    imprimir(vec3, MAX);

    return 0;
}

void lectura(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void imprimir(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d] = %d\n", i, arr[i]);
    }
}
void producto(int *a, int *b, int *c, int size) {
    for(int i = 0; i < size; i++) {
        c[i] = a[i] * b[i];
    }
}
void newLine(void) {
    printf("\n");
}