#include <stdio.h>

void func1(int *);

int main() {
    int i, k = 4;

    for(i = 1; i <= 3; i++) {
        printf("Valor de 'k' antes de llamar a la funcion: %d\n", ++k);
        func1(&k);
        printf("Valor de 'k' despues de llamar a la funcion: %d\n\n", k);
    }


    return 0;
}

void func1(int *r) {
    *r += *r;
}