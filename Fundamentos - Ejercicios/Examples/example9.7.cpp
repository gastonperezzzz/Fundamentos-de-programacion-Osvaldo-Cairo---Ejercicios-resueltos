#include <stdio.h>

void promedioArchivo(FILE *);

int main() {
    FILE *archive;
    if((archive = fopen("arc8.txt", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        promedioArchivo(archive);
        fclose(archive);
    }

    return 0;
}

void promedioArchivo(FILE *ar) {
    int i, j, mat, num_students;
    float prom, calif;
    fscanf(ar, "%d", &num_students);
        for(i = 0; i < num_students; i++) {
            prom = 0.0;
            fscanf(ar, "%d", &mat);
            printf("%d\n", mat);
            for(j = 0; j < 5; j++) {
                fscanf(ar, "%f", &calif);
                printf("%.2f ", calif);
                prom += calif;
            }
            printf("Promedio: %.2f\n", prom / 5);
        }
}