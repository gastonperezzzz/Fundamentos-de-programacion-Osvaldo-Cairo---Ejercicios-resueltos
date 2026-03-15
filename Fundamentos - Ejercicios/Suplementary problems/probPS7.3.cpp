#include <stdio.h>
#include <string.h>

const int max_chars = 30;

void autoComplete(char *, int);

int main() {
    char cad[max_chars];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    if(cad[strlen(cad) - 1] == '\n') {
        cad[strlen(cad) - 1] = '\0';
    }

    puts(cad);

    autoComplete(cad, max_chars);

    puts(cad);

    return 0;
}

void autoComplete(char *string, int chars) {
    int i = 0, j = 0, cont = 0;
    while(string[i] != '\0') {
        cont++;
        i++;
    }
    for(j = cont; j < chars; j++) {
        string[j] = '-';
    }
}