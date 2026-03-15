#include <stdio.h>

void swap_value(int *, int *);

int main() {
    int num1, num2;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num1);

    printf("Ingrese otro numero entero: ");
    scanf("%d", &num2);

    printf("Valor de 'num1' ahora: %d\nValor de 'num2' ahora: %d\n\n", num1, num2);
    swap_value(&num1, &num2);
    printf("Valor de 'num1' ahora: %d\nValor de 'num2' ahora: %d\n", num1, num2);

    return 0;
}

void swap_value(int *a, int *b) {
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}