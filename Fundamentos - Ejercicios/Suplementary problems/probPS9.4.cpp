#include <stdio.h>
#include <string.h>

const int max_chars = 50;

int main() {
    FILE *archivo;
    char cadena[max_chars], subcadena[] = "gaston", cad_aux[max_chars] = "";
    char *palabra;
    int cont_palabras = 0;

    archivo = fopen("probPS9.4.txt", "r");

    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        while(!(feof(archivo))) {
            fgets(cadena, max_chars, archivo);
            palabra = strstr(cadena, subcadena);
            strncpy(cad_aux, palabra, strlen(subcadena));
            if(!(strcmp(subcadena, cad_aux))) {
                cont_palabras++;
            }
        }
        printf("La palabra se encuentra %d veces en el archivo.\n", cont_palabras);
        fclose(archivo);
    }

    return 0;
}