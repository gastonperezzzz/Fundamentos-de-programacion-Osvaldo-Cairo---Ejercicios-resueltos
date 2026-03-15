#include <stdio.h>
#include <ctype.h>

int main() {
    int i = 0, mins = 0, mayus = 0;
    char cadena[50];

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    while(cadena[i] != '\0') {
        if(islower(cadena[i])) {
            mins++;
        }
        else if(isupper(cadena[i])) {
            mayus++;
        }
        i++;
    }

    printf("Minusculas: %d\n", mins);
    printf("Mayusculas: %d\n", mayus);

    return 0;
}