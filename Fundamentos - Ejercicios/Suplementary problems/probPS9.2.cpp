#include <stdio.h>
#include <ctype.h>

const int max_chars = 50;

void calcularVocales(FILE *);

int main() {
    FILE *archivo;
    archivo = fopen("probPS9.2.txt", "r");

    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        calcularVocales(archivo);
        fclose(archivo);
    }

    return 0;
}

void calcularVocales(FILE *arc) {
    char vocales_minus[] = "aeiou", vocales_mayus[] = "AEIOU";
    int cont_vocales[5] = {0};
    int i;
    char caracter;

    rewind(arc);

    while(!(feof(arc))) {
        caracter = fgetc(arc);
        for(i = 0; i < 5; i++) {
            if(caracter == vocales_minus[i] || caracter == vocales_mayus[i]) {
                cont_vocales[i]++;
            }
        }
    }

    for(i = 0; i < 5; i++) {
        printf("%c: %d\n", vocales_minus[i], cont_vocales[i]);
    }
}