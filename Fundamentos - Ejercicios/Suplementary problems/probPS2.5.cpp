#include <stdio.h>

int main() {
    float com;

    printf("Ingrese el monto de compra del cliente: ");
    scanf("%f", &com);

    if(com >= 800 && com <= 1500) {
        com = com - (10/100.0 * com);
    }
    else if(com > 1500 && com <= 5000) {
        com = com - (15/100.0 * com);
    }
    else if(com > 5000) {
        com = com - (20/100.0 * com);
    }
    printf("El precio a pagar es: %.2f", com);
}