#include <stdio.h>

int main() {
    int n, producto;

    do {
        printf("Ingrese un numero > 0 para su tabla de multiplicar: ");
        scanf("%d", &n);
        if(n < 0) {
            printf("Error: numero negativo.\n");
        }
    } while(n < 0);

    for(int i = 1; i <= 10; i++) {
        producto = n * i;
        printf("%d x %d = %d\n", n, i, producto);
    }
}