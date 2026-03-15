#include <stdio.h>
#include <math.h>

long serie(int);

int main() {
    int n;

    do {
        printf("Ingrese un numero positivo para calcular la serie: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(n <= 0);

    printf("Dado %d l resultado de la serie es: %ld\n", n, serie(n));

    return 0;
}

long serie(int n) {
    long int suc = 1;
    bool flag = true;
    for(int i = 2; i <= n; i++) {
        if(flag) {
            suc -= pow(i, i); 
            flag = false;
        }
        else {
            suc += pow(i, i);
            flag = true;
        }
    }
    return suc;
}