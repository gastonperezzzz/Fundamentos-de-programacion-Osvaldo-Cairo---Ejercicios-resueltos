#include <stdio.h>
#include <string.h>

const int max_chars = 50;
const int max_strings = 20;

void deleteNewLine(char *);

int main() {
    FILE *archivo, *archivo_destino;
    archivo = fopen("probPS9.5.txt", "r");
    archivo_destino = fopen("probPS9.5 (write).txt", "w");
    char cadena[max_strings][max_chars];
    int used_strings = 0;

    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        while(!(feof(archivo))) {
            fgets(cadena[used_strings], max_chars, archivo);
            deleteNewLine(cadena[used_strings]);
            used_strings++;
        }

        for(int i = 0; i < used_strings; i++) {
            fprintf(archivo_destino, "%s\n", cadena[used_strings - i - 1]);
        }
    }

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}