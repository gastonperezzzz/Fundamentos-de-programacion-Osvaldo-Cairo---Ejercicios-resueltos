#include <stdio.h>

int main() {
    int n;
    float lan, prom = 0;

    do {
        printf("Ingrese un numero de lanzamientos [0 - 11]: ");
        scanf("%d", &n);
    } while(n < 0 || n > 11);
    
    for(int i = 0; i < n; i++) {
        printf("Ingrese el lanzamiento [%d]: ", i);
        scanf("%f", &lan);
        prom += lan;
    }
    prom /= n;
    printf("El promedio de lanzamientos es: %.2f", prom);
}