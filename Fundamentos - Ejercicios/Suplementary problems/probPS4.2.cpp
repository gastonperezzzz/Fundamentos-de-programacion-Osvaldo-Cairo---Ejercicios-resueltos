#include <stdio.h>

float sucesion(int num);

int main() {
    int num;

    do {
        printf("Ingrese un numero entero: ");
        scanf("%d", &num);
        if(num <= 0) {
            printf("Error: entrada invalida.\n");
        }
    } while(num <= 0);

    printf("El resultado de la sucesion es: %.3f\n", sucesion(num));
}

float sucesion(int num) {
    float suc = 1;
    for(int i = 1; i <= num; i++) {
        if(i % 2 == 0) {
            suc *= 1.0 / i;
        }
        else {
            suc /= 1.0 / i;
        }
    }
    return suc;
}