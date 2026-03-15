#include <stdio.h>

int main() {
    int x = 20, y = 7;

    int *ix;
    ix = &x;

    printf("%d\n", x);
    printf("%d\n", y);

    y = *ix;

    printf("%d\n", y);

    *ix = 1;

    printf("%d\n", y);
    printf("%d\n", x);


}
