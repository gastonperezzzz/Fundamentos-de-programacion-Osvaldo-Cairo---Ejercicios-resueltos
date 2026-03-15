#include <stdio.h>

#define MAX 7

void cargaMat(int mat[][MAX], int, int);
void printMat(int mat[][MAX], int, int);
void recoEspiral(int mat[][MAX], int, int);

int main() {
    int A[MAX][MAX];
    int n, m;

    do {
        printf("Ingrese el numero de filas: ");
        scanf("%d", &m);
    } while(m < 1 || m > MAX);

    do {
        printf("Ingrese el numero de filas: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAX);

    recoEspiral(A, m, n);
    printMat(A, m, n);

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
void recoEspiral(int mat[][MAX], int f, int c) {
int i, j;
    int top = 0, bottom = f - 1, left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        // Llenar la fila superior de izquierda a derecha
        for (j = left; j <= right; j++) {
            printf("Posicion [%d][%d]: ", top, j);
            scanf("%d", &mat[top][j]);
        }
        top++;  // Mover el límite superior hacia abajo

        // Llenar la columna derecha de arriba hacia abajo
        for (i = top; i <= bottom; i++) {
            printf("Posicion [%d][%d]: ", i, right);
            scanf("%d", &mat[i][right]);
        }
        right--;  // Mover el límite derecho hacia la izquierda

        // Llenar la fila inferior de derecha a izquierda (si hay filas restantes)
        if (top <= bottom) {
            for (j = right; j >= left; j--) {
                printf("Posicion [%d][%d]: ", bottom, j);
                scanf("%d", &mat[bottom][j]);
            }
            bottom--;  // Mover el límite inferior hacia arriba
        }

        // Llenar la columna izquierda de abajo hacia arriba (si hay columnas restantes)
        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                printf("Posicion [%d][%d]: ", i, left);
                scanf("%d", &mat[i][left]);
            }
            left++;  // Mover el límite izquierdo hacia la derecha
        }
    }
}