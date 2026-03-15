#include <stdio.h>

const int size = 5;

void loadArray(int *, int);
void printArray(int arr[], int);
void frec(int *, int, int *);
void biggest(int *, int);


int main() {
    int calif[size], freq[6] = {0};

    loadArray(calif, size);
    frec(calif, size, freq);
    printArray(freq, 6);
    biggest(freq, 6);


    return 0;
}

void loadArray(int *x, int a) {
    for(int i = 0; i < a; i++) {
        do {
            printf("Ingrese un numero para la posicion [%d]: ", i);
            scanf("%d", &x[i]);
        } while(x[i] < 0 || x[i] > 5);
    }
}
void printArray(int arr[], int a) {
    for(int i = 0; i < a; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}
void frec(int *x, int size, int *y) {
    for(int i = 0; i < size; i++) {
        y[x[i]]++;
    }
}
void biggest(int *x, int size) {
    int i, mfre = 0, mval = x[0];
    for(i = 1; i < size; i++) {
        if(mval < x[i]) {
            mfre = i;
            mval = x[i];
        }
    }
    printf("\nMayor frecuencia de calificaciones: %d \tValor: %d", mfre, mval);
}