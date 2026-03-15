#include <stdio.h>

#define MAX 7

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void TranspMat(int mat1[][MAX], int mat_transp[][MAX], int, int);
void sumaMatrices(int mat1[][MAX], int mat2[][MAX], int mat_res[][MAX], int, int);

int main() {
    int m, n;
    int A[MAX][MAX], B[MAX][MAX], B_t[MAX][MAX], C[MAX][MAX];

    do {
        printf("Ingrese las filas de la 1er matriz (columnas de la segunda): ");
        scanf("%d", &m);
    } while(m < 1 || m > MAX);

    do {
        printf("Ingrese las columnas de la 1er matriz (filas de la segunda): ");
        scanf("%d", &n);
    } while(n < 1 || n > MAX);

    cargaMat(A, m, n);
    cargaMat(B, n, m);
    TranspMat(B, B_t, m, n);
    sumaMatrices(A, B_t, C, m, n);
    printMat(C, m, n);

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
void TranspMat(int mat1[][MAX], int mat_transp[][MAX], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            mat_transp[i][j] = mat1[j][i];
        }
    }
}
void sumaMatrices(int mat1[][MAX], int mat2[][MAX], int mat_res[][MAX], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            mat_res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}