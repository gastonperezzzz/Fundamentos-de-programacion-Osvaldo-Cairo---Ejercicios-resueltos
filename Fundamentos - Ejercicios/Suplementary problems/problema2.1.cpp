#include <stdio.h>

main() {
    int R, T, Q, Res;

    printf("Ingrese un valor para R: ");
    scanf("%d", &R);

    printf("Ingrese un valor para T: ");
    scanf("%d", &T);

    printf("Ingrese un valor para Q: ");
    scanf("%d", &Q);

    Res = R*R*R*R - T*T*T + 4 * Q*Q;

    if (Res < 820) {
        printf("%d, %d, %d", R, T, Q);
    }
}