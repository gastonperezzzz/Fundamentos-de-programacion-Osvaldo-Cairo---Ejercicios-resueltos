#include <stdio.h>
#define T 6

void loadArray(float *, int);
void printArray(float *, int);
float anualProm(float *, int);
int mesMayorProm(float *, int, float);
int mesMayorProduccion(float *, int, float *);

int main() {
    float cos[T];
    float tonsmayores;

    loadArray(cos, T);
    
    printf("El promedio anual de toneladas cosechadas es: %.2f\n", anualProm(cos, T));
    printf("Meses con cosecha superior al promedio anual: %d\n", mesMayorProm(cos, T, anualProm(cos, T)));
    printf("Mayor produccion: %.2f | Mes: %d\n", tonsmayores, mesMayorProduccion(cos, T, &tonsmayores));

    return 0;
}

void loadArray(float *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%f", &arr[i]);
    }
}
void printArray(float *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %.2f\n", i, arr[i]);
    }
}
float anualProm(float *arr, int size) {
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (sum / size);
}
int mesMayorProm(float *arr, int size, float prom) {
    int mes_mayor_prom = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] > prom) {
            mes_mayor_prom++;
        }
    }
    return mes_mayor_prom;
}
int mesMayorProduccion(float *arr, int size, float *tonsmayor) {
    int mes_mayor_prod;
    *tonsmayor = arr[0];
    for(int i = 0; i < size; i++) {
        if(arr[i] > *tonsmayor) {
            *tonsmayor = arr[i];
            mes_mayor_prod = i;
        }
    }
    return (mes_mayor_prod + 1);
}
