#include <stdio.h>
#include <math.h>

#define MAX 7

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void productoMatrices(int mat1[][MAX], int mat2[][MAX], int mat3[][MAX], int, int, int);

int main() {
    int n, m, p;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    do {
        printf("Ingrese el numero de filas de la 1ra matriz: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAX); 

    do {
        printf("Ingrese el numero de columnas de la primera matriz y filas de la segunda: ");
        scanf("%d", &m);
    } while(m < 1 || m > MAX);

    do {
        printf("Ingrese el numero de columnas de la segunda matriz: ");
        scanf("%d", &p);
    } while(p < 1 || p > MAX);

    cargaMat(A, n, m);
    cargaMat(B, m, p);
    printMat(C, n, p);
    productoMatrices(A, B, C, n, m, p);
    printMat(C, n, p);

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
void productoMatrices(int mat1[][MAX], int mat2[][MAX], int mat3[][MAX], int f, int c, int p) {
    int i, j, k;
    for(i = 0; i < f; i++) {
        for(j = 0; j < p; j++) { // f = n | c = m | p = p
            for(k = 0; k < c; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}