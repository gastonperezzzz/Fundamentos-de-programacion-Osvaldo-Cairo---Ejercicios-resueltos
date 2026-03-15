#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int max_chars = 50;

void conteoPalabras(FILE *);

int main() {
    FILE *archivo;

    archivo = fopen("probPS9.3.txt", "r");

    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        conteoPalabras(archivo);
        fclose(archivo);
    }

    return 0;
}

void conteoPalabras(FILE *ar) {
    int cont_palabras = 0, long_cadena;
    char cadena[max_chars];

    while(!(feof(ar))) {
        fgets(cadena, max_chars, ar);
        long_cadena = strlen(cadena);
        for(int i = 0; i < long_cadena; i++) {
            if((isalpha(cadena[i]) && cadena[i + 1] == ' ') || (isalpha(cadena[i]) && cadena[i + 1] == '\n') || (isalpha(cadena[i]) && cadena[i + 1] == '\0')) {
                cont_palabras++;
            }
        }
    }

    printf("Cantidad de palabras: %d\n", cont_palabras);
}