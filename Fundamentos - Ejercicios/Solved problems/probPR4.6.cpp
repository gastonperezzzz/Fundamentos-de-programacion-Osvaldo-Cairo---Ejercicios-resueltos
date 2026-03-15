#include <stdio.h>

long int productoria(int n);

int main() {
    int N;

    do {
        printf("Ingrese un numero entero positivo: ");
        scanf("%d", &N);
        if(N <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(N <= 0);

    printf("La productoria desde 1 hasta %d es: %ld\n", N, productoria(N));

    return 0;
}

long int productoria(int n) {
    long int producto = 1;
    for(int i = 1; i <= n; i++) {
        producto *= i;
    }
    return producto;
}