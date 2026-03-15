#include <stdio.h>

#define MAX 10

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void swapCol(int mat[][MAX], int, int);

int main() {
    int n, m, A[MAX][MAX];

    do {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &n);
        if(n < 1 || n > MAX) {
            printf("Error: numero invalido.\n");
        }
    } while(n < 1 || n > MAX);

        do {
        printf("Ingrese el numero de columnas de la matriz: ");
        scanf("%d", &m);
        if(m < 1 || m > MAX) {
            printf("Error: numero invalido.\n");
        }
    } while(m < 1 || m > MAX);

    cargaMat(A, n, m);
    printMat(A, n, m);
    swapCol(A, n, m);
    printf("\n");
    printMat(A, n, m);

    return 0;
}

void cargaMat(int mat[][MAX], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Posicion [%d][%d] | Valor: ", i, j);
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
void swapCol(int mat[][MAX], int f, int c) {
    int aux;
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < (c / 2); j++) {
            aux = mat[i][c - j - 1];
            mat[i][c - j - 1] = mat[i][j];
            mat[i][j] = aux;
        }
    }
}