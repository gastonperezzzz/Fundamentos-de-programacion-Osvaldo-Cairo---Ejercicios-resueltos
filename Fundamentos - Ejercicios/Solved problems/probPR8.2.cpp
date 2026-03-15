#include <stdio.h>
#include <string.h>

const int max_chars = 50;
const int materias = 5;

// Declaracion de estructuras.
typedef struct {
    char materia[max_chars];
    float promedio;
} materias_promedios;

typedef struct {
    int matricula;
    char nom_ap[50];
    materias_promedios calificaciones[materias];
} alumno;

// Prototipos de funciones.
void DeleteNewLine(char *);
void lecturaAlumnos(alumno *, int);
void funcion_uno(alumno *, int); // Hecho
void funcion_dos(alumno *, int); // Hecho
void funcion_tres(alumno *, int);

// Programa principal.
int main() {
    unsigned int cantidad_alumnos;

    do {
        printf("Ingrese la cantidad de alumnos: ");
        scanf("%d", &cantidad_alumnos);
        getchar();
        if(cantidad_alumnos < 1 || cantidad_alumnos > 50) {
            printf("Error: cantidad invalida.\n");
        }
    } while(cantidad_alumnos < 1 || cantidad_alumnos > 50);

    alumno alumnado[cantidad_alumnos];

    lecturaAlumnos(alumnado, cantidad_alumnos);

    funcion_uno(alumnado, cantidad_alumnos);
    funcion_dos(alumnado, cantidad_alumnos);
    funcion_tres(alumnado, cantidad_alumnos);

    return 0;
}

// Definicion de funciones.
void DeleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaAlumnos(alumno *var, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        printf("Ingrese los datos del alumno [%d] \n", i + 1);
        printf("Alumno [%d] | Matricula: ", i + 1);
        scanf("%d", &var[i].matricula);
        getchar();

        printf("Alumno [%d] | Nombre y apellido: ", i + 1);
        fgets(var[i].nom_ap, max_chars, stdin);
        DeleteNewLine(var[i].nom_ap);

        printf("Materias y promedios: \n");
        for(j = 0; j < materias; j++) {
            printf("\tAlumno [%d] | Nombre de la materia [%d]: ", i + 1, j + 1);
            fgets(var[i].calificaciones[j].materia, max_chars, stdin);
            DeleteNewLine(var[i].calificaciones[j].materia);

            printf("\tPromedio de la materia [%d]: ", j + 1);
            scanf("%f", &var[i].calificaciones[j].promedio);
            getchar();
        }
    }
    printf("\n");
}
void funcion_uno(alumno *var, int size) {
    int i, j;
    float sum_promedios;
    printf("Alumno \t\tMatriculas \t\tPromedios generales\n");
    for(i = 0; i < size; i++) {
        sum_promedios = 0.0;
        for(j = 0; j < materias; j++) {
            sum_promedios += var[i].calificaciones[j].promedio;
        }
        printf("%d \t\t%d \t\t\t%.2f\n", i + 1, var[i].matricula, sum_promedios / materias);
    }
}
void funcion_dos(alumno *var, int size) {
    int i;
    printf("Matriculas de los alumnos con calificacion mayor a nueve en la tercer materia.\n");
    for(i = 0; i < size; i++) {
        if(var[i].calificaciones[2].promedio > 9) {
            printf("Alumno [%d] | Matricula %d", i + 1, var[i].matricula);
        }
    }
}
void funcion_tres(alumno *var, int size) {
    int i;
    float prom_general = 0.0;
    for(i = 0; i < size; i++) {
        prom_general += var[i].calificaciones[3].promedio;
    }
    printf("El promedio general de la cuarta materia es: %.2f\n", prom_general / size);
}