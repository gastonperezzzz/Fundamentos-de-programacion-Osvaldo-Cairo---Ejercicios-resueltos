#include <stdio.h>

void numPerfects(int);

int main() {
    int number;

    do {
        printf("Ingrese un numero entero positivo: ");
        scanf("%d", &number);
        if(number <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(number <= 0);

    numPerfects(number);
    printf("\n");

    return 0;
}

void numPerfects(int num) {
    for(int i = 1; i <= num; i++) {
        int perfect = 0;
        for(int j = 1; j <= i / 2; j++) {
            if(i % j == 0) {
                perfect += j;
            }
        }
        if(perfect == i) {
            printf("%d ", perfect);
        }
    }
}