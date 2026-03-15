#include <stdio.h>

int multiplo(int a, int b);

int main() {
    int num1, num2, mult_flag;

    printf("Ingrese un numero (divisor): ");
    scanf("%d", &num1);

    do {
        printf("Ingrese un numero (dividendo): ");
        scanf("%d", &num2);
        if(num2 <= 0) {
            printf("El dividendo debe ser != 0.\n");
        }
    } while(num2 <= 0);

    mult_flag = multiplo(num1, num2);

    if(mult_flag) {
        printf("%d es multiplo de %d\n", num2, num1);
    }
    else {
        printf("%d no es multiplo de %d\n", num2, num1);
    }

    return 0;
}

int multiplo(int a, int b) {
    int flag;
    if(b % a == 0) {
        flag = 1;
    }
    else {
        flag = 0;
    }
    return flag;
}