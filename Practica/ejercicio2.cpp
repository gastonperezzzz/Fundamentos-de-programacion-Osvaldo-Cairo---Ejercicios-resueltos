// ALUMNO: Perez Mercado Gaston Ezequiel
// Carrera: LSI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void generarMatrizLetras(char matriz[][N], int);
void mostrarMatriz(char matriz[][N], int);
void mostrarComp(char *, int);
int compararComp(char *, char, int);
void extraerComponentes(char matriz[][N], char *, int);
void ordenamientoAlfabetico(char *, int);
void guardarTxt(char *, int);
void guardarBin(char *, int);

int main() {
    char mat[N][N];
    char lista_componentes[N];
    int opcion;

    do {
        printf("GESTION DE INVENTARIO ELECTRONICO.\n");
        printf("1. Generar Matriz.\n");
        printf("2. Extraer componentes unicos.\n");
        printf("3. Mostrar componentes.\n");
        printf("4. Ordenar alfabeticamente la lista de componentes extraidos.\n");
        printf("5. Guardar lista en un archivo de texto.\n");
        printf("6. Guardar lista en un archivo binario.\n");
        printf("0. Salir.\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 0:
                printf("Saliendo del programa...\n");
                break;
            case 1:
                generarMatrizLetras(mat, N);
                break;
            case 2:
                extraerComponentes(mat, lista_componentes, N);
                break;
            case 3:
                mostrarComp(lista_componentes, N);
                break;
            case 4:
                ordenamientoAlfabetico(lista_componentes, N);
                printf("Lista ordenada exitosamente.\n");
                break;
            case 5:
                guardarTxt(lista_componentes, N);
                printf("Lista guardada en archivo de texto exitosamente.\n");
                break;
            case 6:
                guardarBin(lista_componentes, N);
                printf("Lista guardada en archivo binario exitosamente.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
            
        }
    } while(opcion != 0);
    
    return 0;
}

void generarMatrizLetras(char matriz[][N], int size) {
    srand(time(NULL));

    const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriz[i][j] = letras[rand() % 26];
        }
    }

    printf("Matriz generada exitosamente.\n\n");
}
void mostrarMatriz(char matriz[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}
void mostrarComp(char *lista, int size) {
    printf("Lista de componentes unicos:\n");
    for(int i = 0; i < size; i++) {
        printf("%c ", lista[i]);
    }
    printf("\n");
}
int compararComp(char *lista, char c, int size) {
    for(int i = 0; i < size; i++) {
        if(lista[i] == c) {
            return 0;
        }
    }
    return 1;
}
void extraerComponentes(char matriz[][N], char *lista, int size) {
    int i, j, k = 0;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size && k < N; j++) {
            if(compararComp(lista, matriz[i][j], k)) {
                lista[k] = matriz[i][j];
                k++;
            }
        }
    }
}
void ordenamientoAlfabetico(char *lista, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size - 1 - i; j++) {
            if(lista[j] > lista[j + 1]) {
                char temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}
void guardarTxt(char *lista, int size) {
    FILE *pArchivo;
    pArchivo = fopen("lista_ordenada.txt", "a");

    if(pArchivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        fprintf(pArchivo, "Lista de componentes ordenada:\n");
        for(int i = 0; i < size; i++) {
            fprintf(pArchivo, "%c ", lista[i]);
        }
    }

    fclose(pArchivo);
}
void guardarBin(char *lista, int size) {
    FILE *pArchivo;
    pArchivo = fopen("lista_ordenada.bin", "ab");

    if(pArchivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        for(int i = 0; i < size; i++) {
            fwrite(lista, sizeof(lista), 1, pArchivo);
        }
    }
}