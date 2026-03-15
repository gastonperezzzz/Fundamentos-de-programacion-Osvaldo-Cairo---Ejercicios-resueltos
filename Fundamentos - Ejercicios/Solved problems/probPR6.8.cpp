#include <stdio.h>

#define FONDOS 3
#define MES 3

void cargaMat(float mat[][MES], int, int);
void cargaVec(float *, int);
void printMat(float mat[][MES], int, int);
void printVec(float *, int);
void rendimiento(float mat[][MES], int, int, float *, float *);
void promAnualFondos(float mat[][MES], int, int);
void fondoMejorPeorRendimiento(float *, int);

int main() {
    float fondos[FONDOS][MES], precio_fondos[FONDOS], rend_fondos[FONDOS];

    cargaMat(fondos, FONDOS, MES);
    cargaVec(precio_fondos, FONDOS);
    rendimiento(fondos, FONDOS, MES, precio_fondos, rend_fondos);
    promAnualFondos(fondos, FONDOS, MES);
    fondoMejorPeorRendimiento(rend_fondos, FONDOS);

    return 0;
}
void cargaMat(float mat[][MES], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Fondo %d | Mes %d | Valor: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }
}
void cargaVec(float *vec, int size) {
    for(int i = 0; i < size; i++) {
        printf("Fondo %d | Precio al 31/12/2004: ", i + 1);
        scanf("%f", &vec[i]);
    }
}
void printMat(float mat[][MES], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Mes %d | Fondo %d | Precio %.2f\n", j + 1, i + 1, mat[i][j]);
        }
    }
}
void printVec(float *vec, int size) {
    for(int i = 0; i < size; i++) {
        printf("Accion %d | Precio: %.2f\n", i + 1, vec[i]);
    }
}
void rendimiento(float mat[][MES], int f, int c, float *pre, float *rend) {
    for(int i = 0; i < f; i++) {
        rend[i] = (mat[i][c - 1] - pre[i]) / pre[i] * 100;
        printf("Fondo %d | Rendimiento %.2f\n", i + 1, rend[i]);
    }
}
void promAnualFondos(float mat[][MES], int f, int c) {
    for(int i = 0; i < f; i++) {
        float sum_fondos = 0;
        for(int j = 0; j < c; j++) {
            sum_fondos += mat[i][j];
        }
        sum_fondos /= c;
        printf("Fondo %d | Promedio anual: %.2f\n", i + 1, sum_fondos);
    }
}
void fondoMejorPeorRendimiento(float *vec, int size) {
    int ind_mejor, ind_peor;
    float fmejor = vec[0], fpeor = vec[0];
    for(int i = 0; i < size; i++) {
        if(vec[i] > fmejor) {
            fmejor = vec[i];
            ind_mejor = i;
        }
        if(vec[i] < fpeor) {
            fpeor = vec[i];
            ind_peor = i;
        }
    }
    printf("El fondo %d tuvo mejor rendimiento con %.2f\n", ind_mejor + 1, fmejor);
    printf("El fondo %d tuvo el peor rendimiento con %.2f\n", ind_peor + 1, fpeor);
}