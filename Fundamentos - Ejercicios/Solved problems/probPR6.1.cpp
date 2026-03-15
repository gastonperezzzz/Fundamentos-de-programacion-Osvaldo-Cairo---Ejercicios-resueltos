#include <stdio.h>

#define N 10

void cargaMat(int mat[][N], int, int);
void printMat(int mat[][N], int, int);
int matSimetrica(int mat[][N], int);

int main() {
    int size, A[N][N];

    do {
        printf("Ingrese el tamaño de la matriz [cuadrada]: ");
        scanf("%d", &size);
        if(size <= 0 || size > 10) {
            printf("Error: tamaño invalido.\n");
        }
    } while(size <= 0 || size > N);

    cargaMat(A, size, size);
    
    if(matSimetrica(A, size)) {
        printf("Es una matriz simetrica.\n");
    }
    else {
        printf("No es una matriz simetrica.\n");
    }

    printMat(A, size, size);

    return 0;
}

void cargaMat(int mat[][N], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int mat[][N], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int matSimetrica(int mat[][N], int n) {
    int sim = 0, flag = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == mat[j][i]) {
                sim++;
            }
        }
    }
    if(sim == n * n) {
        flag = 1;
    }
    return flag;
}