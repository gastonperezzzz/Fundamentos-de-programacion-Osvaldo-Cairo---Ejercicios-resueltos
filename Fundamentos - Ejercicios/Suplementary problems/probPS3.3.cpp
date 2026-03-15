#include <stdio.h>

int main() {
    int n;
    float sucesion = 1;

    do {
        printf("Ingrese un numero > 0 para la sucesion: ");
        scanf("%d", &n);
    } while(n < 0);

    for(int i = 0; i <= n; i++) {
        i++;
        sucesion *= ((1.0 / i) / (1.0 / (i + 1)));
    }
    printf("Nro de terminos %d, resultado de la sucesion %.2f", n, sucesion);
}