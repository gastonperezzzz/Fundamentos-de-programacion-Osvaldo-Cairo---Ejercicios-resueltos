#include <stdio.h>

int cuenta(char *);

int main() {
    char cadena[50];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    printf("La cadena tiene %d caracteres.\n", cuenta(cadena));

    return 0;
}

int cuenta(char *cad) {
    if(cad[0] == '\0') {
        return 0;
    }
    else {
        return (1 + cuenta(&cad[1]));
    }
}