#include <stdio.h>

int main() {
    int monedas[6] = {50, 20, 10, 5, 2, 1};
    int cambio;
    int calculo_monedas = 0;
    int i = 0;

    printf("Ingrese el cambio a convertir: ");
    scanf("%d", &cambio);
    getchar();

    while(calculo_monedas != cambio) {
        if((calculo_monedas + monedas[i]) <= cambio) {
            calculo_monedas += monedas[i];
            printf("Moneda de %d\n", monedas[i]);
        }
        else {
            i++;
        }
    }

    printf("Se encontro el cambio indicado.\n");

    return 0;
}