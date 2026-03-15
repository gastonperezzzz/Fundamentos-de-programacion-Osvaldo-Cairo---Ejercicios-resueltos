#include <stdio.h>

int main() {
    int i, j, num_students, mat;
    float prom, calif;
    FILE *archive;

    if((archive = fopen("arc9.txt", "w")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        do {
            printf("Ingrese el numero de estudiantes: ");
            scanf("%d", &num_students);
            getchar();
        } while(num_students < 1 || num_students > 35);
        fprintf(archive, "Numero de estudiantes: %d\n", num_students);
        for(i = 0; i < num_students; i++) {
            prom = 0.0;
            printf("Alumno [%d] | Matricula: ", i + 1);
            scanf("%d", &mat);
            getchar();
            fprintf(archive, "%d | ", mat);
            for(j = 0; j < 5; j++) {
                printf("Alumno [%d] | Calificacion [%d]: ", i + 1, j + 1);
                scanf("%f", &calif);
                getchar();
                fprintf(archive, "%.2f | ", calif);
                prom += calif;
            }
            fprintf(archive, "Promedio: %.2f\n", prom / 5);
        }
        fclose(archive);
    }

    return 0;
}