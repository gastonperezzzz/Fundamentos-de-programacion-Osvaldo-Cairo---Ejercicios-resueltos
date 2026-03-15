#include <stdio.h>

#define MAX 10

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void transpMat(int mat[][MAX], int mat_transp[][MAX], int, int);

int main() {
    int A[MAX][MAX], A_t[MAX][MAX];
    int fil, col;

    do {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &fil);
    } while(fil < 1 || fil > MAX);

    do {
        printf("Ingrese el numero de columnas de la matriz: ");
        scanf("%d", &col);
    } while(col < 1 || col > 10);

    cargaMat(A, fil, col);
    transpMat(A, A_t, fil, col);
    printMat(A_t, col, fil);

    return 0;
}
void cargaMat(int mat[][MAX], int f, int c) {
    for(int i = 0; i  < f; i++) {
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
void transpMat(int mat[][MAX], int mat_transp[][MAX], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            mat_transp[j][i] = mat[i][j];
        }
    }
}