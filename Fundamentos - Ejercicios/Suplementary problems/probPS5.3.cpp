#include <stdio.h>
#define SIZE 100

void printVec(long int *, int);
void fibonacciArray(long int *, int);

int main() {
    long int fibonacci[SIZE];

    fibonacciArray(fibonacci, SIZE);
    printVec(fibonacci, SIZE);

    return 0;
}

void printVec(long int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %ld\n", i, arr[i]);
    }
}
void fibonacciArray(long int *arr, int size) {
    long int res, num1 = 0, num2 = 1;
    for(int i = 0; i < size; i++) {
        res = num1 + num2;
        num2 = num1;
        num1 = res;
        arr[i] = res;
    }
}