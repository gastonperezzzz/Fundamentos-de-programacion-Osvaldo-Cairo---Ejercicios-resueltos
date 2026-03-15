#include <stdio.h>
#include <math.h>

void printArray(int *, int);
void cargaArray(int *, int);
float mediaArit(int *, int);
float varianza(int *, int, float);
float desvEstandar(float);
int moda(int *, int);

int main() {
    int n;

    do {
        printf("Ingrese el tamaño del array: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(n <= 0);

    int alu[n];

    cargaArray(alu, n);

    printf("La media aritmetica es: %.2f\n", mediaArit(alu, n));
    printf("La varianza es: %.2f\n", varianza(alu, n, mediaArit(alu, n)));
    printf("La desviacion estandar es: %.2f\n", desvEstandar(varianza(alu, n, mediaArit(alu, n))));
    printf("La moda es: %d\n", moda(alu, n));

    return 0;
}
void cargaArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
float mediaArit(int *arr, int size) {
    float sumatoria = 0;
    for(int i = 0; i < size; i++) {
        sumatoria += arr[i];
    }
    sumatoria /= size;
    return sumatoria;
}
float varianza(int *arr, int size, float media) {
    float var = 0;
    for(int i = 0; i < size; i++) {
        var += pow((media - arr[i]), 2);
    }
    var /= size;
    return var;
}
float desvEstandar(float var) {
    return (sqrt(var));
}
int moda(int *arr, int size) {
    int calif[size] = {0}, moda = 0, i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(arr[i] == arr[j]) {
                calif[i]++;
            }
        }
    }
    /*
    for(i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, calif[i]);
    }
    */
    for(i = 0; i < size; i++) {
        if(moda < calif[i]) {
            moda = calif[i];
        }
    }
    return (arr[moda]);
}
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}