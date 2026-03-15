#include <stdio.h>
#define MAX 50

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void sumMat(int mat1[][MAX], int mat2[][MAX], int mat3[][MAX], int, int);

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int f, c;

    do {
        printf("Ingrese la cantidad de filas de las matrices: ");
        scanf("%d", &f);
        if(f < 1 || f > MAX) {
            printf("Error: numero invalido.\n");
        }
    } while(f < 1 || f > MAX);

    do {
        printf("Ingrese la cantidad de filas de las matrices: ");
        scanf("%d", &c);
        if(c < 1 || c > MAX) {
            printf("Error: numero invalido.\n");
        }
    } while(c < 1 || c > MAX);

    cargaMat(A, f, c);
    cargaMat(B, f, c);
    sumMat(A, B, C, f, c);
    printMat(C, f, c);


    return 0;
}

void cargaMat(int mat[][MAX], int F, int C) {
    for(int i = 0; i < F; i++) {
        for(int j = 0; j < C; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int mat[][MAX], int F, int C) {
    for(int i = 0; i < F; i++) {
        for(int j = 0; j < C; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void sumMat(int mat1[][MAX], int mat2[][MAX], int mat3[][MAX], int F, int C) {
    for(int i = 0; i < F; i++) {
        for(int j = 0; j < C; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}