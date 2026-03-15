#include <stdio.h>

int main() {
    float sum = 0, pag;

    printf("Ingrese el primer pago: ");
    scanf("%f", &pag);

    while(pag) {
        sum += pag;
        printf("Ingrese el siguiente pago: ");
        scanf("%f", &pag);
    }
    printf("La sumatoria de los pagos es: %.2f", sum);
}