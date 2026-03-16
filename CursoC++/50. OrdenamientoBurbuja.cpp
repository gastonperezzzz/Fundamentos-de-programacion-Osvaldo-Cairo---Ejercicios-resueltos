// ALGORITMO DE ORDENAMIENTO DE BURBUJA O BUBBLE SORT

#include <stdio.h>
#define N 6

main() {
    int i, j, aux, numbers[] = {10, 12, 5, 6, 7, 9}, n1[N];

    for (i = 0; i < N; i++) {
        printf("Ingrese un valor [%d]: ", i);
        scanf("%d", &n1[i]);
    }



    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (numbers[j] > numbers[j + 1]) {
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d ", numbers[i]);
    }


/*
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (n1[j] > n1[j + 1]) {
                aux = n1[j];
                n1[j] = n1[j + 1];
                n1[j + 1] = aux;
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d ", n1[i]);
    }
*/
}