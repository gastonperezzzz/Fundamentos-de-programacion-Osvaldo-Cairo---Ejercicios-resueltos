#include <stdio.h>

void reversePrint(int);

int main() {
    int number;

    do {
        printf("Ingrese un numero de 4 digitos: ");
        scanf("%d", &number);
        if(number < 1000 || number > 9999) {
            printf("Error: numero invalido.\n");
        }
    } while(number < 1000 || number > 9999);

    printf("El numero es %d\n", number);
    printf("Escrito al reves es: ");
    reversePrint(number);

    return 0;
}

void reversePrint(int num) {
    int aux;
    for(int i = 1; i <= 4; i++) {
        aux = num % 10;
        num /= 10;
        printf("%d ", aux);
    }
}