#include <stdio.h>

#define DPTO 5
#define MES 3

void cargaMat(float mat[][MES], int, int);
void printMat(float mat[][MES], int, int);
void ventasMensualesAnual(float mat[][MES], int, int);
void dptoMayorVentaMes(float mat[][MES], int, int);
void mayorMenorVentaMesDptoTres(float mat[][MES], int);

int main() {
    float ven[DPTO][MES];
    int mes_select;

    cargaMat(ven, DPTO, MES);
    ventasMensualesAnual(ven, DPTO, MES);

    do {
        printf("Ingrese el mes del cual desea saber la mayor venta: ");
        scanf("%d", &mes_select);
    } while(mes_select < 1 || mes_select > MES);

    dptoMayorVentaMes(ven, DPTO, mes_select);
    mayorMenorVentaMesDptoTres(ven, MES);

    return 0;
}

void cargaMat(float mat[][MES], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Departamento %d | Mes %d | Ventas: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }
}
void printMat(float mat[][MES], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            printf("Departamento %d | Mes %d | Ventas: %.2f\n", i + 1, j + 1, mat[i][j]);
        }
    }
}
void ventasMensualesAnual(float mat[][MES], int f, int c) {
    float monto_anual_ventas = 0;
    for(int i = 0; i < f; i++) {
        float monto_mensual_ventas = 0;
        for(int j = 0; j < c; j++) {
            monto_mensual_ventas += mat[i][j];
        }
        monto_anual_ventas += monto_mensual_ventas;
        printf("Departamento %d | Monto mensual total de ventas: %.2f\n", i + 1, monto_mensual_ventas);
    }
    printf("Monto anual de ventas: %.2f\n", monto_anual_ventas);
}
void dptoMayorVentaMes(float mat[][MES], int f, int month) {
    month--;
    float monto_mayor_venta = mat[0][month];
    int indice_monto_mayor_venta; // indice, departamento.
    for(int i = 0; i < f; i++) {
        if(mat[i][month] > monto_mayor_venta) {
            monto_mayor_venta = mat[i][month];
            indice_monto_mayor_venta = i;
        }
    }
    printf("El departamento %d tuvo la mayor venta en el mes %d | Monto %.2f\n", indice_monto_mayor_venta + 1, month + 1, monto_mayor_venta);
}
void mayorMenorVentaMesDptoTres(float mat[][MES], int c) {
    float mayor_venta = mat[2][0], menor_venta = 1000;
    int ind_mayor_venta, ind_menor_venta;
    for(int j = 0; j < c; j++) {
        if(mat[2][j] > mayor_venta) {
            mayor_venta = mat[2][j];
            ind_mayor_venta = j;
        }
        if(mat[2][j] < menor_venta) {
            menor_venta = mat[2][j];
            ind_menor_venta = j;
        }
    }
    printf("El departamento 3 obtuvo su mayor venta en el mes %d\n", ind_mayor_venta + 1);
    printf("El departamento 3 obtuvo su menor venta en el mes %d\n", ind_menor_venta + 1);
}