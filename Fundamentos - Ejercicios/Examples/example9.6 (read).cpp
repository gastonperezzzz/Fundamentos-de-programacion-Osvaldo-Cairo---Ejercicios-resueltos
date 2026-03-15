#include <stdio.h>

int main(void) {
    int i, j, mat, num_students;
    float prom, calif;
    FILE *archive;

    if((archive = fopen("arc8.txt", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        fscanf(archive, "%d", &num_students);
        for(i = 0; i < num_students; i++) {
            prom = 0.0;
            fscanf(archive, "%d", &mat);
            printf("%d\n", mat);
            for(j = 0; j < 5; j++) {
                fscanf(archive, "%f", &calif);
                printf("%.2f ", calif);
                prom += calif;
            }
            printf("Promedio: %.2f\n", prom / 5);
        }
        fclose(archive);
    }

    return 0;
}