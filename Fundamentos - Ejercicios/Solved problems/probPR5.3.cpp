#include <stdio.h>
#define SIZE 100

int main() {
    int arrPrimos[SIZE] = {2, 3}, cont_primos = 1, j, i = 3;
    bool flag;

    while(cont_primos < SIZE) {
        for(j = 2; j < i; j++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
            else {
                flag = true;
            }
        }
        if(flag) {
            arrPrimos[cont_primos] = i;
            cont_primos++;
        }
        i++;
    }

    for(int k = 0; k < SIZE; k++) {
        printf("Posicion [%d]: %d\n", k, arrPrimos[k]);
    }

    return 0;
}