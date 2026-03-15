#include <stdio.h>
#include <string.h>

const int max_chars = 50;

void deleteNewLine(char *);

int main() {
    FILE *archivo;
    char cadena[max_chars];
    int option, i = 0;

    archivo = fopen("lista.txt", "w+");
    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        do {
            printf("Desea ingresar una lista de elementos del supermercado? \n0. No \n1. Si \nOpcion: ");
            scanf("%d", &option);
            getchar();
            if(option != 0 && option != 1) {
                printf("Error: opcion invalida.\n");
            }
        } while(option != 0 && option != 1);
        
        while(option) {
            i++;
            printf("Elemento [%d]: ", i);
            fgets(cadena, max_chars, stdin);
            // deleteNewLine(cadena);

            fprintf(archivo, cadena);

            do {
                printf("Desea ingresar otro de elemento del supermercado? \n0. No \n1. Si \nOpcion: ");
                scanf("%d", &option);
                getchar();
                if(option != 0 && option != 1) {
                    printf("Error: opcion invalida.\n");
                }
            } while(option != 0 && option != 1);
        }
    }
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}