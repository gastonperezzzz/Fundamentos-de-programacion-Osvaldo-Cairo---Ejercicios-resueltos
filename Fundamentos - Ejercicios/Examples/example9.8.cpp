#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nom_ap[50];
    int carrera;
    float promedio;
} alumno;

void deleteNewLine(char *);
void escribir(FILE *);

int main() {
    FILE *archive;

    if((archive = fopen("ad1.dat", "w")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        escribir(archive);
        fclose(archive);
    }

    return 0;
}
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void escribir(FILE *file) {
    alumno estudiante;
    int i = 0, option;

    do {
        printf("Desea ingresar informacion sobre un alumno? \n0. No \n1. Si \nOpcion: ");
        scanf("%d", &option);
        if(option != 0 && option != 1) {
            printf("Error: opcion invalida.\n");
        }
    } while(option != 0 && option != 1);

    while(option) {
        i++;

        printf("Alumno [%d] | Matricula: ", i);
        scanf("%d", &estudiante.matricula);
        getchar();

        printf("Alumno [%d] | Nombre y apellido: ", i);
        fgets(estudiante.nom_ap, 50, stdin);
        deleteNewLine(estudiante.nom_ap);

        do {
            printf("Alumno [%d] | Carrera [1 - 5]: ", i);
            scanf("%d", &estudiante.carrera);
            getchar();
        } while(estudiante.carrera < 1 || estudiante.carrera > 5);

        printf("Alumno [%d] | Promedio: ", i);
        scanf("%f", &estudiante.promedio);
        getchar();

        fwrite(&estudiante, sizeof(alumno), 1, file);

        do {
            printf("Desea ingresar informacion sobre un alumno? \n0. No \n1. Si \nOpcion: ");
            scanf("%d", &option);
            if(option != 0 && option != 1) {
                printf("Error: opcion invalida.\n");
            }
        } while(option != 0 && option != 1);
    }
}