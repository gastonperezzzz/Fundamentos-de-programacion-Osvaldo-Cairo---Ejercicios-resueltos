#include <stdio.h>

int main() {
    int n, y;
    float fx;

    do {
        printf("Ingrese la cantidad de valores para 'y': ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: cantidad invalida.\n");
        }
    } while(n <= 0);

    for(int i = 1; i <= n; i++) {
        do {
            printf("Ingrese un valor para 'y' [%d]: ", i);
            scanf("%d", &y);
        } while(y <= 0);

        if(y > 0 && y <= 15) {
            fx = (y * y) + 15;
        }
        else if(y > 15 && y <= 30) {
            fx = (y * y * y) - (y * y) + 12;
        }
        else if(y > 30 && y <= 60) {
            fx = 4 * (y * y * y) / (y * y) + 8;
        }
        else {
            fx = 0;
        }
        printf("f(x) = %.2f\n", fx);
    }
}