#include <stdio.h>

#define T 4

void cargaMat(int mat[][T], int, int);
void printMat(int mat[][T], int, int);
void printVec(float *, int);
void calulation(int mat[][T], float *, int);
float mod1(int mat[][T], int);
float mod2(int mat[][T], int, int);
float modAny(int mat[][T], int, int);

int main() {
    int A[T][T];
    float vec[T];

    cargaMat(A, T, T);
    calulation(A, vec, T);
    printVec(vec, T);

    return 0;
}

void cargaMat(int mat[][T], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Posicion [%d][%d] | Valor: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int mat[][T], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void calulation(int mat[][T], float *arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i % 3 == 1) {
                arr[i] = mod1(mat, i);
            }
            else if(i % 3 == 2) {
                arr[i] = mod2(mat, i, size);
            }
            else {
                arr[i] = modAny(mat, i, size);
            }
        }
    }
}
float mod1(int mat[][T], int ite) {
    int i;
    float sum = 0;
    for(i = 0; i <= ite; i++) {
        sum += mat[ite][i];
    }
    return sum;
}
float mod2(int mat[][T], int ite, int size) {
    float prod = 1;
    for(int i = 0; i < size; i++) {
        prod *= mat[i][ite];
    }
    return prod;
}
float modAny(int mat[][T], int ite, int size) {
    float sum = 0, prod = 1;
    for(int i = 0; i < size; i++) {
        prod *= mat[i][ite];
        sum += mat[i][ite];
    }
    return (prod / sum);
}
void printVec(float *arr, int size) {
    for(int i = 0; i < size; i++)
        printf("Posicion [%d]: %.2f\n", i, arr[i]);
}