#include <stdio.h>

#define MAX 15

void printMat(int mat[][MAX], int);
void cuadradoMagico(int mat[][MAX], int);

int main() {
    int A[MAX][MAX], tam;

    do {
        printf("Ingrese el orden de la matriz (impar): ");
        scanf("%d", &tam);
    } while((tam < 1 || tam > MAX) || (tam % 2 == 0));

    cuadradoMagico(A, tam);
    printMat(A, tam);

    return 0;
}

void printMat(int mat[][MAX], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void cuadradoMagico(int mat[][MAX], int N) {
    int i = 1, fil = 0, col = N / 2;
    int num = N * N;

    while(i <= num) {
        mat[fil][col] = i;
        if(i % N != 0) {
            fil = (fil - 1 + N) % N;
            col = (col - 1) % N;
        }
        else {
            fil++;
            i++;
        }
    }
}