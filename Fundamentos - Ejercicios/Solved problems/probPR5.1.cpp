#include <stdio.h>

const int size = 5;

void carga_array(float *, int a);
void print_array(float *arr, int a);
double suma_cuadrados_array(float *, int a);

int main() {
    float arreglo[size];
    double res;

    carga_array(arreglo, size);
    res = suma_cuadrados_array(arreglo, size);
    print_array(arreglo, size);

    printf("La sumatoria de los cuadrados de los numeros ingresados es: %.10lf", res);

    return 0;
}

void carga_array(float *arr, int a) {
    for(int i = 0; i < a; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%f", &arr[i]);
    }
}
void print_array(float *arr, int a) {
    for(int i = 0; i < a; i++) {
        printf("Posicion [%d]: %.2f\n", i, arr[i]);
    }
}
double suma_cuadrados_array(float *arr, int a) {
    double sumatoria = 0;
    for(int i = 0; i < a; i++) {
        sumatoria += arr[i] * arr[i];
    }
    return sumatoria;
}