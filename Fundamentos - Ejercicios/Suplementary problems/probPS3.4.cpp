#include <stdio.h>

int main() {
    int n, num, contpos = 0, contneg = 0, contnu = 0;

    printf("Cuantos numeros quiere ingresar: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Ingrese un numero [%d]: ", i + 1);
        scanf("%d", &num);
        if(num < 0) {
            contneg++;
        }
        else if(num > 0) {
            contpos++;
        }
        else {
            contnu++;
        }
    }
    printf("%d son positivos, %d son negativos y %d son nulos.", contpos, contneg, contnu);
}