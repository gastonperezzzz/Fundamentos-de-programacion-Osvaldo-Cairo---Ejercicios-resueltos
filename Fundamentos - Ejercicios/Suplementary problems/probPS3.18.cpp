#include <stdio.h>

int main() {
    int num, i, j, k, n = 0;

    do {
        printf("Ingrese un numero para generar una figura: ");
        scanf("%d", &num);
        if(num <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(num <= 0);

    for(i = num; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
            if(j == num - n) {
                for(k = j; k >= 1; k--) {
                    printf(" %d", k);
                }
            }
        }
    printf("\n");
    n++;
    }
}