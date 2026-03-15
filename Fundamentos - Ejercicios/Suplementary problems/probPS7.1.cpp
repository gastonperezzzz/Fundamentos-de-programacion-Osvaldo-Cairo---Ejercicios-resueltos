#include <stdio.h>
#include <string.h>

int main() {
    char cad[50];
    int i = 0;

    printf("Ingrese una cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    while(cad[i] != '\0') {
        if(cad[i] % 2 != 0) {
            putchar(cad[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}