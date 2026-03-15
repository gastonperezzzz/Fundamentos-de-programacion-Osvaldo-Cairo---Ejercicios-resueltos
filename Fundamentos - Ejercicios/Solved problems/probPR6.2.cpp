#include <stdio.h>

#define MAX 10
#define EXA 4

void cargaMat(float mat[][EXA], int);
void promAlumnoIndividual(float mat[][EXA], int);
void promGrupoExamenes(float mat[][EXA], int);

int main() {
    float alumnos[MAX][EXA];
    int cantidad_alumnos;

    do {
        printf("Ingrese la cantidad de alumnos: ");
        scanf("%d", &cantidad_alumnos);
    } while(cantidad_alumnos < 1 || cantidad_alumnos > MAX);

    cargaMat(alumnos, cantidad_alumnos);
    promAlumnoIndividual(alumnos, cantidad_alumnos);
    promGrupoExamenes(alumnos, cantidad_alumnos);

    return 0;
}

void cargaMat(float mat[][EXA], int f) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < EXA; j++) {
            printf("Alumno [%d] | Examen [%d] | Nota: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }
}
void promAlumnoIndividual(float mat[][EXA], int f) {
    int i, j;
    float prom_alumnos[f] = {0};
    for(i = 0; i < f; i++) {
        for(j = 0; j < EXA; j++) {
            prom_alumnos[i] += mat[i][j];
        }
        prom_alumnos[i] /= f;
    }
    for(i = 0; i < f; i++) {
        printf("Alumno [%d] | Promedio: %.2f\n", i + 1, prom_alumnos[i]);
    }
}
void promGrupoExamenes(float mat[][EXA], int f) {
    int i, j, mej_examen_ind;
    float examen_mejor_prom = 0;
    for(i = 0; i < EXA; i++) {
        float sum_notas_examenes = 0;
        for(j = 0; j < f; j++) {
            sum_notas_examenes += mat[j][i];
        }
        sum_notas_examenes /= EXA;
        if(examen_mejor_prom < sum_notas_examenes) {
            examen_mejor_prom = sum_notas_examenes;
            mej_examen_ind = i;
        }
        printf("Examen [%d] | Promedio de todo el grupo: %.2f\n", i + 1, sum_notas_examenes);
    }
    printf("Examen [%d] cuenta con el mejor promedio: %.2f\n", mej_examen_ind + 1, examen_mejor_prom);
}