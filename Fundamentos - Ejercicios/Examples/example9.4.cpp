#include <stdio.h>

const int max_chars = 50;

int main() {
    char cad[max_chars];
    FILE *archivo;
    archivo = fopen("arc.txt", "r");

    if(archivo == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        while(!feof(archivo)) {
            fgets(cad, max_chars, archivo);
            printf("%s", cad);
        }
        fclose(archivo);
    }

    return 0;
}