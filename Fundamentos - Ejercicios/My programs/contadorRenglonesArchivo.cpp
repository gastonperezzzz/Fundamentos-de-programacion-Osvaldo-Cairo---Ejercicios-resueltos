#include <stdio.h>
#include <string.h>

const int max_chars = 50;

void deleteNewLine(char *);
int contadorStrings(FILE *);

int main() {
    FILE *apuntador;

    apuntador = fopen("prueba.txt", "r");

    if(apuntador == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }
    else {
        printf("El archivo tiene %d strings.\n", contadorStrings(apuntador));
        fclose(apuntador);
    }

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
int contadorStrings(FILE *pointer) {
    char cadena[max_chars];
    int contador = 0;

    while(!(feof(pointer))) {
        fgets(cadena, max_chars, pointer);
        contador++;
    }

    return contador;
}