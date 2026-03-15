#include <stdio.h>

int main() {
    int num;

    do {
        printf("Ingrese un numero mayor o igual que 2: ");
        scanf("%d", &num);
        if(num <= 2) {
            printf("Error: numero invalido.\n");
        }
    } while (num <= 2);

    for(int i = 2; i < num; ++i) {
        bool esPrimo = true;
        for(int j = 2; j < i; ++j) {
            if(i % j == 0) {
                esPrimo = false;
                break;
            }
        }
        if(esPrimo) {
            printf("%d ", i);
        }
    }
}