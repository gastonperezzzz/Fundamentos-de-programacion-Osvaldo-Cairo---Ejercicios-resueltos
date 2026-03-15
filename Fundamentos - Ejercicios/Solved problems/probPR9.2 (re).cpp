#include <stdio.h>
#include <string.h>

int main() {
    FILE *archive;
    char c;
    int contador = 0;

    if((archive = fopen("arch.txt", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        printf("Ingrese la letra que quiere buscar en el texto: ");
        c = getchar();

        while(!feof(archive)) {
            if(fgetc(archive) == c) {
                contador++;
            }
        }
        fclose(archive);
        printf("La letra %c se repite %d veces en el archivo de texto.\n", c, contador);
    }

    return 0;
}