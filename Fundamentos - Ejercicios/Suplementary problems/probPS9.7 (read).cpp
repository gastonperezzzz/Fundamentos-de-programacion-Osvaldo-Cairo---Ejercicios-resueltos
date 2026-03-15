#include <stdio.h>
#include <string.h>

const int max_chars = 50;

typedef struct {
    int matricula;
    char nom_ap[max_chars];
    int carrera;
    float promedio;
} alumno;

void deleteNewLine(char *);
int compAlumnos(alumno, alumno);
void mostrarAlumno(alumno);

int main() {
    FILE *apuntador_lectura, *apuntador_escritura;
    int i, j, k, cont_alumnos = 0;
    alumno estudiante;

    apuntador_lectura = fopen("probPS9.7.dat", "r+");
    apuntador_escritura = fopen("probPS9.7 (ex).dat", "w+");

    while(!(feof(apuntador_lectura))) {
        cont_alumnos++;
        fread(&estudiante, sizeof(alumno), 1, apuntador_lectura);
    }

    cont_alumnos--;
    int size_rl = cont_alumnos;
    alumno alumnos_rl[size_rl];

    rewind(apuntador_lectura);

    for(i = 0; i < cont_alumnos; i++) {
        fread(&estudiante, sizeof(alumno), 1, apuntador_lectura);
        alumnos_rl[i] = estudiante;
    }

    for(i = 0; i < cont_alumnos; i++) {
        for(j = i + 1; j < cont_alumnos; j++) {
            if(compAlumnos(alumnos_rl[i], alumnos_rl[j])) {
                for(k = j; k < size_rl; k++) {
                    alumnos_rl[k] = alumnos_rl[k + 1];
                    size_rl--;
                }
            }
        }
    }

    for(i = 0; i < size_rl; i++) {
        fwrite(&alumnos_rl[i], sizeof(alumno), 1, apuntador_escritura);
    }
    rewind(apuntador_escritura);
    for(i = 0; i < size_rl; i++) {
        fread(&estudiante, sizeof(alumno), 1, apuntador_escritura);
        mostrarAlumno(estudiante);
    }

    fclose(apuntador_escritura);
    fclose(apuntador_lectura);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
int compAlumnos(alumno al1, alumno al2) {
    if(al1.matricula == al2.matricula) {
        if(!strcmp(al1.nom_ap, al2.nom_ap)) {
            if(al1.carrera == al2.carrera) {
                if(al1.promedio == al2.promedio) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void mostrarAlumno(alumno var) {
    printf("Matricula: %d\n", var.matricula);
    printf("Nombre: %s\n", var.nom_ap);
    printf("Carrera: %d\n", var.carrera);
    printf("Promedio: %.2f\n", var.promedio);
    printf("\n");
}