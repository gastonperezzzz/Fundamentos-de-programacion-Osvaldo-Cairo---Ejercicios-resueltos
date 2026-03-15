#include <stdio.h>

int main() {
    int num;

    do {
        printf("Ingrese un numero entero positivo: ");
        scanf("%d", &num);
        if(num < 0) {
            printf("Error: numero negativo.");
        }
    } while(num < 0);

    while(num != 1) {
        if(num % 2 == 0) {
            num /= 2;
        }
        else {
            num = (num * 3) + 1;
        }
        printf("%d ", num);
    }
}