#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cadena[50];
    int i = 0;

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    while(cadena[i] != '\0') {
        if(i % 2 == 0) {
            if(isdigit(cadena[i])) {
                putchar(cadena[i]);
            }
        }
        i++;
    }
    printf("\n");

    return 0;
}