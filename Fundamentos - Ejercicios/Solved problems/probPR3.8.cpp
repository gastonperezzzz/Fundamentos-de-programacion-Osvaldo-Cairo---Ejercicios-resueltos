#include <stdio.h>
#include <math.h>

int main() {
    int i = 2, b = 0, c = 1;
    double res = 4.0000/i;

    while((fabs(3.1415 - res)) > 0.0005) {
        i += 2;
        if(b == 1) {
            res += (double)(4.0/i);
            b = 0;
        }
        else {
            res -= (double)(4.0/i);
            b = 1;
        }
        c++;
    }
    printf("%d ", c);
}