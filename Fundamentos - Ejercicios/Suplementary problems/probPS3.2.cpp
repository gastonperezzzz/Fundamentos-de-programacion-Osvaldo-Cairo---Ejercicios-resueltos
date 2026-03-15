#include <stdio.h>

int main() {
    int n;
    float sum = 0;

    do {
        printf("Ingrese un numero > 0 para la sucesion: ");
        scanf("%d", &n);
        if(n < 0) {
            printf("Error: numero negativo o igual a cero.\n");
        }
    } while(n < 0);

    for(int i = 1; i <= n; i++) {
        sum = sum + (1.0/i);
    }
    printf("El resultado de la sucesion hasta %d es %.2f\n", n, sum);
    printf("El numero de terminos necesarios fueron: %d", n);
}
