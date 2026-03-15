#include <stdio.h>

int main() {
    int n1, n2;

    printf("Ingrese un valor: ");
    scanf("%d", &n1);

    printf("Ingrese otro valor: ");
    scanf("%d", &n2);

    if(n1 % n2 == 0) {
        printf("%d es divisor de %d", n2, n1);
    }
    else if(n2 % n1 == 0) {
        printf("%d es divisor de %d", n1, n2);
    }
    else {
        printf("Los numeros no son divisores entre si.");
    }
}