#include <stdio.h>

int main() {
    /*
    long int sum, cuad, num;

    printf("Ingrese un numero para calcular su cuadrado: ");
    scanf("%ld", &num);

    while(num) {
        cuad = num * num;
        sum += cuad;
        printf("%ld al cuadrado es %ld\n", num, cuad);
        printf("Ingrese otro numero: ");
        scanf("%ld", &num);
    }
    printf("La sumatoria de los cuadrados es: %ld", sum);
    */

    long int sum, cuad, num;

    while(num) {
        printf("Ingrese un numero entero > 0 para calcular su cuadrado: ");
        scanf("%ld", &num);

        if(num < 0) {
            printf("El numero es negativo.");
            return 1;
        }

        cuad = num * num;
        sum += cuad;
    }
    printf("La sumatoria de los cuadrados es %ld", sum);
}