#include <stdio.h>

int main() {
    unsigned int mat, car, sem;
    float prom;

    printf("Ingrese la carrera del alumno: \n1) Industrial \n2) Telematica \n3) Computacion: \n4) Mecanica\n");
    printf("Carrera [1/2/3/4]: ");
    scanf("%d", &car);

    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &mat);

    printf("Ingrese el semestre del alumno: ");
    scanf("%d", &sem);

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &prom);

    printf("\n");

    switch (car) {
        case 1: if (sem >= 6 && prom >= 8.5) {
            printf("El alumno puede ser asistente en Industrial");
            }
            break;
        case 2: if (sem >= 5 && prom >= 9.0) {
            printf("El alumno puede ser asistente en Telematica");
            }
            break;
        case 3: if (sem >= 6 && prom >= 8.8) {
            printf("El alumno puede ser asistente en Computacion");
            }
            break;
        case 4: if (sem >= 7 && prom >= 7.0) {
            printf("El alumno puede ser asistente en Mecanica");
        }
            break;
        default: printf("Error en al seleccionar la carrera.");
        break;
    }
}