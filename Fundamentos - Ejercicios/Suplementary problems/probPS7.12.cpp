#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deleteNewLine(char *);

const int max_strings = 3;
const int max_chars = 50;

int main() {
    char arc[max_strings][max_chars], aux[max_chars];
    int i, j, string_length;
    int str_mayor_mayus = 0, indice_mayor_mayus = 0, cont_mayus;

    for(i = 0; i < max_strings; i++) {
        printf("Ingrese la cadena de caracteres [%d]: ", i);
        fgets(arc[i], max_chars, stdin);
        deleteNewLine(arc[i]);
        strcpy(aux, arc[i]);
        string_length = strlen(aux);
        cont_mayus = 0;
        for(j = 0; j < string_length; j++) {
            if(isupper(aux[j])) {
                cont_mayus++;
            }
        }
        if(cont_mayus > str_mayor_mayus) {
            str_mayor_mayus = cont_mayus;
            indice_mayor_mayus = i;
        }
    }

    printf("La cadena con el mayor numero de mayusculas es:\n");
    puts(arc[indice_mayor_mayus]);
    printf("Con un total de %d mayusculas.\n", str_mayor_mayus);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}