#include <stdio.h>
#include <string.h>

const int cantidad_examenes = 5;

typedef struct {
    int matricula;
    char nom_ap[50];
    float calificaciones[cantidad_examenes];
} alumno;

void delNewLine(char *);
void lecturaAlumno(alumno *, int);
void funcion_uno(alumno *, int);
void funcion_dos(alumno *, int);
void funcion_tres(alumno *, int);

int main() {
    int cantidad_alumnos;

    do {
        printf("Ingrese la cantidad de alumnos: ");
        scanf("%d", &cantidad_alumnos);
        if(cantidad_alumnos > 100 || cantidad_alumnos < 1) {
            printf("Error: cantidad de alumnos invalida.\n");
        }
    } while(cantidad_alumnos > 100 || cantidad_alumnos < 1);

    alumno arre[cantidad_alumnos];

    lecturaAlumno(arre, cantidad_alumnos);
    funcion_uno(arre, cantidad_alumnos);
    funcion_dos(arre, cantidad_alumnos);
    funcion_tres(arre, cantidad_alumnos);

    return 0;
}

void delNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaAlumno(alumno *var, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        printf("Ingrese la matricula del alumno [%d]: ", i + 1);
        scanf("%d", &var[i].matricula);
        getchar();

        printf("Ingrese el nombre y apellido del alumno [%d]: ", i + 1);
        fgets(var[i].nom_ap, sizeof(var[i].nom_ap), stdin);
        delNewLine(var[i].nom_ap);

        for(j = 0; j < cantidad_examenes; j++) {
            printf("Ingrese la calificacion %d del alumno %d: ", j + 1, i + 1);
            scanf("%f", &var[i].calificaciones[j]);
            getchar();
        }
        puts("");
    }
}
void funcion_uno(alumno *var, int size) {
    int i, j;
    float sumatoria, promedio;
    for(i = 0; i < size; i++) {
        promedio = 0.0;
        sumatoria = 0.0;
        for(j = 0; j < cantidad_examenes; j++) {
            sumatoria += var[i].calificaciones[j];
        }
        promedio = sumatoria / cantidad_examenes;
        printf("\nMatricula: %d \t Promedio: %f\n", var[i].matricula, promedio);
    }
}
void funcion_dos(alumno *var, int size) {
    int i;
    printf("Matriculas de alumnos con nota mayor a nueve en la tercera materia:\n");
    for(i = 0; i < size; i++) {
        if(var[i].calificaciones[2] > 9) {
            printf("Matricula: %d\n", var[i].matricula);
        }
    }
}
void funcion_tres(alumno *var, int size) {
    int i;
    float prom = 0.0;
    for(i = 0; i < size; i++) {
        prom += var[i].calificaciones[3];
    }
    printf("Materia 4 | Promedio General: %.2f\n", prom);
}