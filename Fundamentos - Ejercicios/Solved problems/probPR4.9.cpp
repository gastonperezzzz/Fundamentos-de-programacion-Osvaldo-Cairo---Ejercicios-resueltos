#include <stdio.h>
#include <math.h>

int expression(int, int, int);

int main() {
    int exp, t = 0, p = 0, q = 0;
    exp = expression(t, p, q);

    while(exp < 5500) {
        while(exp < 5500) {
            while(exp < 5500) {
                printf("t => %d ; p => %d ; q => %d, resultado => %d\n", t, p, q, exp);
                q++;
                exp = expression(t, p, q);
            }
            p++;
            q = 0;
        }
        t++;
        p = 0;
        q = 0;
        exp = expression(t, p, q);
    }

    return 0;
}

int expression(int n1, int n2, int n3) {
    int res;
    res = 15 * pow(n1, 4) + 12 * pow(n2, 5) + 9 * pow(n3, 6);
    return res;
}