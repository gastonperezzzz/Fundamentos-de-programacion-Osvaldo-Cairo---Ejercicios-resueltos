#include <stdio.h>
#include <iostream>

#define CEN 3
#define MES 2
#define YEAR 2

void RegistroVisitantes(int arr[][MES][YEAR], int, int, int);
void printRegistro(int arr[][MES][YEAR], int, int, int);
void totalVisitantesCentros(int arr[][MES][YEAR], int *, int, int, int);
void centroMasVistadoMenosVisitado(int *, int);
void AfluenciaTuristicaMesLastYear(int arr[][MES][YEAR], int, int, int);

int main() {
    int sec[CEN][MES][YEAR], centros[CEN] = {0};

    RegistroVisitantes(sec, CEN, MES, YEAR);
    totalVisitantesCentros(sec, centros, CEN, MES, YEAR);
    centroMasVistadoMenosVisitado(centros, CEN);
    AfluenciaTuristicaMesLastYear(sec, CEN, MES, YEAR);

    return 0;
}

void RegistroVisitantes(int arr[][MES][YEAR], int cen, int mes, int year) {
    int i, j, k;
    for(k = 0; k < year; k++) {
        for(i = 0; i < cen; i++) {
            for(j = 0; j < mes; j++) {
                printf("Año %d | Mes %d | Centro %d | Visitantes: ", k + 1, j + 1, i + 1);
                scanf("%d", &arr[i][j][k]);
            }
        }
        printf("-----------------------\n");
    }
}
void printRegistro(int arr[][MES][YEAR], int cen, int mes, int year) {
    int i, j, k;
    for(k = 0; k < year; k++) {
        for(i = 0; i < cen; i++) {
            for(j = 0; j < mes; j++) {
                printf("Año %d | Mes %d | Centro %d | Visitantes: %d", k + 1, j + 1, i + 1, arr[i][j][k]);
            }
        }
    }
}
void totalVisitantesCentros(int arr[][MES][YEAR], int *arrcen, int cen, int mes, int year) {
    int i, j, k;
    for(i = 0; i < cen; i++) {
        for(k = 0; k < year; k++) {
            for(j = 0; j < mes; j++) {
                arrcen[i] += arr[i][j][k];
            }
        }
        printf("Centro %d | Total de visitantes: %d\n", i + 1, arrcen[i]);
    }
}
void centroMasVistadoMenosVisitado(int *arrcen, int cen) {
    int i, ind_cen_mas_visitado = 0, ind_cen_menos_visitado = 0;
    int cen_mas_visitado = arrcen[0], cen_menos_visitado = arrcen[0];
    for(i = 1; i < cen; i++) {
        if(arrcen[i] > cen_mas_visitado) {
            cen_mas_visitado = arrcen[i];
            ind_cen_mas_visitado = i;
        }
        if(arrcen[i] < cen_menos_visitado) {
            cen_menos_visitado = arrcen[i];
            ind_cen_menos_visitado = i;
        }
    }
    printf("El centro %d es el mas visitado | Visitantes: %d\n", ind_cen_mas_visitado + 1, arrcen[ind_cen_mas_visitado]);
    printf("El centro %d es el menos visitado | Visitantes: %d\n", ind_cen_menos_visitado + 1, arrcen[ind_cen_menos_visitado]);
}
void AfluenciaTuristicaMesLastYear(int arr[][MES][YEAR], int cen, int mes, int year) {
    int i, j;
    int mes_mayor_afluencia = 0, mes_menor_afluencia = 10000;
    int ind_mayor_afluencia = 0, ind_menor_afluencia = 0;
    for(j = 0; j < mes; j++) {
        int sum_meses = 0;
        for(i = 0; i < cen; i++) {
            sum_meses += arr[i][j][year - 1];
        }
        if(sum_meses > mes_mayor_afluencia) {
            mes_mayor_afluencia = sum_meses;
            ind_mayor_afluencia = j;
        }
        if(sum_meses < mes_menor_afluencia) {
            mes_menor_afluencia = sum_meses;
            ind_menor_afluencia = j;
        }
    }
    printf("Mes con mayor afluencia: %d | Visitantes: %d\n", ind_mayor_afluencia + 1, mes_mayor_afluencia);
    printf("Mes con menor afluencia: %d | Visitantes: %d\n", ind_menor_afluencia + 1, mes_menor_afluencia);
}