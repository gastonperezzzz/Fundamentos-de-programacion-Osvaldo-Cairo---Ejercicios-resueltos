#include <stdio.h>

int main() {
    int num, suc = 0, flag = 0;

    do {
        printf("Ingrese un valor > 0 para la serie: ");
        scanf("%d", &num);
        if(num < 0) {
            printf("Error: numero negativo o nulo.");
        }
    } while(num <= 0);

    for(int i = 1; i <= num; i++) {
        if(flag) {
            suc -= (i * i);
            flag = 0;
        }
        else {
            suc += (i * i);
            flag = 1;
        }
    }
    printf("El resultado de la sucesion es: %d", suc);
}