#include <stdio.h>

int cubo(int);

int main() {
    int i;
    for(i = 1; i <= 10; i++) {
        printf("El cubo de %d es %d.\n", i, cubo(i));
    }
}

int cubo(int i) {
    return (i * i * i);
}
