#include <stdio.h>
#include <math.h>

int main() {
    int x, flag = 1, terms = 0, i = 1, num;
    float serie = 0, res = 0, ftr;

    printf("Ingrese un valor para 'x': ");
    scanf("%d", &x);

    while((fabs(serie - res)) < 0.001) {
        num = i;
        while(num != 1) {
            ftr *= (num - 1);
        }
        if(flag) {
            res = float(pow(x, i) / ftr);
            serie -= res;
            flag = 0;
            terms++;
        }
        else {
            res = float(pow(x, i) / ftr);
            serie += res;
            flag = 1;
            terms++;
        }
        i += 2;
    }
    printf("Nro de terminos: %d", terms);
    return 0;
}