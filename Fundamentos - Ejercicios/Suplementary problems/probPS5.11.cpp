#include <stdio.h>
#define T 4

void numPerfects(int *, int);
void printArray(int *, int);

int main() {
    int arrayPerfect[T];

    numPerfects(arrayPerfect, T);
    printArray(arrayPerfect, T);

    return 0;
}

void numPerfects(int *arr, int size) {
    int cont_perfects = 0, flag = 0, i = 3, j;

    while(cont_perfects < size) {
        flag = 0;
        while(flag != 1) {
            j = 1;
            i++;
            int sum_divisors = 0;
            while(j <= (i / 2)) {
                if(i % j == 0) {
                    sum_divisors += j;
                }
                j++;
            }
            if(sum_divisors == i) {
                flag = 1;
            }
        }
        if(flag) {
        arr[cont_perfects] = i;
        cont_perfects++;
        }
    }
}
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}