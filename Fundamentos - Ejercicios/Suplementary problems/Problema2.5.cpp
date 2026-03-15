#include <stdio.h>
#include <math.h>

int main() {
    int y, fx;

    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);

    if (y >= 0 && y <= 10) {
        fx = (4 / y) - y;
    }
    if (y > 11 && y <= 25) {
        fx = pow(y, 3) - 12;
    }
    if (y > 25 && y <= 50) {
        fx = pow(y, 2) + (pow(y, 3) - 18);
    }
    printf("%d", fx);
}