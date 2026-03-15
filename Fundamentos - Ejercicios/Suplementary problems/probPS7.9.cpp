#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deleteNewLine(char *);
void strInverse(char *);
void strClean(char *);

const int max_chars = 50;

int main() {
    char cad[max_chars] = "", cad_aux[max_chars] = "", cad_inverse[max_chars];
    int i, j = 0;

    printf("Ingrese una cadena de caracteres para invertirla: ");
    fgets(cad, max_chars, stdin);
    deleteNewLine(cad);
    strInverse(cad);

    int cad_len = strlen(cad) + 1;

    for(i = 0; i < cad_len; i++) {
        if(isalpha(cad[i])) {
            cad_aux[j] = cad[i];
            j++;
        }
        else {
            strInverse(cad_aux);
            strcat(cad_inverse, cad_aux);
            strcat(cad_inverse, " ");
            strClean(cad_aux);
            j = 0;
        }
    }

    puts(cad_inverse);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void strInverse(char *string) {
    int i, length_str = strlen(string);
    char aux;
    for(i = 0; i < (length_str / 2); i++) {
        aux = string[i];
        string[i] = string[length_str - 1 - i];
        string[length_str - 1 - i] = aux;
    }
}
void strClean(char *string) {
    int len = strlen(string);
    for(int i = 0; i < len; i++) {
        string[i] = 0;
    }
}