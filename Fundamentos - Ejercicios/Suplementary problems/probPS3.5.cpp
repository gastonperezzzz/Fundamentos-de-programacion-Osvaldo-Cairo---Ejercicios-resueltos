#include <stdio.h>

int main() {
    int n, productoria = 1;

    do {
        printf("Ingrese un valor n > 0 para la productoria: ");
        scanf("%d", &n);
        if(n < 0 || n == 0) {
            printf("Error: numero negativo o nulo.\n");
        }
    } while(n < 0 || n == 0);

    for(int i = 1; i <= n; i++) {
        productoria = productoria * i;
    }
    printf("La productoria de los primeros n numeros naturales es: %d", productoria);
}