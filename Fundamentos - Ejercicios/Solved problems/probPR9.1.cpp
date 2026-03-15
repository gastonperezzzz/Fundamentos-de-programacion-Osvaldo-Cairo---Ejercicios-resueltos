#include <stdio.h>

int main() {
    FILE *archivo;
    char c;

    archivo = fopen("libro.txt", "a");

    if(archivo == NULL) {
        printf("Error: no se ha podido abrir el archivo.\n");
    }
    else {
        while((c = getchar()) != '\n') {
            fputc(c, archivo);
        }
        fclose(archivo);
    }


    return 0;
}