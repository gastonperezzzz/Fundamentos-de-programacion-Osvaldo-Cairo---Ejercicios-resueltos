#include <stdio.h>

int func1(int);

int main() {
    int i, k = 4;

    for(i = 1; i <= 3; i++) {
        printf("Valor de k antes de la funcion: %d\n", ++k);
        printf("Valor de k despues de la funcion: %d\n\n", func1(k));
    }

    return 0;
}

int func1(int num) {
    num += num;
    return num;
}