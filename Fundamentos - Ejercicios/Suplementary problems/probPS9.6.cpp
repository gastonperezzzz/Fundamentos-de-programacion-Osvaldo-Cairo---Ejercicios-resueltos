#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int max_chars = 50;

void deleteNewLine(char *);
void ortografia(FILE *);

int main() {
    FILE *archivo;
    char cadena[max_chars];

    archivo = fopen("doc.txt", "w+");

    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        fprintf(archivo, "Me empape al jugar con mbappe");
        ortografia(archivo);
        rewind(archivo);
        fgets(cadena, max_chars, archivo);
        puts(cadena);
        fclose(archivo);
    }

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void ortografia(FILE *archive) {
    char cadena[max_chars];
    int long_cadena, cont_err = 0;

    rewind(archive);
    while(!(feof(archive))) {
        fgets(cadena, max_chars, archive);
        deleteNewLine(cadena);

        long_cadena = strlen(cadena);

        for(int i = 0; i < long_cadena; i++) {
            if(islower(cadena[i])) {
                if((cadena[i] == 'n') && (cadena[i + 1] == 'b')) {
                    cont_err++;
                }
                else if((cadena[i] == 'n') && (cadena[i + 1] == 'p')) {
                    cont_err++;
                }
                else if((cadena[i] == 'm') && (cadena[i + 1] == 'v')) {
                    cont_err++;
                }
            }
            else if(isupper(cadena[i])) {
                if((cadena[i] == 'N') && (cadena[i + 1] == 'B')) {
                    cadena[i] = 'M';
                    cont_err++;
                }
                else if((cadena[i] == 'N') && (cadena[i + 1] == 'P')) {
                    cont_err++;
                }
                else if((cadena[i] == 'M') && (cadena[i + 1] == 'V')) {
                    cont_err++;
                }
            }
        }
    }

    if(cont_err == 0) {
        printf("El archivo sigue las reglas ortograficas.\n");
    }
    else {
        printf("El archivo tiene errores ortograficos.\n");
    }
}