#include <stdio.h>
#include <math.h>

int serieTaylorCos(float x);
int factorial(int num);

int main() {
    int x;

    do {
        printf("Ingrese un valor para 'x': ");
        scanf("%d", &x);
        if(x < 0) {
            printf("Error: numero negativo.\n");
        }
    } while(x < 0);

    printf("El factorial de %d es %d\n", x, factorial(x));
    printf("Dado el 'x', el numero de terminos para la serie de Taylor es: %d\n", serieTaylorCos(x));

    return 0;
}

int serieTaylorCos(float x) {
    bool flag = true;
    int i = 2, terms = 0;
    double res = 0.000, serie = 1.000;
    while((fabs(serie - res)) >= 0.001) {
        if(flag) {
            res -= (pow(x, i) / (factorial(i)));
            flag = false;
        }
        else {
            res += (pow(x, i) / (factorial(i)));
            flag = true;
        }
        i += 2;
        terms++;
    }
    return terms;
}
int factorial(int num) {
    int ftrl = 1;
    for(int i = 1; i <= num; i++) {
        ftrl *= i;
    }
    return ftrl;
}