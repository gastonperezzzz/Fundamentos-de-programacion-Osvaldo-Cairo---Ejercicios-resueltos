#include <stdio.h>

main() {

    int m1[100][100], m2[100][100], f, c;

    printf ("Ingrese un numero de filas para la matriz: ");
    scanf ("%d", &f);

    printf ("Ingrese un numero de filas para la matriz: ");
    scanf ("%d", &c);

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("Ingrese un valor para la posicion [%d][%d]: ", i, j);
            scanf ("%d", &m1[i][j]);
        }
    }
    printf ("Copiamos la primera matriz en otra...\n");
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            m2[i][j] = m1[i][j];
            printf ("Ahora el primer valor de la segunda matriz en la posicion [%d][%d] es: %d\n", i, j, m2[i][j]);
        }
    }
}