#include <stdio.h>

#define MAX 10

void cargaMat(int mat[][MAX], int);
void diagUno(int mat[][MAX], int);
void printMat(int mat[][MAX], int);

int main() {
    int A[MAX][MAX], N;

    do {
        printf("Ingrese el orden de la matriz: ");
        scanf("%d", &N);
        if(N < 1 || N > MAX) {
            printf("Error: tamaño invalido.\n");
        }
    } while(N < 1 || N > MAX);

    cargaMat(A, N);
    diagUno(A, N);
    printMat(A, N);

    return 0;
}

void cargaMat(int mat[][MAX], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int mat[][MAX], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void diagUno(int mat[][MAX], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            mat[i][j] = 0;
            if(i == j) {
                mat[i][j] = 1;
            }
            mat[i][N - i - 1] = 1;
        }
    }
}