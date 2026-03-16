#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void generarMatriz(char mat[][N], char *);
void mostrarMatriz(char mat[][N]);
void mostrarArray(int *);
void conteoColores(char mat[][N], char *, int *);
void guardarEnArchivo(int *, int *, int);

int main() {
    char matrizColores[N][N];
    char colores[] = "RGBY";
    int cont_colores[sizeof(colores)];

    generarMatriz(matrizColores, colores);
    mostrarMatriz(matrizColores);


    return 0;
}

void generarMatriz(char mat[][N], char *arrayCol) {
    int i, j;
    int size = sizeof(arrayCol);
    srand(time(NULL));
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            mat[i][j] = arrayCol[rand() % size];
        }
    }
}
void mostrarMatriz(char mat[][N]) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void mostrarArray(int *array) {
    int size = sizeof(array) / sizeof(int);
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void conteoColores(char mat[][N], char *arrayCol, int *arrayCont) {
    int i, j, k;
    int cantidad_colores = sizeof(arrayCol) / sizeof(int);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            for(k = 0; k < cantidad_colores; j++) {
                if(mat[i][j] == arrayCol[k]) {
                    arrayCont[k]++;
                }
            }
        }
    }
}