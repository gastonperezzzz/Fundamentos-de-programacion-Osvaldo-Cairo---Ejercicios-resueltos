#include <stdio.h>

int factorial(int num);

int main() {
    int num;

    do {
        printf("Ingrese un numero positivo para calcular su factorial: ");
        scanf("%d", &num);
    } while(num < 0);

    printf("El factorial de %d es %d\n", num, factorial(num));
}

int factorial(int num) {
    int fact = 1;

    if(num == 0) {
        return 1;
    }
    else {
        for(int i = 2; i <= num; i++) {
            fact *= i;
        }
    }

    return fact;
}