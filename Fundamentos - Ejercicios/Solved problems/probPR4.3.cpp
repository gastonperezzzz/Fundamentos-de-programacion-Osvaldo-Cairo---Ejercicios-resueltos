#include <stdio.h>

int mcd(int a, int b);

int main() {
    int num1, num2;

    do {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &num1);
        if(num1 <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(num1 <= 0);

    do {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &num2);
        if(num2 <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(num2 <= 0);

    printf("El mcm de %d y %d es: %d\n", num1, num2, mcd(num1, num2));
}

int mcd(int a, int b) {
    int i;
    if(a == 1 || b == 1) {
        return 1;
    }
    else if(a > b) {
        i = b / 2;
    }
    else if(b > a){
        i = a / 2;
    }
    while((a % i != 0) || (b % i != 0)) {
        i--;
    }
    return i;
}