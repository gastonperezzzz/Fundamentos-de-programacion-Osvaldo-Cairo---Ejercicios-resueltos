#include <stdio.h>

void promParesImpares(int, float *, float *);

int main() {
    int n, num;
    float prom_pares = 0, prom_impares = 0;

    do {
        printf("Ingrese un valor para 'n': ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(n <= 0);

    for(int i = 1; i <= n; i++) {
        do {
            printf("Ingrese un numero positivo: ");
            scanf("%d", &num);
            if(num <= 0) {
                printf("Error: numero negativo o nulo.\n");
            }
        } while(num <= 0);
        promParesImpares(num, &prom_pares, &prom_impares);
    }
    printf("El promedio de los numeros pares es: %.2f\n", prom_pares / n);
    printf("El promedio de los numeros impares es: %.2f\n", prom_impares / n);

    return 0;
}

void promParesImpares(int num, float *acum1, float *acum2) {
    if(num % 2 == 0) {
        *acum1 += num;
    }
    else {
        *acum2 += num;
    }
}