#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int max_chars = 40;
const int n_materias = 2;

// Declaracion de estructuras.
typedef struct {
    char materia[max_chars];
    float promedio;
} calificaciones;

typedef struct {
    char nivel[max_chars];
    int grado;
    char salon[max_chars];
    calificaciones notas[n_materias];
} nivel_estudios;

typedef struct {
    char calle_num[max_chars];
    char cod_postal[max_chars];
    char colonia[max_chars];
    char ciudad[max_chars];
    char telefono[max_chars];
} domicilio;

typedef struct {
    int matricula;
    char nom_ap[max_chars];
    domicilio vivienda;
    nivel_estudios educacion;
} alumno;

// Prototipos de funciones.
void deleteNewLine(char *); // Hecho
void lecturaAlumnos(alumno *, int); // Hecho
int verifExistenciaMatricula(alumno *, int, int); // Hecho
void alumnoPromedioGeneralPorMatricula(alumno *, int); // Hecho
void alumnosPorNivelDeEstudios(alumno *, int); // Hecho
void promedioMayorPorNivelDeEstudios(alumno *, int); // Hecho

// Programa principal.
int main() {
    int cantidad_alumnos;
    unsigned int option;

    do {
        printf("Ingrese la cantidad de alumnos que tiene la escuela: ");
        scanf("%d", &cantidad_alumnos);
        getchar();
        if(cantidad_alumnos < 1 || cantidad_alumnos > 100) {
            printf("Error: cantidad invalida.\n");
        }
    } while(cantidad_alumnos < 1 || cantidad_alumnos > 100);

    alumno escuela[cantidad_alumnos];

    lecturaAlumnos(escuela, cantidad_alumnos);

    do {
        do {
            printf("1. Calcular promedio general por matricula. \n2. Lista de alumnos segun nivel de estudios, grado y salon. \n3. Alumno de mayor promedio segun nivel de estudios, grado y salon. \n4. Salir. \n");
            printf("Opcion: ");
            scanf("%d", &option);
            getchar();
            if(option < 1 || option > 4) {
                printf("Error: opcion invalida.\n");
            }
        } while(option < 1 || option > 4);
        switch(option) {
            case 1:
                alumnoPromedioGeneralPorMatricula(escuela, cantidad_alumnos);
                break;
            case 2:
                alumnosPorNivelDeEstudios(escuela, cantidad_alumnos);
                break;
            case 3:
                promedioMayorPorNivelDeEstudios(escuela, cantidad_alumnos);
                break;
        }
    } while(option != 4);

    return 0;
}

// Definiciones de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaAlumnos(alumno *var, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        printf("Alumno [%d] | Matricula: ", i + 1);
        scanf("%d", &var[i].matricula);
        getchar();

        printf("Alumno [%d] | Nombre y apellido: ", i + 1);
        fgets(var[i].nom_ap, max_chars, stdin);
        deleteNewLine(var[i].nom_ap);

        printf("Domicilio: \n");
        printf("\tAlumno [%d] | Calle y numero: ", i + 1);
        fgets(var[i].vivienda.calle_num, max_chars, stdin);
        deleteNewLine(var[i].vivienda.calle_num);
    
        printf("\tAlumno [%d] | Codigo postal: ", i + 1);
        fgets(var[i].vivienda.cod_postal, max_chars, stdin);
        deleteNewLine(var[i].vivienda.cod_postal);

        printf("\tAlumno [%d] | Colonia: ", i + 1);
        fgets(var[i].vivienda.colonia, max_chars, stdin);
        deleteNewLine(var[i].vivienda.colonia);

        printf("\tAlumno [%d] | Ciudad: ", i + 1);
        fgets(var[i].vivienda.ciudad, max_chars, stdin);
        deleteNewLine(var[i].vivienda.ciudad);

        printf("\tAlumno [%d] | Telefono: ", i + 1);
        fgets(var[i].vivienda.telefono, max_chars, stdin);
        deleteNewLine(var[i].vivienda.telefono);

        printf("Nivel de estudios: \n");
        printf("\tAlumno [%d] | Nivel: ", i + 1);
        fgets(var[i].educacion.nivel, max_chars, stdin);
        deleteNewLine(var[i].educacion.nivel);
    
        printf("\tAlumno [%d] | Grado: ", i + 1);
        scanf("%d", &var[i].educacion.grado);
        getchar();
    
        printf("\tAlumno [%d] | Salon: ", i + 1);
        fgets(var[i].educacion.salon, max_chars, stdin);
        deleteNewLine(var[i].educacion.salon);

        printf("\tCalificaciones: \n");
        for(j = 0; j < n_materias; j++) {
            printf("\t\t\tAlumno [%d] | Nombre de la materia [%d]: ", i + 1, j + 1);
            fgets(var[i].educacion.notas[j].materia, max_chars, stdin);
            deleteNewLine(var[i].educacion.notas[j].materia);

            printf("\t\t\tAlumno [%d] | Promedio [%d]: ", i + 1, j + 1);
            scanf("%f", &var[i].educacion.notas[j].promedio);
            getchar();
        }
    }
    printf("\n");
}
int verifExistenciaMatricula(alumno *var, int size, int mat) {
    int i;
    for(i = 0; i < size; i++) {
        if(mat == var[i].matricula) {
            return i;
        }
    }
    return (- 1);
}
void alumnoPromedioGeneralPorMatricula(alumno * var, int size) {
    int i, j, i_matricula;
    int matricula;
    float promedio = 0.0;
    printf("Matricula | Nombre y apellido: \n");
    for(i = 0; i < size; i++) {
        printf("%d | %s\n", var[i].matricula, var[i].nom_ap);
    }
    do {
        printf("Ingrese la matricula de un alumno para calcular su promedio general: ");
        scanf("%d", &matricula);
        getchar();
        i_matricula = verifExistenciaMatricula(var, size, matricula);
        if(i_matricula == - 1) {
            printf("Error: matricula inexistente.\n");
        } 
    } while(i_matricula == - 1);
    for(j = 0; j < n_materias; j++) {
        promedio += var[i_matricula].educacion.notas[j].promedio;
    }
    printf("%d | %s | Promedio general: %.2f\n", var[i_matricula].matricula, var[i_matricula].nom_ap, promedio / n_materias);
}
void alumnosPorNivelDeEstudios(alumno *var, int size) {
    int i, j;
    char nivel[max_chars], salon[max_chars];
    int grado;
    float promedio = 0.0;
    printf("Mostrar alumnos segun: nivel de estudios, grado, salon.\n");
        
    printf("Ingrese el nivel de estudios [Primaria/Secundaria/Preparatoria]: ");
    fgets(nivel, max_chars, stdin);
    deleteNewLine(nivel);

    if(islower(nivel[0])) {
        nivel[0] = toupper(nivel[0]);
    }

    printf("Ingrese el grado: ");
    scanf("%d", &grado);
    getchar();

    printf("Ingrese el salon: ");
    fgets(salon, max_chars, stdin);
    deleteNewLine(salon);

    for(i = 0; i < size; i++) {
        promedio = 0.0;
        for(j = 0; j < n_materias; j++) {
            promedio += var[i].educacion.notas[j].promedio;
        }
        if(!(strcmp(var[i].educacion.nivel, nivel)) && var[i].educacion.grado == grado && !(strcmp(var[i].educacion.salon, salon))) {
            printf("%d | %s | %.2f \n", var[i].matricula, var[i].nom_ap, promedio / n_materias);
        }
    }
}
void promedioMayorPorNivelDeEstudios(alumno *var, int size) {
    int i, j, i_alumno;
    char nivel[max_chars], salon[max_chars];
    int grado;
    float promedio = 0.0, mayor_promedio = 0.0;
    printf("Alumno con mayor promedio segun: nivel de estudios, grado y salon.\n");
        
    printf("Ingrese el nivel de estudios [Primaria/Secundaria/Preparatoria]: ");
    fgets(nivel, max_chars, stdin);
    deleteNewLine(nivel);

    if(islower(nivel[0])) {
        nivel[0] = toupper(nivel[0]);
    }

    printf("Ingrese el grado: ");
    scanf("%d", &grado);
    getchar();

    printf("Ingrese el salon: ");
    fgets(salon, max_chars, stdin);
    deleteNewLine(salon);

    for(i = 0; i < size; i++) {
        promedio = 0.0;
        if(!(strcmp(var[i].educacion.nivel, nivel)) && var[i].educacion.grado == grado && !(strcmp(var[i].educacion.salon, salon))) {
            for(j = 0; j < n_materias; j++) {
                promedio += var[i].educacion.notas[j].promedio;
            }
            promedio = promedio / n_materias;
            if(promedio > mayor_promedio) {
                mayor_promedio = promedio;
                i_alumno = i;
            }
        }
    }
    printf("El alumno con mayor promedio es: %d, %s, con %.2f\n", var[i_alumno].matricula, var[i_alumno].nom_ap, mayor_promedio);
}