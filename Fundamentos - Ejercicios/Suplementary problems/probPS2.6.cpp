#include <stdio.h>

int main() {
    float n1, n2, n3;

    printf("Ingrese un valor [1]: ");
    scanf("%f", &n1);

    printf("Ingrese un valor [2]: ");
    scanf("%f", &n2);

    printf("Ingrese un valor [3]: ");
    scanf("%f", &n3);

    if(n1 > n2 && n1 > n3) {
        printf("El mayor es. %.2f", n1);
    }
    else if(n2 > n3) {
        printf("El mayor es: %.2f", n2);
    }
    else {
        printf("El mayor es: %.2f", n3);
    }
}