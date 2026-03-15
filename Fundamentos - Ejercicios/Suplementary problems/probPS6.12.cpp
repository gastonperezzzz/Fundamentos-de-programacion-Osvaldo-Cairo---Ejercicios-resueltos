#include <stdio.h>

#define EST 2
#define MES 2
#define YEAR 2

void regAsistentes(int tridim[][MES][YEAR], int, int, int);
void numAsistOrdenadosEstadiosLastYear(int tridim[][MES][YEAR], int, int, int);
void estadiosMayorMenorAfluencia(int tridim[][MES][YEAR], int *, int, int, int);
void mesLastYearMayorAfluenciaEstadios(int tridim[][MES][YEAR], int, int, int);

int main() {
    int fut[EST][MES][YEAR], num_asist[EST] = {0};

    regAsistentes(fut, EST, MES, YEAR);
    numAsistOrdenadosEstadiosLastYear(fut, EST, MES, YEAR);
    estadiosMayorMenorAfluencia(fut, num_asist, EST, MES, YEAR);
    mesLastYearMayorAfluenciaEstadios(fut, EST, MES, YEAR);

    return 0;
}

void regAsistentes(int tridim[][MES][YEAR], int est, int mes, int year) {
    int i, j, k;
    for(k = 0; k < year; k++) {
        for(i = 0; i < est; i++) {
            for(j = 0; j < mes; j++) {
                printf("Año %d | Mes %d | Estadio %d | Asistentes: ", k + 1, j + 1, i + 1);
                scanf("%d", &tridim[i][j][k]);
            }
        }
        printf("---------------------------\n");
    }
}
void numAsistOrdenadosEstadiosLastYear(int tridim[][MES][YEAR], int est, int mes, int year) {
    int i, j;
    int asist[est] = {0}, asist_ind[est];
    for(i = 0; i < est; i++) {
        for(j = 0; j < mes; j++) {
            asist[i] += tridim[i][j][year - 1];
        }
        asist_ind[i] = i;
    }
    
    int aux = 0, aux_ind = 0;
    for(i = 0; i < (est - 1); i++) {
        for(j = (i + 1); j < est; j++) {
            if(asist[i] < asist[j]) {
                aux = asist[i];
                asist[i] = asist[j];
                asist[j] = aux;
                // intercambio de indices
                aux_ind = asist_ind[i];
                asist_ind[i] = asist_ind[j];
                asist_ind[j] = aux_ind;
            }
        }
    }
    for(i = 0; i < est; i++) {
        printf("Estadio %d | Total de visitantes del ultimo año: %d\n", asist_ind[i] + 1, asist[i]);
    }
}
void estadiosMayorMenorAfluencia(int tridim[][MES][YEAR], int *publico, int est, int mes, int year) {
    int i, j, k;
    for(k = 0; k < year; k++) {
        for(i = 0; i < est; i++) {
            for(j = 0; j < mes; j++) {
                publico[i] += tridim[i][j][k];
            }
        }
    }
    int mayoraf = publico[0], menoraf = publico[0];
    int i_mayoraf = 0, i_menoraf = 0;
    for(i = 0; i < est; i++) {
        if(mayoraf < publico[i]) {
            mayoraf = publico[i];
            i_mayoraf = i;
        }
        if(menoraf > publico[i]) {
            menoraf = publico[i];
            i_menoraf = i;
        }
    }
    printf("El estadio con mayor afluencia de publico [%d] | Asistentes: %d\n", i_mayoraf + 1, mayoraf);
    printf("El estadio con menor afluencia de publico [%d] | Asistentes: %d\n", i_menoraf + 1, menoraf);
}
void mesLastYearMayorAfluenciaEstadios(int tridim[][MES][YEAR], int est, int mes, int year) {
    int i, j;
    int mes_mayoraf = tridim[0][0][year - 1], mes_menoraf = 100000;
    int i_mes_mayoraf = 0, i_mes_menoraf = 0;
    for(j = 0; j < mes; j++) {
        int sum_mes = 0;
        for(i = 0; i < est; i++) {
            sum_mes += tridim[i][j][year - 1];
        }
        if(mes_mayoraf < sum_mes) {
            mes_mayoraf = sum_mes;
            i_mes_mayoraf = j;
        }
        if(mes_menoraf > sum_mes) {
            mes_menoraf = sum_mes;
            i_mes_menoraf = j;
        }
    }
    printf("Mes de mayor afluencia del ultimo año: %d | Asistentes: %d\n", i_mes_mayoraf + 1, mes_mayoraf);
    printf("Mes de menor afluencia del ultimo año: %d | Asistentes: %d\n", i_mes_menoraf + 1, mes_menoraf);
}