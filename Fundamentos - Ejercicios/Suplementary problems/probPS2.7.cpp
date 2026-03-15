#include <stdio.h>
#include <math.h>

int main() {
    int y;
    float fx;

    printf("Ingrese un valor entero para 'y': ");
    scanf("%d", &y);

    if(y % 4 == 0) {
        fx = pow(y, 3);
    }
    else if(y % 4 == 1) {
        fx = (pow(y, 2) / pow(y, 3));
    }
    else if(y % 4 == 2) {
        fx = pow(y, 3) + 5;
    }
    else if(y % 4 == 3) {
        fx = sqrt(y);
    }

    printf("f(x) es igual a: %.4f", fx);
}