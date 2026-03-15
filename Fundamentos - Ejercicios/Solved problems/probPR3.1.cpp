#include <stdio.h>

int main() {
    long num, factorial = 1, i = 1;
    
    do {
        printf("Ingrese un numero > 0 para calcular su factorial: ");
        scanf("%ld", &num);
        if(num <= 0) {
            printf("Error en el dato.\n");
        }
    } while(num <= 0);

    for(i = 1; i <= num; i++) {
        factorial = factorial * i;
    }
    printf("El factorial de %ld es %ld", num, factorial);
}