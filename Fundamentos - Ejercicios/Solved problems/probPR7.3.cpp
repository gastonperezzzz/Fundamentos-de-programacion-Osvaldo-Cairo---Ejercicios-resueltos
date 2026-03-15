#include <stdio.h>
#include <ctype.h>

int main() {
    char cadena[50];
    int n;
    char c;

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    printf("Ingrese un valor para la posicion de la cadena: ");
    scanf("%d", &n);

    c = cadena[n - 1];

    if(islower(cadena[n - 1])) {
        printf("La posicion %d (%c) en la cadena ingresada es una letra minuscula.\n", n, c);
    }
    else {
        printf("La posicion %d (%c) en la cadena ingresada NO es una letra minuscula.\n", n, c);
    }

    return 0;
}