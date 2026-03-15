#include <stdio.h>

int main() {
    int x = 5, y = 8, v[5] = {1, 3, 5, 7, 9};
    int *ay, *ax;

    ay = &y;
    x = *ay; // x = 8

    *ay = v[3] + v[2];

    printf("x = %d | y = %d | v[0] = %d | v[1] = %d | v[2] = %d | v[3] = %d | v[4] = %d\n", x, y, v[0], v[1], v[2], v[3], v[4]);

    ax = &v[v[0] * v[1]]; // => v[3] = 7
    x = *ax; // x = 7
    y = *ax * v[1]; // y = 21
    *ax = *ay - 3; // *ax = 18

    printf("x = %d | y = %d | v[0] = %d | v[1] = %d | v[2] = %d | v[3] = %d | v[4] = %d\n", x, y, v[0], v[1], v[2], v[3], v[4]);

    return 0;
}