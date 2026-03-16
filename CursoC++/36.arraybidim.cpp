#include <stdio.h>

main() {

    int arrbi[100][100], f, c;

    printf ("Ingrese el numero de filas de la matriz: ");
    scanf ("%d", &f);

    printf ("Ingrese el numero de columnas de la matriz: ");
    scanf ("%d", &c);

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("Ingrese un valor para la posicion [%d][%d]: ", i, j);
            scanf ("%d", &arrbi[i][j]);
        }
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("\nEl valor ingresado en la posicion [%d][%d] es: %d", i, j, arrbi[i][j]);
        }
    }
    if (f == c) {
        printf ("\nLa diagonal de principal tiene los elementos...");
        for (int i = 0; i < f; i++) {
            printf ("\nPosicion [%d][%d], valor: %d", i, i, arrbi[i][i]);
        }
    }
    else {
        printf ("\nLa matriz no tiene diagonal principal porque no es una matriz cuadrada...");
    }
    
}