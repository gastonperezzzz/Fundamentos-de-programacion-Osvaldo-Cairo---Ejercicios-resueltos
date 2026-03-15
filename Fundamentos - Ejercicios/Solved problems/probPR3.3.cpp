#include <stdio.h>

int main() {
    int num, par = 0, val;
    float impar = 0, contim = 0;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &val);

    if(val > 0) {
        for(int i = 0; i < val; i++) {
            printf("Ingrese un numero entero positivo [%d]: ", i);
            scanf("%d", &num);
            if(num % 2 == 0) {
                par += num;
            }
            else {
                impar += num;
                contim++;
            }
        }
    }
    else {
        printf("El numero ingresado no es valido.");
        return 1;
    }
    impar /= contim;
    printf("La suma de los numeros pares es: %d", par);
    printf("\nEl promedio de los numeros impares es. %.2f", impar);
}