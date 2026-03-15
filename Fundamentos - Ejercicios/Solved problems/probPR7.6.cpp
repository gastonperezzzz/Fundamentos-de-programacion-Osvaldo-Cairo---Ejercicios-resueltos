#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cadena[50];
    int i = 0, j, num;

    printf("Ingrese una cadena con numeros y letras en ese orden: ");
    fgets(cadena, sizeof(cadena), stdin);

    while(cadena[i] != '\0') {
        if(isdigit(cadena[i])) {
            num = cadena[i] - '0';
            for(j = 0; j < num; j++) {
                putchar(cadena[i + 1]);
            }
        }
        i++;
    }

    return 0;
}