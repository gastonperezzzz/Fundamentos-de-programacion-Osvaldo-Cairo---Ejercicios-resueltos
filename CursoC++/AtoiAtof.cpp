// ATOI ---> de cadena a entero.
// ATOF ---> de cadena a flotante.

#include <stdio.h>
#include <stdlib.h>

main() {
    char string[10], string2[10];
    int numberConv;
    float numberConv2, resultado;

    printf("Ingrese un numero: ");
    scanf("%s", string);

    printf("Ingrese un numero flotante: ");
    scanf("%s", string2);

    numberConv = atoi(string);
    numberConv2 = atof(string2);
    resultado = numberConv + numberConv2;

    printf("La cadena convertida a entero es: %d", numberConv);
    printf("\nLa cadena convertida a flotante es: %.3f", numberConv2);
    printf("\nLa suma de ambos numeros es: %.3f", resultado);
}