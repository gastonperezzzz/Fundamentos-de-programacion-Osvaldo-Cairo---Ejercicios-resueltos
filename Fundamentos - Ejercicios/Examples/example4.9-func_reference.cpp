#include <stdio.h>

int sum(int a, int b);
int resta(int a, int b);
int control(int (*apf) (int, int), int a, int b);

int main() {
    int n1, n2;

    printf("Ingrese un numero: ");
    scanf("%d", &n1);

    printf("Ingrese un numero: ");
    scanf("%d", &n2);

    printf("Suma: %d\n", control(sum, n1, n2));
    printf("Resta: %d\n", control(resta, n1, n2));

    return 0;
}

int sum(int a, int b) {
    return (a + b);
}
int resta(int a, int b) {
    return (a - b);
}
int control(int (*apf) (int, int), int a, int b) {
    int res;
    res = (*apf) (a, b);
    return res;
}