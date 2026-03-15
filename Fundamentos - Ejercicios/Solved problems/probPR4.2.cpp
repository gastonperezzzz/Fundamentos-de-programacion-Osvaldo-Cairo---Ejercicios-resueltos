#include <stdio.h>

int mayor_div(int a);

int main() {
    int num;

    do {
        printf("Ingrese un numero > 0: ");
        scanf("%d", &num);
        if(num <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(num <= 0);

    printf("El mayor divisor de %d es %d\n", num, mayor_div(num));
}

int mayor_div(int a) {
    if(a == 1) {
        return 1;
    }
    else {
        int i = (a / 2);
        while(a % i != 0) {
            i--;
        }
        return i;
    }
}