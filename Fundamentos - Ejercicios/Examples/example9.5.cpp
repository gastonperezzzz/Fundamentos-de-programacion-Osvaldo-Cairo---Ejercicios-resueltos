#include <stdio.h>

int main() {
    int i, j, num_students, mat;
    FILE *file;
    float calif;

    do {
        printf("Ingrese el numero de estudiantes: ");
        scanf("%d", &num_students);
    } while(num_students < 1 || num_students > 35);

    if((file = fopen("arc8.txt", "w")) == NULL) {
        printf("Error: no se ha podido abrir el archivo.\n");
    }
    else {
        fprintf(file, "%d\n", num_students);
        for(i = 0; i < num_students; i++) {
            printf("Ingrese la matricula del alumno [%d]: ", i + 1);
            scanf("%d", &mat);
            fprintf(file, "%d\n", mat);
            for(j = 0; j < 5; j++) {
                printf("Calificacion %d: ", j + 1);
                scanf("%f", &calif);
                fprintf(file, "%.2f ", calif);
            }
        }
        fclose(file);
    }

    return 0;
}