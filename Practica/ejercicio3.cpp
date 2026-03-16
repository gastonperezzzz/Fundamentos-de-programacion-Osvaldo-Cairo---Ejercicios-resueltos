// ALUMNO: Perez Mercado Gaston Ezequiel
// Carrera: LSI

#include <stdio.h>
#include <math.h>

#define N 10

typedef struct {
    int x;
    int y;
} Punto;

int valorAbsoluto(int); // Funcion provisional. En 'math.h' no existe abs() para enteros.
void mostrarMatriz(Punto mat[][N], int);
void mostrarDistancias(int mat[][N], int);
void generarMatriz(Punto mat[][N], int);
void calcularDistancias(Punto mat[][N], int mat_dist[][N], int);
void guardarMatriz(int mat_dist[][N], int);

int main() {
    Punto matriz[N][N];
    int matriz_distancias[N][N];
    int opcion;
    
    do {
        printf("OPTIMIZACION DE RUTAS.\n");
        printf("1. Generar matriz.\n");
        printf("2. Mostrar matriz.\n");
        printf("3. Calcular distancias de Manhattan.\n");
        printf("4. Mostrar matriz de distancias.\n");
        printf("5. Guardar matriz de distancias en archivo de texto y binario.\n");
        printf("0. Salir.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                generarMatriz(matriz, N);
                printf("Matriz generada exitosamente.\n");
                break;
            case 2:
                mostrarMatriz(matriz, N);
                break;
            case 3:
                calcularDistancias(matriz, matriz_distancias, N);
                printf("Matriz de distancias calculada exitosamente.\n");
                break;
            case 4:
                mostrarDistancias(matriz_distancias, N);
                break;
            case 5:
                guardarMatriz(matriz_distancias, N);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 0);


    return 0;
}

void mostrarMatriz(Punto mat[][N], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("(%d, %d) ", mat[i][j].x, mat[i][j].y);
        }
        printf("\n");
    }
}
void generarMatriz(Punto mat[][N], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            mat[i][j].x = i;
            mat[i][j].y = j;
        }
    }
}
void calcularDistancias(Punto mat[][N], int mat_dist[][N], int size) {
    int i, j;
    Punto origen;
    do {
        printf("Ingrese el punto de origen (x, y) para sacar distancias de Manhattan: \n");
        printf("x = ");
        scanf("%d", &origen.x);
        printf("y = ");
        scanf("%d", &origen.y);
        getchar();

        if(origen.x > N - 1 || origen.y > N - 1) {
            printf("Coordenadas invalidas. Intente de nuevo.\n");
        }
    } while((origen.x > N - 1) || (origen.y > N - 1));

    mat[origen.x][origen.y].x = 0;
    mat[origen.x][origen.y].y = 0;
    printf("Punto de origen establecido.\n");

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            mat_dist[i][j] = valorAbsoluto(origen.x - i) + valorAbsoluto(origen.y - j);
        }
    }
}
int valorAbsoluto(int n) {
    if(n < 0) {
        return (n * (- 1));
    }
    else {
        return n;
    }
}
void mostrarDistancias(int mat[][N], int) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void guardarMatriz(int mat_dist[][N], int size) {
    FILE *pTexto;
    FILE *pBin;
    int i, j;

    pTexto = fopen("distancias_texto.txt", "w");

    // Primero guardamos la matriz de distancias en el archivo de texto.

    if(pTexto == NULL) {
        printf("No se ha podido abrir el archivo de texto.\n");
        fclose(pTexto);
    }
    else {
        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                fprintf(pTexto, "%d ", mat_dist[i][j]);
            }
            fprintf(pTexto, "\n");
        }
        printf("Matriz guardada en archivo de texto exitosamente.\n");
        fclose(pTexto);
    }

    // Ahora guardamos la matriz pero un el archivo binario.

    pBin = fopen("distancias_binario.bin", "wb");

    if(pBin == NULL) {
        printf("No se ha podido abrir el archivo binario.\n");
        fclose(pBin);
    }   
    else {
            for(i = 0; i < size; i++) {
                fwrite(mat_dist[i], sizeof(int), size, pBin);
            }
    }

    printf("Matriz guardada en archivo binario exitosamente.\n");
    fclose(pBin);
}