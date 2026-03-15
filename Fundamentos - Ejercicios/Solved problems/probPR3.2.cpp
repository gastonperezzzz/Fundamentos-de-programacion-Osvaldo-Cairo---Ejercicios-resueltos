#include <stdio.h>

int main() {
    long int cam = 1, sse = 0, i = 2;

    while(i <= 2500) {
        sse += i;
        printf("%ld ", i);
        if(cam > 0) {
            i += 5;
            cam = 0;
        }
        else {
            i += 3;
            cam = 1;
        }
    }
    printf("\nLa suma de la sucesion es: %ld", sse);
}