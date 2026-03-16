// ALUMNO: Perez Mercado Gaston Ezequiel
// Carrera: LSI

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 3

// PROTOTIPO DE FUNCIONES.
void cargarMatriz(int mat[][N], int);
void mostrarMatriz(int mat[][N], int);
void transpuesta(int mat[][N], int mat_t[][N], int);
int sumaDiagPrincipal(int mat[][N], int);
int sumaDiagSec(int mat[][N], int);
void buscarValor(int mat[][N], int);
int det3x3(int m[][N]);
void guardarEnArchivo(int mat[][N], int);

// PROGRAMA PRINCIPAL.
int main() {
    int matriz[N][N], mat_transp[N][N];
    int opcion;
    
    do {
        printf("0. Salir.\n");
        printf("1. Cargar la matriz.\n");
        printf("2. Mostrar matriz.\n");
        printf("3. Calcular y mostrar transpuesta y determinante.\n");
        printf("4. Mostrar transpuesta.\n");
        printf("5. Calcular y mostrar elementos de la diagonal principal y secundaria.\n");
        printf("6. Buscar un valor en la matriz.\n");
        printf("7. Guardar matriz y diagonal principal en archivo.\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
        case 0:
            printf("Saliendo del programa...\n");
            break;
        case 1:
            cargarMatriz(matriz, N);
            break;
        case 2:
            mostrarMatriz(matriz, N);
            break;
        case 3:
            transpuesta(matriz, mat_transp, N);
            mostrarMatriz(mat_transp, N);
            printf("Determinante: %d\n", det3x3(matriz));
            break;
        case 4:
            mostrarMatriz(mat_transp, N);
            break;
        case 5:
            printf("Suma diagonal principal: %d\n", sumaDiagPrincipal(matriz, N));
            printf("Suma diagonal secundaria: %d\n", sumaDiagSec(matriz, N));
            break;
        case 6:
            buscarValor(matriz, N);
            break;
        case 7:
            guardarEnArchivo(matriz, N);
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }

    } while(opcion != 0);

    return 0;
}


// DEFININICION DE FUNCIONES.
void cargarMatriz(int mat[][N], int size) {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            mat[i][j] = (rand() % 100) + 1;
        }
    }
    printf("Matriz generada correctamente.\n");
}

void mostrarMatriz(int mat[][N], int size) {
    int i, j;
    printf("\n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpuesta(int mat[][N], int mat_t[][N], int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            mat_t[j][i] = mat[i][j];
        }
    }
}

int sumaDiagPrincipal(int mat[][N], int size) {
    int sumatoria = 0;
    for(int i = 0; i < size; i++) {
        sumatoria += mat[i][i];
    }

    return sumatoria;
}

int sumaDiagSec(int mat[][N], int size) {
    int sumatoria = 0;
    for(int i = 0; i < size; i++) {
        sumatoria += mat[i][size - 1 - i];
    }

    return sumatoria;
}

void buscarValor(int mat[][N], int size) {
    int key, flag = 0;
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &key);
    getchar();

    int i_elemento, j_elemento;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(mat[i][j] == key) {
                i_elemento = i;
                j_elemento = j;
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0) {
        printf("Valor no encontrado.\n");
        
    }
    else {
        printf("Valor [%d] encontrado.\n", key);
        printf("Fila: %d | Columna: %d\n.", i_elemento, j_elemento);
    }
}

int det3x3(int m[][N]) {
    int det;
    det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
          m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
          m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    return det;
}
void guardarEnArchivo(int mat[][N], int size) {
    FILE *pArchivo;
    FILE *pArchivo2;

    pArchivo = fopen("reporte_sensores.txt", "a");
    pArchivo2 = fopen("diagonal_sensores.bin", "ab");

    if(pArchivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                fprintf(pArchivo, "%d ", mat[i][j]);
                if(i == j) {
                    fwrite(&mat[i][j], sizeof(int), 1, pArchivo2);
            }
            fprintf(pArchivo, "\n");
        }
    }
    fprintf(pArchivo, "Determinante: %d\n", det3x3(mat));

    fclose(pArchivo);
    fclose(pArchivo2);
    printf("Datos guardados en archivo correctamente.\n");
    }
}