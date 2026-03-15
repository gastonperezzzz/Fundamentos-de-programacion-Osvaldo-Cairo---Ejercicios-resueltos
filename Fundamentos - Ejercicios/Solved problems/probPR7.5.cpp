#include <stdio.h>
#include <stdlib.h>

int cantidadChar(char *cad);

int main() {
    char cadena[50];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    printf("La cadena tiene una longitud de %d caracteres.\n", cantidadChar(cadena));

    return 0;
}

int cantidadChar(char *cad) {
    int acu = 0;
    while(cad[acu] != '\0') {
        acu++;
    }

    return acu - 1;
}