#include <stdio.h>
#include <math.h>

main() {
    int num;
    
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("%d es nulo.", num);
    }
    else {
        if (pow (-1, num) > 0) {
            printf("%d es par.", num);
        }
        else {
            printf("%d es impar", num);
        }
    }
}