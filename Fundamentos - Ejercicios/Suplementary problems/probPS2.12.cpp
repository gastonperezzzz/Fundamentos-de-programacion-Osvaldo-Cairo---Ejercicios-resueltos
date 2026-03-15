#include <stdio.h>

int main() {
    int num, d1, d2, d3, d4;
    int todosPares = 1;

    printf("Ingrese un numero entero de 4 digitos: ");
    scanf("%d", &num);
    if(num < 1000 || num > 9999) {
        printf("El numero no es de cuatro digitos.");
        return 1;
    }

    d1 = num % 10;
    if(d1 % 2 == 0) {
        printf("%d es par.\n", d1);
    }
    else {
        printf("%d es impar.\n", d1);
        todosPares = 0;
    }

    // printf("%d\n", num);

    num /= 10;

    d2 = num % 10;
    if(d2 % 2 == 0) {
        printf("%d es par.\n", d2);
    }
    else {
        printf("%d es impar.\n", d2);
        todosPares = 0;
    }

    // printf("%d\n", num);

    num /= 10;

    d3 = num % 10;
    if(d3 % 2 == 0) {
        printf("%d es par.\n", d3);
    }
    else {
        printf("%d es impar.\n", d3);
        todosPares = 0;
    }

    // printf("%d\n", num);

    num /= 10;

    d4 = num % 10;
    if(d4 % 2 == 0) {
        printf("%d es par.\n", d4);
    }
    else {
        printf("%d es impar.\n", d4);
        todosPares = 0;
    }

    if(todosPares) {
        printf("Todos los digitos son pares.");
    }
    else {
        printf("No todos los digitos son pares.");
    }
    // printf("%d\n", num);
}