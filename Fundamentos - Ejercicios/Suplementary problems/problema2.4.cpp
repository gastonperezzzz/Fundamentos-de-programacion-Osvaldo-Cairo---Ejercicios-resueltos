#include <stdio.h>
#include <math.h>

main() {
    float t, p, n;

    printf("Ingrese un valor para 't': ");
    scanf("%f", &t);

    printf("Ingrese un valor para 'p': ");
    scanf("%f", &p);

    printf("Ingrese un valor para 'n': ");
    scanf("%f", &n);

    printf("\n%.4f = %.4f", pow((t / p), n), pow(t, n) / pow(p, n));

    if (pow(t / p, n) == pow(t, n) / pow(p, n)) {
        printf("\nLa igualdad se cumple.");
    }
}