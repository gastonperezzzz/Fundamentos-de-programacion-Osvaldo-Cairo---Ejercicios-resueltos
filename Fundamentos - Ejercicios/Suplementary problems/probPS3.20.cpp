#include <stdio.h>
#include <math.h>

int main() {
    bool flag = true;
    int t = 1, p = 1, r = 1, expression;

    printf("valores t, p, r para los que se cumple la expresion: ");
    while(flag) {
        expression = 7 * pow(t, 4) - 6 * pow(p, 3) + 12 * pow(r, 5);
        if(expression < 5850) {
            printf("%d ", t);
            t++;
            p++;
            r++;
        }
        else {
            flag = false;
        }
    }
}