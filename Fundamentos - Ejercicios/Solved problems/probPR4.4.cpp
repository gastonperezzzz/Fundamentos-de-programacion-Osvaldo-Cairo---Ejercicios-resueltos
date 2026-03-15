#include <stdio.h>

void par_impar(int a, int *b, int *c);
void parimp(int a, int *b, int *c);

int main() {
    int n, num, par = 0, impar = 0;

    do {
        printf("Ingrese el numero de datos: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(n <= 0);

    for(int i = 1; i <= n; i++) {
        do {
            printf("Ingrese un numero entero positivo: ");
            scanf("%d", &num);
            if(num <= 0) {
                printf("Error: numero invalido.\n");
            }
        } while(num <= 0);
        parimp(num, &par, &impar);
        printf("%d pares y %d impares.\n", par, impar);
    }
    return 0;
}

void par_impar(int a, int *b, int *c) {
    for(int i = 1; i <= a; i++) {
        if(a % 2 == 0) {
            *b += 1;
        }
        else {
            *c += 1;
        }
    }
}
void parimp(int a, int *b, int *c) {
    if(a % 2 == 0) {
        *b += 1;
    }
    else {
        *c += 1;
    }
}