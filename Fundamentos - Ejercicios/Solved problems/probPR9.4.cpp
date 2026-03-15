#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minymay(FILE *);

int main() {
    FILE *archive;

    if((archive = fopen("arc5.txt", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        minymay(archive);
        fclose(archive);
    }

    return 0;
}

void minymay(FILE *ar) {
    char cadena[50];
    int minusculas = 0, mayusculas = 0, total = 0;
    int lenstr;

    while(!(feof(ar))) {
        fgets(cadena, 50, ar);
        lenstr = strlen(cadena);
        for(int i = 0; i < lenstr; i++) {
            if(isalpha(cadena[i])) {
                total++;
                if(isupper(cadena[i])) {
                    mayusculas++;
                }
                else if(islower(cadena[i])) {
                    minusculas++;
                }
            }
        }
    }
    printf("Mayusculas: %d | Minusculas: %d | Total: %d \n", mayusculas, minusculas, total);
}