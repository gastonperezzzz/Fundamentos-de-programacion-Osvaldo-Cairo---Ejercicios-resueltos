#include <stdio.h>

#define PROV 3
#define MES 3
#define YEARS 3

void cargaArrTridim(float arr[][MES][YEARS], int, int, int);
void provMayorRegPluvial(float arr[][MES][YEARS], int, int, int);
void provRegMenorLastYear(float arr[][MES][YEARS], int, int, int);
void regMensualMayorProv18(float arr[][MES][YEARS], int);

int main() {
    float lluvias[PROV][MES][YEARS];

    cargaArrTridim(lluvias, PROV, MES, YEARS);
    provMayorRegPluvial(lluvias, PROV, MES, YEARS);
    provRegMenorLastYear(lluvias, PROV, MES, YEARS);
    regMensualMayorProv18(lluvias, MES);

    return 0;
}

void cargaArrTridim(float arr[][MES][YEARS], int f, int c, int p) {
    for(int k = 0; k < p; k++) {
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < c; j++) {
                printf("Año %d | Provincia %d | Mes %d | Registro de lluvia: ", k + 1, i + 1, j + 1);
                scanf("%f", &arr[i][j][k]);
            }
        }
    }
}
void provMayorRegPluvial(float arr[][MES][YEARS], int f, int c, int p) {
    int indice_prov_registro_mayor;
    float prov_registro_mayor = 0;
    for(int k = 0; k < p; k++) {
        float sum_reg = 0;
        for(int i = 0; i < f; i++) {
            for(int j = 0; j < p; j++) {
                sum_reg += arr[i][j][k];
            }
            sum_reg /= c;
            if(sum_reg > prov_registro_mayor) {
                prov_registro_mayor = sum_reg;
                indice_prov_registro_mayor = i;
            }
        }
    }
    printf("Provincia %d cuenta con el mayor registro pluvial: %.2f\n", indice_prov_registro_mayor + 1, prov_registro_mayor);
}
void provRegMenorLastYear(float arr[][MES][YEARS], int f, int c, int p) {
    int indice_prov_regmenor;
    float prov_regmenor = arr[0][0][p - 1];
    for(int i = 0; i < f; i++) {
        float sum_reg_mensual = 0;
        for(int j = 0; j < c; j++) {
            sum_reg_mensual += arr[i][j][p - 1];
        }
        sum_reg_mensual /= c;
        if(sum_reg_mensual < prov_regmenor) {
            prov_regmenor = sum_reg_mensual;
            indice_prov_regmenor = i;
        }
    }
    printf("La provincia %d tuvo el menor registro de lluvias el ultimo año: %.2f\n", indice_prov_regmenor + 1, prov_regmenor);
}
void regMensualMayorProv18(float arr[][MES][YEARS], int c) {
    int ind_mes;
    float reg_mes_mayor = arr[1][0][1];
    for(int j = 0; j < c; j++) {
        if(arr[1][j][1] > reg_mes_mayor) {
            reg_mes_mayor = arr[1][j][1];
            ind_mes = j;
        }
    }
    printf("Provincia 2 | Año 2 | Mes %d\n", ind_mes + 1);
}