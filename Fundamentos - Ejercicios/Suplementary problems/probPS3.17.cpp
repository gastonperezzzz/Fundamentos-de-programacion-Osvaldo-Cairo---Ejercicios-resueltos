#include <stdio.h>

int main() {
    int num, i, j, k;

    do {
        printf("Ingrese un numero > 0: ");
        scanf("%d", &num);
        if(num <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(num <= 0);

    for(i = 1; i <= num; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
            if(j == i) {
                for(k = j - 1; k >= 1; k--) {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
    }
}