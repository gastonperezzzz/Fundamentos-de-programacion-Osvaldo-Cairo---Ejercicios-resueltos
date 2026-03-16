#include <stdio.h>

main() {

    int m[100][100], f, c, mt[100][100];

    printf ("Ingrese el numero de filas de la matriz: ");
    scanf ("%d", &f);

    printf ("Ingrese el numero de columnas de la matriz: ");
    scanf ("%d", &c);

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("Ingrese un valor para la posicion [%d][%d]: ", i, j);
            scanf ("%d", &m[i][j]);
        }
    }
    printf ("La matriz transpuesta es...\n");
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("La transpuesta es [%d][%d]: %d\n", i, j, mt[j][i]);
        }
    }
}