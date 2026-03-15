#include <stdio.h>

#define MAX 7

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void recSerpent(int mat[][MAX], int, int);

int main() {
    int A[MAX][MAX], n = 3, m = 3;

    recSerpent(A, n, m);

    printMat(A, n, m);

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
void recSerpent(int mat[][MAX], int f, int c) {
    int i = 0, j = 0, cont_casillas = 0;
    while(cont_casillas <= (f * c)) {
        for(i = 0; i <= (f - 1); i++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            cont_casillas++;
        }
        if(cont_casillas == (f * c)) {
            break;
        }
        j++;
        for(i = (f - 1); i >= 0; i--) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            cont_casillas++;
        }
        j++;
        if(cont_casillas == (f * c)) {
            break;
        }
    }
    
}