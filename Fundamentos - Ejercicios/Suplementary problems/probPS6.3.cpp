#include <stdio.h>

#define MAX 10

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void swapFilas(int mat[][MAX], int, int);

int main() {
    int matA[MAX][MAX], n, m;

    do {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAX);

    do {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &m);
    } while(m < 1 || m > MAX);

    cargaMat(matA, n, m);
    printf("Matriz inicial...\n");
    printMat(matA, n, m);
    printf("\n");
    swapFilas(matA, n, m);
    printf("Matriz resultante...\n");
    printMat(matA, n, m);

    return 0;
}

void cargaMat(int mat[][MAX], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int mat[][MAX], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void swapFilas(int mat[][MAX], int f, int c) {
    int i, j, aux;
    for(i = 0; i < (f / 2); i++) {
        for(j = 0; j < c; j++) {
            aux = mat[i][j];
            mat[i][j] = mat[f - i - 1][j];
            mat[f - i - 1][j] = aux;
        }
    }
}