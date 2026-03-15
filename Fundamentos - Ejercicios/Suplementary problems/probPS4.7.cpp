#include <stdio.h>

int numPrimo(int num);

int main() {
    int number, flag;

    do {
        printf("Ingrese un numero para determinar si es primo: ");
        scanf("%d", &number);
    } while(number <= 0);

    flag = numPrimo(number);

    if(flag) {
        printf("%d no es un numero primo.\n", number);
    }
    else {
        printf("%d es un numero primo.\n", number);
    }

    return 0;
}

int numPrimo(int num) {
    int flag, limit = num / 2;
    for(int i = 2; i <= limit; i++) {
        if(num % i == 0) {
            flag = 1;
            break;
        }
        else {
            flag = 0;
        }
    }
    return flag;
}